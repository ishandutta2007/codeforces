#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    auto solve = [&](string s) {
        while (1) {
            for (int i = 0; i + 1 < s.size(); i++) {
                if (s[i] == s[i + 1] && s[i] == 'B') {
                    s.erase(s.begin() + i, s.begin() + i + 2); goto next1;
                }
            }
            for (int i = 0; i + 1 < s.size(); i++) {
                if (s[i + 1] == 'B') {
                    swap(s[i], s[i + 1]); goto next1;
                }
            }
            break;
        next1:;
        }
        while (1) {
            for (int i = 0; i + 1 < s.size(); i++) {
                if (s[i] == s[i + 1]) {
                    s.erase(s.begin() + i, s.begin() + i + 2); goto next2;
                }
            }
            break;
        next2:;
        }
        return s;
    };
    while (T--) {
        string s, t;
        cin >> s >> t;
        cout << (solve(s) == solve(t) ? "YES" : "NO") << "\n";
    }
    return 0;
}