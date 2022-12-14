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
    vt<vt<pii>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    ll ans = 0;
    vt<int> in[2], g[2];
    in[0].resize(n + 1, -1);
    in[1].resize(n + 1, -1);

    for (int w = 0; w < 2; w++) {
        for (int v = 1; v <= n; v++) if (!~in[w][v]) {
            g[w].push_back(0);

            auto dfs = [&](int u, int p, auto &f) -> void {
                in[w][u] = sz(g[w]) - 1;
                g[w].back()++;
                for (pii e : adj[u]) if (e.fi != p && e.se == w) {
                    f(e.fi, u, f);
                }
            };

            dfs(v, v, dfs);

            ans += g[w].back() * (g[w].back() - 1ll);
        }
    }

    for (int v = 1; v <= n; v++) {
        if (~in[0][v] && ~in[1][v]) {
            ans += (g[0][in[0][v]] - 1ll) * (g[1][in[1][v]] - 1);
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}