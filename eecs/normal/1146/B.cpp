#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    cin >> s;
    int n = s.length(), cur = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') cur++;
        if (i + 1 + i + 1 - cur == n) {
            string t;
            for (int j = 0; j <= i; j++) {
                if (s[j] ^ 'a') t.push_back(s[j]);
            }
            if (s.substr(0, i + 1) + t != s) cout << ":(\n", exit(0);
            cout << s.substr(0, i + 1) << "\n", exit(0);
        }
    }
    cout << ":(\n";
    return 0;
}