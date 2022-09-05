#include <bits/stdc++.h>
using namespace std;

string s, t[5];

int main() {
    cin >> s;
    for (int i = 0; i < 5; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < 5; i++) {
        if (s[0] == t[i][0] || s[1] == t[i][1]) puts("YES"), exit(0);
    }
    puts("NO"), exit(0);
    return 0;
}