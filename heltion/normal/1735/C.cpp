#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> f(26, -1), v(26), x;
        for (char c : s)
            if (not v[c - 'a']) {
                x.push_back(c - 'a');
                v[c - 'a'] = 1;
            }
        auto check = [&]() {
            vector<int> p(26, -1), u(26);
            for (int i = 0; i < 26; i += 1)
                if (f[i] != -1) {
                    if (p[f[i]] != -1) return 0;
                    p[f[i]] = i;
                }
            for (int i = 0; i < 26; i += 1)
                if (not u[i]) {
                    int j = i, c = 0;
                    while (j != -1 and not u[j]) {
                        u[j] = 1;
                        j = p[j];
                        c += 1;
                    }
                    if (j == i and c != 26) {
                        return 0;
                    }
                }
            return 1;
        };
        for (int xi : x)
            for (int i = 0; i < 26; i += 1) {
                f[xi] = i;
                if (check()) break;
            }
        for (char c : s) cout << char(f[c - 'a'] + 'a');
        cout << "\n";
    }
}