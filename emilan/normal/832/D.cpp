#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

const int kK = 20;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> par(n);
    vector<vector<int>> chi(n);
    for (int v = 1; v < n; v++) {
        int u;
        cin >> u;
        u--;
        par[v] = u;
        chi[u].push_back(v);
    }

    array<vector<int>, kK> spt;
    spt[0] = par;
    for (int k = 0; k < kK - 1; k++) {
        spt[k + 1].resize(n);
        for (int u = 0; u < n; u++) {
            spt[k + 1][u] = spt[k][spt[k][u]];
        }
    }

    vector<int> depth(n);
    auto dfs = [&](auto &self, int u) -> void {
        for (int v : chi[u]) {
            depth[v] = depth[u] + 1;
            self(self, v);
        }
    };
    dfs(dfs, 0);

    auto lca = [&](int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        for (int d = depth[u] - depth[v], k = 0; 1 << k <= d; k++) {
            if (d >> k & 1) u = spt[k][u];
        }

        if (u != v) {
            for (int k = __lg(depth[u]); k >= 0; k--) {
                int pu = spt[k][u];
                int pv = spt[k][v];
                if (pu != pv) u = pu, v = pv;
            }
            u = par[u];
        }
        return u;
    };

    while (q--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--, w--;

        int l_uv = lca(u, v);
        int l_uw = lca(u, w);
        int l_vw = lca(v, w);
        int l_uvw = lca(l_uv, w);

        int ans = max({
            depth[u] - max(depth[l_uv], depth[l_uw])
                + max(depth[l_vw] - depth[l_uvw], 0),
            depth[v] - max(depth[l_uv], depth[l_vw])
                + max(depth[l_uw] - depth[l_uvw], 0),
            depth[w] - max(depth[l_uw], depth[l_vw])
                + max(depth[l_uv] - depth[l_uvw], 0),
        }) + 1;
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}