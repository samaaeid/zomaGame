#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

int n=0;
int capacity=20;
int* arr = new int[capacity];

void reserve(int new_capacity) {
    int* temp = new int[new_capacity];
    for (int i = 0; i < n; i++)
        temp[i] = arr[i];
	delete[] arr;
	arr = temp;
	capacity = new_capacity;
}

void insert_element(int item, int idx) {
    if (idx < 0 || idx > n)
		return;
    cout<<'p';
    if (n == capacity)
        reserve(2 * capacity + 1);
    cout<<'o';
	int j = n - 1;
	while (j >= idx) {
		arr[j+1] = arr[j];
		j = j - 1;
	}
    cout<<'m';
	arr[idx] = item;
	n = n + 1;
    cout<<'i';
}

void delete_element(int idx) {
	if (idx < 0 || idx >= n)
		return;
	int j = idx;
	while (j < n) {
		arr[j] = arr[j+1];
		j = j + 1;
	}
	n = n - 1;
    if (n < capacity / 2)
        reserve(capacity / 2);
}

bool search_element(int item) {
	int j = 0;
	while (j < n) {
		if (arr[j] == item)
			return true;
		j = j + 1;
	}
	return false;
}

void print_array() {
	int i = 0;
	while (i < n) {
		cout << arr[i] << ' ';
		i = i + 1;
	}
}

const int N = 3;
const int M = 7;
int number[20];
int counter=0;
int indx=0;

//This function prints the grid of Gomoku as the game progresses
void print_grid() {
    cout << "\n";
	cout << "-";
    for (int i = 0; i < M; cout << "---", i++);
    cout << "--\n";
    //for (int j = 0; j < n;cout << arr[j],  j++)
    //cout << "\n";
    print_array();
    cout << "\n";     cout << "\n";   cout << "\n";
    for (int k = 0; k < n; k++){
        if(number[k]){
            cout << number[k]<<' ';
        }
        else{
            cout<<"  ";
        }
    }
    cout << "\n";
    for (int i = 0; i < M; cout << "", i++);
    for (int i = 0; i < M; cout << "---", i++);
    cout << "--\n";
} 

//This function checks if the game has a win state or not
bool check_win() {
    return !n;
}

/*bool check_lose() {
    
}*/

//This function checks if given position is valid or not
bool check_valid_column(int i) {
    if (0<i && i<=3 ){
         return true;}
    else{
        return false;
            }}

int move(int i ){
    if(i==1){
        number[indx+1]=number[indx];
        number[indx]=0;
        indx++; 
    }
    else if(i==2){
        number[indx-1]=number[indx];
        number[indx]=0;
        indx--;
    }
}

//This function sets the given mark to the given column index
void set_cell(int a) {
    if( arr[indx]==a && arr[indx+1]==a || arr[indx+1]==a && arr[indx+2]==a) {
        /*for (int i = indx ; i < n ; i++)
        {   
            if(arr[i]==a)    
            {
                delete_element(i);
            }
            else {break;}
        }*/
        while (arr[indx]==a)
        {
            delete_element(indx); //7 8 9 
        }
    }
    if( arr[indx]==a && arr[indx-1]==a || arr[indx-1]==a && arr[indx-2]==a ){
        for (int i = indx ; i >= 0 && arr[i]==a ; i--)
        {   

                delete_element(i);
 
        } 
    }
    if(!(arr[indx]==a && arr[indx-1]==a || arr[indx-1]==a && arr[indx-2]==a) ||
       !(arr[indx]==a && arr[indx+1]==a || arr[indx+1]==a && arr[indx+2]==a)) {
        insert_element(a,indx);
    }
    number[indx]=0;
}

//This function generates pac man
int generate_number() {
    srand( (unsigned)time( NULL ) );
    int a = rand() % N +1;
    number[n/2] = a;
    indx=n/2;
    return a;
}

//This function generates pac man
void generate_zoma() {
    srand((unsigned)time( NULL ));
    for(int i=0 ; i<capacity/2 ; i++){
        int a = rand() % N +1;
        cout<<n<<a;
        insert_element(a,n) ;
        cout<<'l';
    }
    cout<<'f';
}

//This function clears the game structures
void grid_clear() {
    n=0;
    counter=0;
    arr = new int[capacity];
    for (int i = 0; i < capacity; i++)
    {
        number[i]=0;
    } 
    cout<<'f';}

//This function reads a valid position input
void read_input(int &i) {
    cout << "Enter the column index: ";
    cin >> i;
    while (!check_valid_column(i)) {
        cout << "Enter a valid column index: ";
        cin >> i;
    }
}
//MAIN FUNCTION
void play_game(int k) {
    cout << "ZOMA Game!\n";
    cout << "Welcome...\n";
    cout << "============================\n";
    while (true) {
        //Prints the grid
        print_grid();
        int i;
		read_input(i);
        //Set the input position with the mark
        if(i==3){
           set_cell(k); 
           k=generate_number();
        }
        else{
            move(i);
        }
        //cout<< "your score is :" <<counter;
        //Check if the state of the grid has a win state
        if (check_win()) {
            //Prints the grid
            print_grid();
            //Announcement of the final statement
            cout << "Congrats, you won!\n";
            cout<< "your score is :" <<counter;
            break;
        }
        //Check if the state of the grid has a tie state
        /*if (check_lose()){
            //Prints the grid
            print_grid();
            //Announcement of the final statement
            cout << "Woah! That's a tie!\n";
            break;}*/
    }
}
int main() {
    while (true) {
        grid_clear();
        generate_zoma();
        int a=generate_number();
    	play_game(a);
    	char c;
    	cout << "Play Again [Y/N] ";
    	cin >> c;
    	if (c != 'y' && c != 'Y')
    		break;
    }
}
