#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;
//void and other functions
void OverView();



int main()
{
    bool exit = false;
    int play = 1;

    
        //Display Title of the program to the user
        cout << "\n\n\t Welcome to Keywords II recruit\n\n\t" << endl;

        // Ask the recruit to log in using their name
        string name;
        cout << "\n\nPlease log in using your first name\n\n";
        cin >> name;
        // Hold the recruit's name in a var, and address them by it throughout the simulation.
        cout << "\n\nWelcome " << name << " to the Code Breaker II program\n\n";
        // Display an overview of what Keywords II is to the recruit 
        OverView();
        do {
        //the replay statment (for loop)
        for (int j = 1; j <= 3; j++)
        {
            const int MAX_WRONG = 10;  //maximum number of incorrect guesses allowed

            vector<string> words;   // Create a collection of 10 words you had written down manually
            words.push_back("AGENT");
            words.push_back("CIA");
            words.push_back("ASSET");
            words.push_back("SECRET");
            words.push_back("UNDERCOVER");
            words.push_back("GHOST");
            words.push_back("SILENT");
            words.push_back("PHONE");
            words.push_back("HIDDEN");
            words.push_back("MYSTERY");

            srand(static_cast<unsigned int>(time(0)));
            random_shuffle(words.begin(), words.end());

            const string THE_WORD = words[0];           //word to guess

            int wrong = 0;                              //number of incorrect guesses
            string soFar(THE_WORD.size(), '-');         //word guessed so far
            string used = "";                           //letters already guessed

            cout << "Welcome to Code Breaker II. Good luck!\n";
            // Display the simulation # is starting to the recruit. 
            cout << "\n\n-----You are currently on simulation # " << play << "-----\n\n";

            //main loop
            while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
            {
                // While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
                // Tell recruit how many incorrect guesses he or she has left
                cout << "\n\nYou have " << (MAX_WRONG - wrong);
                cout << " incorrect guesses left.\n";
                // Show recruit the letters he or she has guessed
                cout << "\nYou’ve used the following letters:\n" << used << endl;
                // Show player how much of the secret word he or she has guessed
                cout << "\nSo far, the word is:\n" << soFar << endl;

                // Get recruit's next guess
                char guess;
                cout << "\n\nEnter your guess: ";
                cin >> guess;
                guess = toupper(guess); //make uppercase since secret word in uppercase
                // While recruit has entered a letter that he or she has already guessed
                while (used.find(guess) != string::npos)
                {
                    cout << "\nYou’ve already guessed " << guess << endl;

                    // Get recruit ’s guess
                    cout << "Enter your guess: ";
                    cin >> guess;
                    // Add the new guess to the group of used letters
                    guess = toupper(guess);
                }

                used += guess;

                if (THE_WORD.find(guess) != string::npos)
                {
                    // Tell the recruit the guess is correct
                    cout << "That’s right! " << guess << " is in the word.\n";
                    //update soFar to include newly guessed letter
                    for (int i = 0; i < THE_WORD.length(); ++i)
                    {
                        if (THE_WORD[i] == guess)
                        {
                            soFar[i] = guess;
                        }
                    }
                }
                else
                {
                    // Tell the recruit the guess is incorrect
                    cout << "Sorry, " << guess << " isn’t in the word.\n";
                    // Increment the number of incorrect guesses the recruit has made
                    ++wrong;
                }
            }

            //shut down
            // If the recruit has made too many incorrect guesses
            if (wrong == MAX_WRONG)
            {
                // Tell the recruit that he or she has failed the Keywords II course.
                cout << "\nYou’ve been found out!";
            }
            else
            {
                // Congratulate the recruit on guessing the secret words
                cout << "\nYou guessed it!";
            }

            cout << "\nThe word was " << THE_WORD << endl;


        }

        // Ask the recruit if they would like to run the simulation again
        cout << "You have completed the simulation!\n";
        cout << "Would you like to try again? (0 to exit and 1 to continue)";
        cin >> exit;
        //Increment the number of simulations ran counter
        play++;
    } while (exit);

    // Display End of Simulations to the recruit
    cout << "\nThanks for playing.\n";
    // Pause the Simulation with press any key to continue
    system("pause");
    return 0;
}


void OverView()
{
    cout << "\nWelcome to the next step in your training recruit.\n";
    cout << "\nThis will be what you will be training with from here on.\n";
    cout << "\nThis is a more advanced version of the pervious program.\n\n";
    // Display directions to the recruit on how to use Keywords
    cout << " \n\n\t-- This is how you play --\n\n\t";
    cout << "\nInput one letter at a time, and you will slowly fill in the word\n";
    cout << "\nTake your time, and do not rush, you only have 10 guesses before you are found out!";
    cout << "\nYou will have to guess three randomly selected words, good luck!";
}