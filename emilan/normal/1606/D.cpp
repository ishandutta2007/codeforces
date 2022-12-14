#include <bits/stdc++.h>

using namespace std;

using A2 = array<int, 2>;
using A3 = array<int, 3>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &v : a) {
        for (int &x : v) cin >> x;
    }

    vector<vector<A2>> pre(n, vector<A2>(m));
    vector<vector<A2>> suf(n, vector<A2>(m));
    for (int i = 0; i < n; i++) {
        // ->
        pre[i][0][0] = pre[i][0][1] = a[i][0];
        for (int j = 1; j < m; j++) {
            pre[i][j][0] = min(pre[i][j - 1][0], a[i][j]);
            pre[i][j][1] = max(pre[i][j - 1][1], a[i][j]);
        }

        // <-
        suf[i][m - 1][0] = suf[i][m - 1][1] = a[i][m - 1];
        for (int j = m - 2; j >= 0; j--) {
            suf[i][j][0] = min(suf[i][j + 1][0], a[i][j]);
            suf[i][j][1] = max(suf[i][j + 1][1], a[i][j]);
        }
    }

    auto cmp_l = [](A3 x, A3 y) {
        return x[1] < y[1];
    };

    auto cmp_r = [](A3 x, A3 y) {
        return x[0] > y[0];
    };

    for (int k = 1; k < m; k++) {
        vector<bool> vis(n); // red
        priority_queue<A3, vector<A3>, decltype(cmp_l)> pq_l(cmp_l);
        priority_queue<A3, vector<A3>, decltype(cmp_r)> pq_r(cmp_r);
        for (int i = 0; i < n; i++) {
            pq_l.push({
                pre[i][k - 1][0],
                pre[i][k - 1][1],
                i
            });

            pq_r.push({
                suf[i][k][0],
                suf[i][k][1],
                i
            });
        }

        int first = pq_l.top()[2];
        vis[first] = true;
        int l_min = pre[first][k - 1][0];
        int r_max = suf[first][k][1];

        auto update = [&](int i) {
            vis[i] = true;
            l_min = min(l_min, pre[i][k - 1][0]);
            r_max = max(r_max, suf[i][k][1]);
        };

        for (;;) {
            bool cont = false;

            while (!pq_l.empty()) {
                auto [l, r, i] = pq_l.top();
                if (vis[i]) {
                    pq_l.pop();
                    continue;
                }

                if (r >= l_min) {
                    cont = true;
                    update(i);
                } else {
                    break;
                }
            }

            // bruh lmao
            // although it shouldn't affect correctness
            // if (!pq_r.empty()) {
            while (!pq_r.empty()) {
                auto [l, r, i] = pq_r.top();
                if (vis[i]) {
                    pq_r.pop();
                    continue;
                }

                if (l <= r_max) {
                    cont = true;
                    update(i);
                } else {
                    break;
                }
            }

            if (!cont) break;
        }

        if (count(vis.begin(), vis.end(), false) != 0) {
            cout << "YES\n";
            for (bool x : vis) {
                if (x) cout << 'R';
                else cout << 'B';
            }
            cout << ' ' << k << '\n';

            return;
        }
    }

    cout << "NO\n";
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