

#include <iostream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#include <random>
#define tabs "\t\t\t\t\t\t"

using namespace std;

int options(); //main functions
int Exit();
int howtoplay();
int GameStart();
int win();
int lose();
int draw();
int balance = 0;

int main() //where the menu starts
{

	int choice;
	bool running = 1; 
	system("CLS");
	std::cout << tabs << "Welcome to Black Jack" << std::endl;// this is the main menu not much to say just a simple switch statment
	std::cout << tabs << "Main Menu\n" << std::endl;
	balance = balance + 10;

	if(running = 1)
	{
		
		std::cout << tabs << "Type 1 to Start\n" << std::endl;
		std::cout << tabs << "Type 2 for Options\n" << std::endl;
		std::cout << tabs << "Type 3 for How To Play\n" << std::endl;
		std::cout << tabs << "Type 4 to Exit\n" << std::endl;
		

		cin >> choice;

		switch (choice) //switch statment for choices in the menu
		{
		case 1:
			system("CLS");
			std::cout << tabs << "Start Selected\n" << std::endl;
			GameStart();
			running = 0;
			break;
		case 2:
			system("CLS");
			std::cout << tabs << "Options Selected\n" << std::endl;
			running = 0;
			options();
			break;
		case 3:
			system("CLS");
			std::cout << tabs << "How To Play Selected\n" << std::endl;
			running = 0;
			howtoplay();
			break;
		case 4:
			std::cout << tabs << "Exit Selected\n" << std::endl;
			running = 0;
			Exit();
			break;
		default:
			std::cout << tabs << "Error\n" << std::endl;
			running = 0;
			break;
		}

	}
	return 0;
}

int howtoplay()// this rules and how to play
{
	int back;

	std::cout << "The game is played with one or more decks of 52 cards.\n" << std::endl;
	std::cout << "Each player, including the dealer, is dealt two cards at the start of the round. One of the \n" << std::endl;
	std::cout << "dealer's cards is dealt face up, while the other is dealt face down (this is called the hole card). \n" << std::endl;
	std::cout << "The value of the cards is as follows: \n" << std::endl;
	std::cout << "2 through 10 are worth their face value (e.g. a 7 of hearts is worth 7 points).\n" << std::endl;
	std::cout << "Face cards (jacks, queens, and kings) are worth 10 points. \n" << std::endl;
	std::cout << "Aces can be worth 1 or 11 points, whichever is more beneficial for the hand. \n" << std::endl;
	std::cout << "The player goes first and has a few options: \n" << std::endl;
	std::cout << "Hit: Take another card. \n" << std::endl;
	std::cout << "Stand: Keep the current hand and end the turn. \n" << std::endl;
	std::cout << "If the player goes over 21 points, they lose the round (this is called a bust). \n" << std::endl;
	std::cout << "The dealer then reveals their hole card and plays according to a set of rules: \n" << std::endl;
	std::cout << "If the dealer has 16 points or less, they must hit. \n" << std::endl;
	std::cout << "If the dealer has 17 points or more, they must stand. \n" << std::endl;
	std::cout << "If the dealer busts, the player wins the round. If both the player and the dealer have 21 or  \n" << std::endl;
	std::cout << "less, the hand with the highest total value wins. \n\n\n" << std::endl;

	std::cout << tabs << "Type 1 to go back to the menu\n" << std::endl;
	cin >> back;

	switch (back)
	{
	case 1:
		std::cout << tabs << "Back Selected\n" << std::endl;
		main();
		break;
	}
	return 0;
}

int debug = 0;

int GameStart()
{
	
	int HorS = 0;
	int seed = 0;
	int bet = 0;
	int back = 0;
	int Dseeds = 0;
	int seedSet = 0;

	struct Card // this is the struct for the names suits and values of the cards
	{
		char m_cardName[6];
		char m_cardSuit[9];
		int m_cardNum;
	};

	struct Hand {
		Card cards[11];
		int length = 0;
	};

	if (balance <= 0) // this is the balance check 
	{
		int back;

		std::cout << tabs << "You lost all your money" << std::endl << std::endl;
		std::cout << tabs << "Type 1 to go Back to the Menu" << std::endl << std::endl;

		cin >> back;

		switch (back)
		{
		case 1:
			main();
		default:
			break;
		}

	}

	std::cout << "\t\t\t\t" << " Press 1 for random seed, Press 2 for set seed. " << std::endl;

	std::cin >> Dseeds;

	switch (Dseeds)
	{
	case 1:
		std::cout << tabs << "Ramdom seed selected" << std::endl;
		seedSet = 1;
		break;
	case 2:
		std::cout << tabs << " Type a ramdom seed the consists of 4 numbers:  " << std::endl;
		std::cin >> seed;
		seedSet = 2;
		break;

	}


	std::cout << tabs << std::endl;

	std::cout << tabs << "Balance: " << balance << std::endl << std::endl;

	std::cout << tabs << "How much would you like to bet:  ";

	
	std::cin >> bet;
	while(bet > balance)
	{
		std::cout << tabs << "Incorrect bet size" << std::endl;
		std::cout << tabs << "How much would you like to bet:  ";
		std::cin >> bet;
	}
	


	Card Deck[52] = { 0 };
	Hand Dealerhand;
	Hand Playerhand;

	for (int Suit = 0; Suit < 52; Suit += 13) // this is the creaton of the deck and how suits and ranks are assigned 
	{
		for (int Card = 0; Card < 13; Card++)
		{
			if (Card > 9) { Deck[Suit + Card].m_cardNum = 10; }
			else { Deck[Suit + Card].m_cardNum = Card + 1; }
			if (Suit == 0) { strcpy_s(Deck[Suit + Card].m_cardSuit, "Hearts"); }

			if (Suit == 13) { strcpy_s(Deck[Suit + Card].m_cardSuit, "Diamonds"); }

			if (Suit == 26) { strcpy_s(Deck[Suit + Card].m_cardSuit, "Clubs"); }

			if (Suit == 39) { strcpy_s(Deck[Suit + Card].m_cardSuit, "Spades"); }


			switch (Card)
			{
			case 0:
			{strcpy_s(Deck[Suit + Card].m_cardName, "Ace"); break; }
			case 1:
			{strcpy_s(Deck[Suit + Card].m_cardName, "2"); break; }
			case 2:
			{strcpy_s(Deck[Suit + Card].m_cardName, "3"); break; }
			case 3:
			{strcpy_s(Deck[Suit + Card].m_cardName, "4"); break; }
			case 4:
			{strcpy_s(Deck[Suit + Card].m_cardName, "5"); break; }
			case 5:
			{strcpy_s(Deck[Suit + Card].m_cardName, "6"); break; }
			case 6:
			{strcpy_s(Deck[Suit + Card].m_cardName, "7"); break; }
			case 7:
			{strcpy_s(Deck[Suit + Card].m_cardName, "8"); break; }
			case 8:
			{strcpy_s(Deck[Suit + Card].m_cardName, "9"); break; }
			case 9:
			{strcpy_s(Deck[Suit + Card].m_cardName, "10"); break; }
			case 10:
			{strcpy_s(Deck[Suit + Card].m_cardName, "Jack"); break;
			case 11:
			{strcpy_s(Deck[Suit + Card].m_cardName, "Queen"); break; }
			case 12:
			{strcpy_s(Deck[Suit + Card].m_cardName, "King"); break; }
			default: break;
			}
			}

		}
	}

	int firstCard = 0;// this is what i use to do the maths for the totals and things like that
	int secondCard = 0;
	int cardTotal = 0;

	int dealerfirstCard = 0;
	int dealersecondCard = 0;
	int dealerCardTotal = 0;
	
	for (int a = 0; a < 1; a++) // this gives 2 random card from the top of the shuffled deck
	{
		if (seedSet == 2)
		{
			srand(seed);
		}
		if (seedSet == 1)
		{
			srand(time(0));
		}

		for (std::size_t i = 0; i < std::size(Deck) - 1; ++i)
		{
			std::size_t j = i + rand() % (std::size(Deck) - i);
			std::swap(Deck[i], Deck[j]);
		}
		std::cout << "::Players Hand::" << std::endl;
		std::cout << Deck[a].m_cardName << " of " << Deck[a].m_cardSuit << "(" << Deck[a].m_cardNum << ")" << std::endl;
		firstCard = Deck[a].m_cardNum;
		Playerhand.cards[Playerhand.length++] = Deck[a];
		a++;

		std::cout << Deck[a].m_cardName << " of " << Deck[a].m_cardSuit << "(" << Deck[a].m_cardNum << ")" << std::endl;
		secondCard = Deck[a].m_cardNum;
		cardTotal = secondCard + firstCard;
		std::cout << "(" << cardTotal << ")" << std::endl << std::endl;
		Playerhand.cards[Playerhand.length++] = Deck[a];
		a++;

		std::cout << "::Dealers Hand::" << std::endl;
		std::cout << Deck[a].m_cardName << " of " << Deck[a].m_cardSuit << "(" << Deck[a].m_cardNum << ")" << std::endl;
		dealerfirstCard = Deck[a].m_cardNum;
		dealerCardTotal = dealerfirstCard + dealerCardTotal;
		Dealerhand.cards[Dealerhand.length++] = Deck[a];
		a++;


		while (dealerCardTotal < 17)
		{
			dealerfirstCard = Deck[a].m_cardNum;
			dealerCardTotal = dealerfirstCard + dealerCardTotal;
			std::cout << "(" << "Hidden Card" << ")" << std::endl;
			if (debug == 1) 
			{
				std::cout << Deck[a].m_cardName << " of " << Deck[a].m_cardSuit << "(" << Deck[0].m_cardNum << ")" << std::endl;
			}
			Dealerhand.cards[Dealerhand.length++] = Deck[a];
			a++;

			
		}


		while (true)
		{
			a++;
			std::cout << tabs << "Press 1  for hit or press 2 for stand" << endl;

			cin >> HorS;


			switch (HorS)  //switch statment to sort hitting and standing (2)
			{
			case 1:

				if (cardTotal > 21)
				{
					std::cout << tabs << "You Have gone Bust please select stand\n" << std::endl;
					break;
				}
				std::cout << tabs << "Hit Selected\n" << std::endl;

				std::cout << Deck[a].m_cardName << " of " << Deck[a].m_cardSuit << "(" << Deck[a].m_cardNum << ")" << std::endl;
				secondCard = Deck[a].m_cardNum;
				cardTotal = secondCard + cardTotal;
				std::cout << "(" << cardTotal << ")" << std::endl;
				Playerhand.cards[Playerhand.length++] = Deck[a];

				break;
			case 2: // this makes the player stand (2)
				std::cout << tabs << "Stand Selected\n" << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;


				for (int i = 0; i < Playerhand.length; ++i)
				{
					std::cout << "Players Cards = " << Playerhand.cards[i].m_cardName << " of " << Playerhand.cards[i].m_cardSuit << "(" << Playerhand.cards[i].m_cardNum << ")" << std::endl;
				}
				std::cout << "Players Card Total = " << "(" << cardTotal << ")" << std::endl << std::endl;



				for (int i = 0; i < Dealerhand.length; ++i)
				{
					std::cout << "Dealers Cards = " << Dealerhand.cards[i].m_cardName << " of " << Dealerhand.cards[i].m_cardSuit << "(" << Dealerhand.cards[i].m_cardNum << ")" << std::endl;
				}

				std::cout << "Dealers Card Total = " << "(" << dealerCardTotal << ")" << std::endl << std::endl;




				if (cardTotal > 21 && dealerCardTotal > 21)
				{
					std::cout << tabs << "You Both went bust\n" << std::endl;
					balance = balance;
					draw();

				}
				if (cardTotal > 21)
				{
					std::cout << tabs << "You went bust\n" << std::endl;
					balance = balance - bet;
					lose();
				}
				if (dealerCardTotal > 21)
				{
					std::cout << tabs << "Dealer went bust\n" << std::endl;
					balance = balance + bet;
					win();
				}

				if (cardTotal > dealerCardTotal)
				{
					balance = balance + bet;
					win();

				}
				if (dealerCardTotal > cardTotal)
				{
					balance = balance - bet;
					lose();

				}
				if (cardTotal = dealerCardTotal)
				{
					std::cout << tabs << "You Both had the same card values\n" << std::endl;
					balance = balance;
					draw();

				}
			}
		}

	}


	return 0;
}
int win()
{
	int back;

	std::cout << tabs << "You Won\n" << std::endl;
	std::cout << tabs << "your balance is now: " << balance << std::endl << std::endl;
	std::cout << tabs << "Type 1 to play again\n" << std::endl;
	std::cout << tabs << "Type 2 to go to the menu (this will reset balance)\n" << std::endl;

	cin >> back;

	switch (back)
	{
	case 1:
		system("CLS");
		std::cout << tabs << "New game Selected\n" << std::endl;
		GameStart();
		break;
	case 2:
		std::cout << tabs << "Main menu Selected\n" << std::endl;
		main();
		break;
	}
	return 0;
}
int lose()
{
	int back;

	std::cout << tabs << "You Lost\n" << std::endl;
	std::cout << tabs << "your balance is now: " << balance << std::endl << std::endl;
	std::cout << tabs << "Type 1 to play again\n" << std::endl;
	std::cout << tabs << "Type 2 to go to the menu (this will reset balance)\n" << std::endl;

	cin >> back;

	switch (back)
	{
	case 1:
		system("CLS");
		std::cout << tabs << "New game Selected\n" << std::endl;
		GameStart();
		break;
	case 2:
		std::cout << tabs << "Main menu Selected\n" << std::endl;
		main();
		break;
	}
	return 0;

}
int draw() 
{
	int back;

	std::cout << tabs << "You Drew\n" << std::endl;
	std::cout << tabs << "your balance is now: " << balance << std::endl << std::endl;
	std::cout << tabs << "Type 1 to play again\n" << std::endl;
	std::cout << tabs << "Type 2 to go to the menu (this will reset balance)\n" << std::endl;

	cin >> back;

	switch (back)
	{
	case 1:
		system("CLS");
		std::cout << tabs << "New game Selected\n" << std::endl;
		GameStart();
		break;
	case 2:
		std::cout << tabs << "Main menu Selected\n" << std::endl;
		main();
		break;
	}
	return 0;


}

int options()
{
	int options_choice;
	bool optionsrunning = 1;


	if (optionsrunning = 1)
	{

		std::cout << tabs << "Type 1 Debug mode\n" << std::endl;
		std::cout << tabs << "Type 2 To Go Back\n" << std::endl;
		
		cin >> options_choice;

		switch (options_choice)
		{
		case 1:
			std::cout << tabs << "Debug selected\n" << std::endl;
			debug = 1;
			main();
			optionsrunning = 0;
			break;
		case 2:
			main();
			optionsrunning = 0;

		}
	}
	return 0;
}

int Exit()
{
	return 0;
}
