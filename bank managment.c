#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void createAccount();
void depositMoney();
void withdrawMoney();
void checkBalance();

int accountNumber = 0;
char name[50];
float balance = 0.0;

int main() {
    int choice;

    while(1) {
        printf("\n**** Bank Management System ****\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to create an account
void createAccount() {
    printf("\nEnter your name: ");
    scanf(" %[^\n]s", name);  // to read string with spaces
    accountNumber = rand() % 1000000;  // Random account number
    balance = 0.0;  // Initial balance is 0

    printf("Account created successfully!\n");
    printf("Account Number: %d\n", accountNumber);
    printf("Account Holder: %s\n", name);
    printf("Initial Balance: %.2f\n", balance);
}

// Function to deposit money
void depositMoney() {
    float amount;
    printf("\nEnter amount to deposit: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount. Please enter a positive value.\n");
    } else {
        balance += amount;
        printf("Deposited %.2f successfully. New Balance: %.2f\n", amount, balance);
    }
}

// Function to withdraw money
void withdrawMoney() {
    float amount;
    printf("\nEnter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount. Please enter a positive value.\n");
    } else if (amount > balance) {
        printf("Insufficient balance. Available balance: %.2f\n", balance);
    } else {
        balance -= amount;
        printf("Withdrawn %.2f successfully. New Balance: %.2f\n", amount, balance);
    }
}

// Function to check balance
void checkBalance() {
    printf("\nAccount Holder: %s\n", name);
    printf("Account Number: %d\n", accountNumber);
    printf("Current Balance: %.2f\n", balance);
}
