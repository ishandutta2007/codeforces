#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>


using namespace std;


int s;


int main() {
    cin >> s;
    cout << '+';
    for (int i = 0; i < 24; i++) {
        cout << '-';
    }
    cout << "+";
    cout << endl;
    int t = 1 + (max(s - 4, 0) + 2) / 3;
    int t1 = t;
    cout << '|';
    if (s == 0) {
        t = 0;
        t1 = 0;
    }
    for (int i = 0; i < t; i++) {
        cout << 'O';
        cout << '.';
    }
    for (int i = t; i < 11; i++) {
        cout << '#';
        cout << '.';
    }
    cout << "|D|)"; 
    cout << endl;
    cout << '|';
    for (int i = 0; i < t; i++) {
        if (s >= 2 && (i != t - 1 || (i == t - 1 && max((s - 4), 0) % 3 != 1))) {
            cout << 'O';
            cout << '.';
        }
    }
    if (max(s - 4, 0) % 3 == 1 || s < 2) {
        t1 = max(t - 1, 0);
    }
    t1 = max(t1, 0);
    for (int i = t1; i < 11; i++) {
        cout << '#';
        cout << '.';
    }
    cout << "|.|"; 
    cout << endl;
    cout << '|'; 
    if (t == 1) {
        if (s >= 3) {
            cout << 'O';
        } else {
            cout << '#';
        }
    } else {
        if (t > 0) {
            cout << 'O';
        } else {
            cout << '#';
        }
    }
    for (int i = 0; i < 23; i++) {
        cout << '.';
    }
    cout << '|';
    cout << endl;
    cout << '|';
    for (int i = 0; i < t; i++) {
        if (s >= 4 && (i != t - 1 || (i == t - 1 && max((s - 4), 0) % 3 == 0))) {
            cout << 'O';
            cout << '.';
        }
    }
    if (max(s - 4, 0) % 3 != 0 || s <= 3) {
        t1 = max(t - 1, 0);
    }
    t1 = max(t1, 0);
    for (int i = t1; i < 11; i++) {
        cout << "#.";
    }
    cout << "|.|)"; 
    cout << endl;
    cout << '+';
    for (int i = 0; i < 24; i++) {
        cout << '-';
    }
    cout << "+";
    cout << endl;
    return 0;
}