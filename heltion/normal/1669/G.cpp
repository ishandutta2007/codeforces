#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m;
        cin >> n >> m;
        vector<string> s(n), t(n, string(m, '.'));
        for (auto& si : s) cin >> si;
        for (int i = 0; i < m; i += 1) {
            for (int L = n - 1, R = n - 1; L >= 0; L = R -= 1)
                if (s[L][i] != 'o') {
                    while (R >= 0 and s[R][i] != 'o') R -= 1;
                    int c = 0;
                    for (int j = L; j > R; j -= 1) c += s[j][i] == '*';
                    for (int j = L; j > L - c; j -= 1) t[j][i] = '*';
                }
        }
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1)
                if (s[i][j] == 'o')
                    t[i][j] = 'o';
            cout << t[i] << '\n';
        }
    }
}