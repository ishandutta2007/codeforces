#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int n;
string s[N];

int main() {
    int found = 0;
    //freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (found) continue;
        if (s[i][0] == 'O' && s[i][1] == 'O') {
            found = 1;
            s[i][0] = s[i][1] = '+';
        } else if (s[i][3] == 'O' && s[i][4] == 'O') {
            found = 1;
            s[i][3] = s[i][4] = '+';
        }
    }
    puts(found ? "YES" : "NO");
    if (found) {
        for (int i = 0; i < n; i++)
            cout << s[i] << endl;
    }
}