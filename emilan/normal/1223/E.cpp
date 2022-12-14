#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<pii>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<array<ll, 2>> dp(n);
    auto dfs = [&](auto &self, int u, int p) -> void {
        ll base = 0;
        vector<ll> extra;
        for (auto [v, w] : adj[u]) if (v != p) {
            self(self, v, u);
            base += dp[v][0];
            if (dp[v][1] + w > dp[v][0]) {
                extra.push_back(dp[v][1] + w - dp[v][0]);
            }
        }

        sort(RALL(extra));

        int m = min(k - 1, SZ(extra));
        dp[u][1] = base + accumulate(begin(extra), begin(extra) + m, 0LL);
        dp[u][0] = dp[u][1] + (m == SZ(extra) ? 0LL : extra[m]);
    };
    dfs(dfs, 0, -1);

    cout << dp[0][0] << '\n';
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