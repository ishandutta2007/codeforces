#include <bits/stdc++.h>

using namespace std;

const int N = 400;
using bs = bitset<N>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<bs> a(n);
    for (auto &v : a) {
        cin >> v;
    }

    vector<vector<int>> pre(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pre[i + 1][j + 1] = a[i][j]
                + pre[i + 1][j] + pre[i][j + 1] - pre[i][j];
        }
    }

    // [l, r)
    auto get = [&](int x1, int y1, int x2, int y2) -> int {
        return pre[x2][y2] - pre[x2][y1]
            - pre[x1][y2] + pre[x1][y1];
    };

    // [u, d)
    int ans = 16;
    for (int u = 0; u < n; u++) {
        for (int d = u + 5; d <= n; d++) {
            auto calc_left = [&](int l, int r) {
                return d - u - 2 - get(u + 1, l, d - 1, l + 1)
                    + 2 * (r - l - 1) - get(u, l + 1, d, r)
                    + 2 * get(u + 1, l + 1, d - 1, r);
            };

            int left_min = 16;
            for (int i = 0; i + 4 <= m; i++) {
                int l = i, r = i + 4;

                int x = calc_left(l, l + 3);
                int y = calc_left(l, l + 2);
                left_min = min(
                    left_min + x - y,
                    x
                );

                ans = min(
                    ans,
                    left_min + d - u - 2 - get(u + 1, r - 1, d - 1, r)
                );
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}