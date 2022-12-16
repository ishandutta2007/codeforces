#include <bits/stdc++.h>
using namespace std;

int amount[30];

int main() {
    string s;
    int total = 0;
    cin >> s;
    for(int i = 0; i < s.length(); i++) {
        if(amount[s[i]-'a']++ == 0) {
            total++;
        }
    }
    if(total % 2) {
        puts("IGNORE HIM!");
    } else {
        puts("CHAT WITH HER!");
    }
    return 0;
}