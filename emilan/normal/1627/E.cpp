#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
constexpr i64 kInf = 1LL << 61;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<vector<array<int, 4>>> adj(n);
    while (k--) {
        int i1, j1, i2, j2, w;
        cin >> i1 >> j1 >> i2 >> j2 >> w;
        adj[i1 - 1].push_back({j1 - 1, i2 - 1, j2 - 1, w});
    }
    adj[n - 1].push_back({m - 1, n, 0, 0});

    vector<map<int, i64>> dp(n + 1);
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end());
        {
            auto it = dp[i].begin();
            i64 best = kInf;
            for (auto &[j1, i2, j2, w] : adj[i]) {
                while (it != dp[i].end()) {
                    auto [j, val] = *it;
                    if (j > j1) break;
                    best = min(best, val - i64(j) * a[i]);
                    it++;
                }
                if (best != kInf) {
                    i64 ori = dp[i2].count(j2) ? dp[i2][j2] : kInf;
                    i64 walk_cost = i64(j1) * a[i];
                    dp[i2][j2] = min(ori, -w + walk_cost + best);
                }
            }
        }

        reverse(adj[i].begin(), adj[i].end());
        {
            auto it = dp[i].rbegin();
            i64 best = kInf;
            for (auto &[j1, i2, j2, w] : adj[i]) {
                while (it != dp[i].rend()) {
                    auto [j, val] = *it;
                    if (j < j1) break;
                    best = min(best, val + i64(j) * a[i]);
                    it++;
                }
                if (best != kInf) {
                    i64 ori = dp[i2].count(j2) ? dp[i2][j2] : kInf;
                    i64 walk_cost = -i64(j1) * a[i];
                    dp[i2][j2] = min(ori, -w + walk_cost + best);
                }
            }
        }
    }

    if (dp[n].empty()) cout << "NO ESCAPE";
    else cout << dp[n][0];
    cout << '\n';
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