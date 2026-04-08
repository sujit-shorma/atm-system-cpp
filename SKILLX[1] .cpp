#include <iostream>
#include <string>
using namespace std;

// Structure to store user details
struct User {
    string name;
    int pin;
    double balance;
};

// Main ATM operations
int main() {
    User currentUser; // Current user data

    // User input for details
    cout << "Enter your name: ";
    getline(cin, currentUser.name);

    cout << "Create a 4-digit PIN: ";
    cin >> currentUser.pin;

    cout << "Enter initial balance (₹): ";
    cin >> currentUser.balance;

    // ATM operations
    while (true) {
        int pin;
        cout << "\nEnter your 4-digit PIN to access the ATM: ";
        cin >> pin;

        if (pin == currentUser.pin) {
            // User authenticated
            while (true) {
                cout << "\nWelcome, " << currentUser.name << "!\n";
                cout << "1. Check Balance\n";
                cout << "2. Deposit\n";
                cout << "3. Withdraw\n";
                cout << "4. Exit\n";
                cout << "Choose an option: ";
                
                int choice;
                cin >> choice;

                if (choice == 1) {
                    cout << "Your balance: ₹" << currentUser.balance << endl;
                } else if (choice == 2) {
                    double deposit;
                    cout << "Enter deposit amount: ₹";
                    cin >> deposit;
                    if (deposit > 0) {
                        currentUser.balance += deposit;
                        cout << "₹" << deposit << " deposited.\n";
                    } else {
                        cout << "Invalid amount.\n";
                    }
                } else if (choice == 3) {
                    double withdraw;
                    cout << "Enter withdrawal amount: ₹";
                    cin >> withdraw;
                    if (withdraw > 0 && withdraw <= currentUser.balance) {
                        currentUser.balance -= withdraw;
                        cout << "₹" << withdraw << " withdrawn.\n";
                    } else {
                        cout << "Insufficient funds or invalid amount.\n";
                    }
                } else if (choice == 4) {
                    cout << "Exiting... Goodbye!\n";
                    break;  // End session
                } else {
                    cout << "Invalid choice.\n";
                }
            }
        } else {
            cout << "Invalid PIN. Please try again.\n";
        }
    }

    return 0;
}
