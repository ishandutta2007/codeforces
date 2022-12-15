#include <bits/stdc++.h>
using namespace std;

int amount[30];

int main() {
    string s, lowerS, upperS;
    int lower = 0, upper = 0;
    cin >> s;
    for(int i = 0; i < s.length(); i++) {
        lowerS.push_back(tolower(s[i]));
        upperS.push_back(toupper(s[i]));
        if(s[i] != lowerS[i]) {
            upper++;
        } else {
            lower++;
        }
    }
    if(upper > lower) {
        cout << upperS;
    } else {
        cout << lowerS;
    }
    return 0;
}