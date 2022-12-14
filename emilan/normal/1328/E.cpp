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

const int maxn = 2e5 + 1, maxk = 18;
int par[maxk][maxn];

void solve() {
    int n, m;
    cin >> n >> m;
    vt<vt<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vt<int> depth(n);
    function<void(int, int)> dfs = [&](int u, int p) {
        par[0][u] = p;
        for (int v : adj[u]) if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    };
    dfs(0, 0);

    for (int k = 1; k < maxk; k++) {
        for (int u = 0; u < n; u++) {
            par[k][u] = par[k - 1][ par[k - 1][u] ];
        }
    }

    while (m--) {
        int q;
        cin >> q;
        vt<int> nodes(q);
        for (int &i : nodes) {
            cin >> i;
            i--;
            i = par[0][i];
        }

        int deep = *max_element(all(nodes),
            [&](int x, int y) {
                return depth[x] < depth[y];
        });

        bool ok = true;
        for (int i : nodes) if (i != deep) {
            int j = depth[deep], v = deep;
            for (int k = maxk - 1; k >= 0; k--) {
                if (j - (1 << k) >= depth[i]) {
                    v = par[k][v];
                    j -= 1 << k;
                }
            }
            if (i != v) ok = false;
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}