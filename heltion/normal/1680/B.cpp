#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        int x = n, y = m;
        for (int i = 0; i < n; i += 1) {
            cin >> s[i];
            for (int j = 0; j < m; j += 1)
                if (s[i][j] == 'R') {
                    x = min(x, i);
                    y = min(y, j);
                }
        }
        cout << (s[x][y] == 'R' ? "YES\n" : "NO\n");
    }
}