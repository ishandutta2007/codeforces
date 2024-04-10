#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
using namespace std;
using ld = long double;
using ll = int64_t;
using pii = pair<int, int>;
using ull = uint64_t;

char s[105][105];
vector<vector<int>> ans;

void add(int ya, int xa, int yb, int xb, int yc, int xc) {
    ans.push_back({ya, xa, yb, xb, yc, xc});
    s[ya][xa] ^= 1;
    s[yb][xb] ^= 1;
    s[yc][xc] ^= 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) cin >> s[i];
        ans.clear();
        for (int i = 0; i + 2 < n; ++i) {
            for (int j = 0; j + 1 < m; ++j) {
                if (s[i][j] == '1')
                    add(i, j,   i + 1, j,   i, j + 1);
            }
            if (s[i][m - 1] == '1')
                add(i, m - 1, i + 1, m - 1, i + 1, m - 2);
        }
        for (int j = 0; j + 1 < m; ++j) {
            if (s[n - 2][j] == '1' && s[n - 1][j] == '1')
                add(n - 2, j, n - 1, j, n - 1, j + 1);
            else if (s[n - 2][j] == '1' && s[n - 1][j] == '0')
                add(n - 2, j, n - 2, j + 1, n - 1, j + 1);
            else if (s[n - 2][j] == '0' && s[n - 1][j] == '1')
                add(n - 2, j + 1, n - 1, j + 1, n - 1, j);
        }
        if (s[n - 2][m - 1] == '1' && s[n - 1][m - 1] == '1') {
            add(n - 2, m - 2, n - 1, m - 2, n - 1, m - 1);
            add(n - 2, m - 2, n - 2, m - 1, n - 1, m - 2);
        } else if (s[n - 2][m - 1] == '0' && s[n - 1][m - 1] == '1') {
            add(n - 2, m - 2, n - 2, m - 1, n - 1, m - 1);
            add(n - 1, m - 2, n - 1, m - 1, n - 2, m - 1);
            add(n - 1, m - 2, n - 1, m - 1, n - 2, m - 2);
        } else if (s[n - 2][m - 1] == '1' && s[n - 1][m - 1] == '0') {
            add(n - 1, m - 2, n - 1, m - 1, n - 2, m - 1);
            add(n - 2, m - 2, n - 2, m - 1, n - 1, m - 1);
            add(n - 2, m - 2, n - 2, m - 1, n - 1, m - 2);
        }
        cout << ans.size() << "\n";
        for (auto v : ans) {
            for (int x : v) cout << x + 1 << " ";
            cout << "\n";
        }
    }
}