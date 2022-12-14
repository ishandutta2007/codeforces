#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        int state = 1, cd = 0;
        for (int i = 0; i < int(s.size()); i++) {
            if (s[i] == '0' + state) {
                if (cd) {
                    state--;
                } else {
                    s.erase(s.begin() + i);
                    i--;
                    cd = 2;
                }
            }

            if (cd) cd--;
        }

        cout << (state >= 0 ? "yEs" : "nO") << '\n';
    }
}