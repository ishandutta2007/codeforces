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
    int n, m;
    cin >> n >> m;
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vt<vt<int>> adj(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vt<int> color(n, -1);
    vt<vt<vt<int>>> comp;
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (~color[i]) continue;

        vt<vt<int>> cur_comp(2);

        auto dfs = [&](int u, auto &f) -> void {
            cur_comp[color[u]].push_back(u);

            for (int v : adj[u]) {
                if (color[v] == color[u]) {
                    cout << "NO";
                    exit(0);
                } else if (!~color[v]) {
                    color[v] = color[u] ^ 1;
                    f(v, f);
                }
            }
        };

        color[i] = 0;
        dfs(i, dfs);

        if (sz(cur_comp[0]) > sz(cur_comp[1])) {
            swap(cur_comp[0], cur_comp[1]);
        }
        s += sz(cur_comp[0]);
        comp.push_back(cur_comp);
    }
    m = sz(comp);

    vt<int> dp(n2 + 1, -1), par(n2 + 1);
    if (s <= n2) dp[s] = -2;
    for (int i = 0; i < m; i++) {
        int w = sz(comp[i][1]) - sz(comp[i][0]);
        if (!w) continue;

        for (int j = n2 - w; j >= s; j--) if (~dp[j] && !~dp[j + w]) {
            dp[j + w] = i;
            par[j + w] = j;
        }
    }

    if (!~dp[n2]) {
        cout << "NO";
    } else {
        cout << "YES\n";

        vt<int> ans(n);
        vt<bool> f(m);
        for (int i = n2; i != s; i = par[i]) {
            f[dp[i]] = true;
        }

        for (int i = 0; i < m; i++) {
            for (int u : comp[i][0]) {
                ans[u] = f[i] ? 1 : 2;
            }

            for (int u : comp[i][1]) {
                ans[u] = f[i] ? 2 : 1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (ans[i] == 1 && n3 > 0) {
                ans[i] = 3;
                n3--;
            }
        }

        for (int x : ans) cout << x;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}