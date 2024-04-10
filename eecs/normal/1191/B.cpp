#include <bits/stdc++.h>
using namespace std;

string s[3];

int main() {
    cin >> s[0] >> s[1] >> s[2];
    sort(s, s + 3);
    if (s[0] == s[1] && s[1] == s[2]) printf("0\n"), exit(0);
    if (s[0][1] == s[1][1] && s[1][1] == s[2][1] && s[1][0] == s[0][0] + 1 && s[2][0] == s[1][0] + 1) printf("0\n"), exit(0);
    if (s[0] == s[1] || s[1] == s[2]) printf("1\n"), exit(0);
    if (s[0][1] == s[1][1] && s[1][0] == s[0][0] + 1) printf("1\n"), exit(0);
    if (s[0][1] == s[1][1] && s[1][0] == s[0][0] + 2) printf("1\n"), exit(0);
    if (s[1][1] == s[2][1] && s[2][0] == s[1][0] + 1) printf("1\n"), exit(0);
    if (s[1][1] == s[2][1] && s[2][0] == s[1][0] + 2) printf("1\n"), exit(0);
    if (s[0][1] == s[2][1] && s[2][0] == s[0][0] + 1) printf("1\n"), exit(0);
    if (s[0][1] == s[2][1] && s[2][0] == s[0][0] + 2) printf("1\n"), exit(0);
    printf("2\n");
    return 0;
}