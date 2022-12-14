
#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vt<vt<int>> a(n, vt<int>(n));
    for (auto &v : a) {
        cin >> ws;
        for (int &x : v) {
            char y;
            cin >> y;
            x = int(y - '0');
        }
    }

    for (int i = 0; i < 10; i++) {
        int l = n, r = -1, u = n, d = -1;
        vt<vt<int>> row(n), col(n);
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (a[x][y] == i) {
                    l = min(l, y);
                    r = max(r, y);
                    u = min(u, x);
                    d = max(d, x);

                    row[x].push_back(y);
                    col[y].push_back(x);
                }
            }
        }

        int ans = 0;

        for (int x = 0; x < n; x++) {
            if (row[x].empty()) continue;

            ans = max({
                ans,

                (n - 1 - row[x][0]) * max(x - u, d - x),
                (row[x].back()) * max(x - u, d - x),

                (row[x].back() - row[x][0]) * x,
                (row[x].back() - row[x][0]) * (n - 1 - x)
            });
        }

        for (int y = 0; y < n; y++) {
            if (col[y].empty()) continue;

            ans = max({
                ans,

                (n - 1 - col[y][0]) * max(y - l, r - y),
                (col[y].back()) * max(y - l, r - y),

                (col[y].back() - col[y][0]) * y,
                (col[y].back() - col[y][0]) * (n - 1 - y)
            });
        }

        cout << ans << ' ';
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}