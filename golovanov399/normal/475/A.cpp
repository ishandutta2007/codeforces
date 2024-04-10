#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second

using namespace std;

int main(){

    int n;
    cin >> n;
    cout << "+";
    for (int i = 0; i < 11; i++) cout << "--";
    cout << "--+\n";
    cout << "|";
    if (n >= 1) cout << "O."; else cout << "#.";
    for (int i = 0; i < 10; i++){
        if (n > 4 + 3 * i) cout << "O."; else cout << "#.";
    }
    cout << "|D|)\n";
    cout << "|";
    if (n >= 2) cout << "O."; else cout << "#.";
    for (int i = 0; i < 10; i++){
        if (n > 5 + 3 * i) cout << "O."; else cout << "#.";
    }
    cout << "|.|\n";
    cout << "|";
    if (n >= 3) cout << "O."; else cout << "#.";
    for (int i = 0; i < 10; i++){
        cout << "..";
    }
    cout << "..|\n";
    cout << "|";
    if (n >= 4) cout << "O."; else cout << "#.";
    for (int i = 0; i < 10; i++){
        if (n > 6 + 3 * i) cout << "O."; else cout << "#.";
    }
    cout << "|.|)\n";
    cout << "+";
    for (int i = 0; i < 11; i++) cout << "--";
    cout << "--+";

    return 0;
}