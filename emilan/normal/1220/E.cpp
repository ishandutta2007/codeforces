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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<vector<int>> adj(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int s;
    cin >> s;
    s--;

    vector<bool> vis(n);
    vector<bool> safe(n);
    vector<ll> dp(n);
    auto dfs = [&](auto &self, int u, int p) -> void {
        vis[u] = true;
        for (int v : adj[u]) if (v != p) {
            if (vis[v]) safe[u] = true;
            else {
                self(self, v, u);
                if (safe[v]) safe[u] = true;
                dp[u] = max(dp[u], dp[v]);
            }
        }

        if (!safe[u]) dp[u] += a[u];
    };
    dfs(dfs, s, -1);

    ll ans = dp[s];
    for (int u = 0; u < n; u++) if (safe[u]) {
        ans += a[u];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}