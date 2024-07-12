#include <bits/stdc++.h>
#include <fstream>
using namespace std;
class BILL
{
public:
    unordered_map<string, int> Price;
    void InsertItem(string name, int price)
    {
        Price[name] = price;
    }
};
void AddItems(BILL &bill, int &total, bool &exit)
{
    bool close = false;
    while (!close)
    {
        int choice2;
        cout << "\t\t 1.ADD ";
        cout << "\t\t 2.CLOSE ";
        cout << "\t\t 3.EXIT" << endl;
        cout << " enter the choice :";
        cin >> choice2;
        while (choice2 != 1 && choice2 != 2 && choice2 != 3)
        {
            cout << " \t\t invalid input " << " enter again : ";
            int a;
            cin >> a;
            choice2 = a;
        }
        if (choice2 == 3)
        {
            exit == true;
            return;
        }
        if (choice2 == 1)
        {
            system("cls");
            string nameOfItem;
            int quantity;
            cout << " enter the name of the fruit ->";
            cin >> nameOfItem;
            while (bill.Price[nameOfItem] == 0)
            {
                cout << " \t\t !! invalid input      enter again ";
                string temp;
                cin >> temp;
                nameOfItem = temp;
            }
            cout << " enter the quantity of " << nameOfItem << " -> ";
            cin >> quantity;
            ofstream out("bill.txt", ios::app);
            out << "\t" << nameOfItem << "\t\t\t\t\t" << bill.Price[nameOfItem] << "\t\t\t\t\t" << quantity << "\t\t\t\t\t" << bill.Price[nameOfItem] * quantity << endl;
            cout << "Item added Successfully " << endl;
            total = total + bill.Price[nameOfItem] * quantity;
        }
        else
        {
            close == true;
            system("cls");
            cout << " \tBack To Main Menu ";
            /*
            ofstream out("bill.txt", ios::app);
            for (int i = 0; i < 16; i++)
            {
                out << "\t";
            }
            out << "------------" << endl;
            for (int i = 0; i <= 16; i++)
            {
                out << "\t";
            }
            out << total;*/
            break;
        }
    }
}
void PrintBill(BILL bill, int &total, bool &exit)
{
    bool close = false;
    while (!close)
    {
        cout << "\t\t1. Add Bill";
        cout << "\t\t2. Print Bill";
        cout << "\t\t 3.EXIT" << endl;
        int choice;
        cout << "\nenter the choice -> ";
        cin >> choice;
        while (choice != 1 && choice != 2)
        {
            cout << "invalid input   enter again :-> ";
            cin >> choice;
        }
        if (choice == 3)
        {
            exit = true;
            return;
        }
        if (choice == 1)
        {
            system("cls");
            string nameOfItem;
            int quantity;
            cout << " enter the name of the fruit ->";
            cin >> nameOfItem;
            while (bill.Price[nameOfItem] == 0)
            {
                cout << " \t\t !! invalid input      enter again ";
                string temp;
                cin >> temp;
                nameOfItem = temp;
            }
            cout << " enter the quantity of " << nameOfItem << " -> ";
            cin >> quantity;
            ofstream out("bill.txt", ios::app);
            out << "\t" << nameOfItem << "\t\t\t\t" << bill.Price[nameOfItem] << "\t\t\t\t\t" << quantity << "\t\t\t\t\t" << bill.Price[nameOfItem] * quantity << endl;
            cout << "Item added Successfully " << endl;
            total = total + bill.Price[nameOfItem] * quantity;
        }
        else
        {
            close == true;
            system("cls");
            cout << " \t HERE'S THE BILL " << endl;
            ofstream out("bill.txt", ios::app);
            for (int i = 0; i < 16; i++)
            {
                out << "\t";
            }
            out << "------------" << endl;
            for (int i = 0; i <= 16; i++)
            {
                out << "\t";
            }
            out << total << endl;
            cout << endl;
            cout << endl;
            // print bill

            std::ifstream inputFile("bill.txt");

            if (inputFile.is_open())
            {
                std::string line;

                while (std::getline(inputFile, line))
                {
                    std::cout << line << std::endl;
                }

                inputFile.close();
            }
            else
            {
                std::cout << "Failed to open the file." << std::endl;
            }
            ofstream lin("bill.txt");
            lin << "\t\t\t\t\t\t**  THE SIDDHANT FRUIT MARKET  **" << endl
                << endl
                << "\t\t\t\t\t\t\t\t* BILL RECEIPT *" << endl
                << endl
                << endl
                << "\tFRUIT NAME  \t\t\tPRICE   \t\t\tQUANTITY\t\t\tTOTAL" << endl
                << "\t.   \t\t\t\t.   \t\t\t\t.   \t\t\t\t." << endl;
            int a;
            cout << "\t\t\t 1.create another bill :";
            cout << "\t\t 2.exit :";
            cin >> a;
            if (a != 1)
            {
                exit = true;
                total = 0;
                system("cls");
                return;
            }
            break;
        }
    }
}
int main()
{
    BILL bill;
    int total = 0;
    /*
        while(1){
        string name;
        int quant;
        cout<<"enter the fruit name -> ";
        cin>>name;
        if(name=="done"){
            break;
        }
        cout<<"enter the quantity -> ";
        cin>>quant;
    }*/
    bill.InsertItem("apple", 20);
    bill.InsertItem("banana", 5);
    bill.InsertItem("pineapple", 40);
    bill.InsertItem("mango", 90);
    bill.InsertItem("graphes", 25);
    bill.InsertItem("orange", 10);
    bill.InsertItem("lime", 5);
    bill.InsertItem("capcicum", 100);
    bill.InsertItem("avocado", 30);
    bill.InsertItem("cherry", 550);
    bill.InsertItem("guava", 450);
    bill.InsertItem("dragon_fruit", 200);
    bill.InsertItem("fig", 32);
    bill.InsertItem("kiwi", 85);
    bill.InsertItem("strawberry", 80);
    bill.InsertItem("watermelon", 40);
    bill.InsertItem("papaya", 55);
    bill.InsertItem("blackberry", 15);
    bill.InsertItem("coconut", 25);
    bill.InsertItem("apricot", 95);
    bool exit = false;
    int choice;
    cout << " \n*   WELCOME TO THE SIDDHANT FRUIT MARKET BILLING SYSTEM   *" << endl;
    cout << " **********************************************************" << endl;
    while (!exit)
    {
        cout << " \n             1 . ADD ITEMS.";
        cout << " \n             2 . PRINT BILL.";
        cout << " \n             3 . EXIT. ";
        cout << " \n\n            ENTER YOUR CHOICE -> ";
        cin >> choice;
        while (choice != 1 && choice != 2 && choice != 3)
        {
            cout << " \n          !! invalid input !! ";
            cout << " enter again ";
            cin >> choice;
        }
        if (choice == 1)
        {
            system("cls");
            AddItems(bill, total, exit);
        }
        else if (choice == 2)
        {
            system("cls");
            PrintBill(bill, total, exit);
        }
        else
        {
            exit == true;
            // print function
        }
    }
}
