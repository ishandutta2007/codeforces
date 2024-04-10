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

struct Dsu {
    vector<int> p;

    Dsu(int n) : p(n, -1) {}

    int root(int u) { return p[u] < 0 ? u : p[u] = root(p[u]); }

    bool combine(int u, int v) {
        u = root(u);
        v = root(v);
        if (u == v) return false;

        if (p[u] > p[v]) swap(u, v);
        p[u] += p[v];
        p[v] = u;
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 4>> edges(m);
    for (auto &[w, u, v, i_] : edges) {
        static int i = 0;
        cin >> u >> v >> w;
        u--, v--;
        i_ = i++;
    }
    sort(ALL(edges));

    ll mst_wei = 0;
    vector<vector<pii>> adj(n);

    Dsu dsu(n);
    for (auto [w, u, v, i_] : edges) {
        if (dsu.combine(u, v)) {
            mst_wei += w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
    }

    vector<int> par(n);
    vector<int> par_wei(n);
    vector<int> depth(n);
    auto dfs = [&](auto &self, int u) -> void {
        for (auto [v, w] : adj[u]) if (v != par[u]) {
            par[v] = u;
            par_wei[v] = w;
            depth[v] = depth[u] + 1;
            self(self, v);
        }
    };
    dfs(dfs, 0);

    array<vector<int>, kK> jmp;
    array<vector<int>, kK> jmp_path;
    jmp[0] = par;
    jmp_path[0] = par_wei;
    for (int k = 0; k < kK - 1; k++) {
        jmp[k + 1].resize(n);
        jmp_path[k + 1].resize(n);
        for (int u = 0; u < n; u++) {
            int p = jmp[k][u];
            jmp[k + 1][u] = jmp[k][p];
            jmp_path[k + 1][u] = max(jmp_path[k][u], jmp_path[k][p]);
        }
    }

    auto query = [&](int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int path = 0;

        for (int d = depth[u] - depth[v], k = __lg(d | 1); k >= 0; k--) {
            if (d >> k & 1) {
                path = max(path, jmp_path[k][u]);
                u = jmp[k][u];
            }
        }

        if (u != v) {
            for (int k = __lg(depth[u]); k >= 0; k--) {
                int pu = jmp[k][u];
                int pv = jmp[k][v];
                if (pu != pv) {
                    path = max({path, jmp_path[k][u], jmp_path[k][v]});
                    u = pu, v = pv;
                }
            }
            path = max({path, par_wei[u], par_wei[v]});
        }

        return path;
    };

    vector<ll> ans(m);
    for (auto [w, u, v, i_] : edges) {
        auto path = query(u, v);
        ans[i_] = mst_wei + w - path;
    }

    for (auto x : ans) cout << x << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}