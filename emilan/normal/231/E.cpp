#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

pair<int, vector<int>>
two_ecc(int n, const vector<pair<int, int>> &edges) {
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < int(size(edges)); i++) {
        auto [u, v] = edges[i];
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }

    vector<int> tin(n, -1), low(n);
    int t = 0;
    stack<int> st;
    vector<int> ecc_id(n, -1);
    int ecc_cnt = 0;
    auto dfs = [&](auto &self, int u, int pi) -> void {
        tin[u] = low[u] = t++;
        st.push(u);
        for (auto [v, i] : adj[u]) if (i != pi) {
            if (tin[v] == -1) self(self, v, i);
            low[u] = min(low[u], low[v]);
        }

        if (low[u] == tin[u]) {
            int v;
            do {
                v = st.top();
                st.pop();
                ecc_id[v] = ecc_cnt;
            } while (v != u);
            ecc_cnt++;
        }
    };
    for (int s = 0; s < n; s++) if (tin[s] == -1) {
        dfs(dfs, s, -1);
    }

    return {ecc_cnt, ecc_id};
}

const ll kMod = 1e9 + 7;

ll mod_pow(ll b, int e) {
    ll r = 1;
    for (; e > 0; e /= 2, b = b * b % kMod) {
        if (e & 1) r = r * b % kMod;
    }
    return r;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pii> edges(m);
    for (auto &[u, v] : edges) {
        cin >> u >> v;
        u--, v--;
    }

    auto [ecc_cnt, ecc_id] = two_ecc(n, edges);

    vector<int> sz(ecc_cnt);
    for (int u = 0; u < n; u++) {
        sz[ecc_id[u]]++;
    }

    vector<vector<int>> adj(ecc_cnt);
    for (auto [u_, v_] : edges) {
        int u = ecc_id[u_];
        int v = ecc_id[v_];
        if (u != v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    vector<int> par(ecc_cnt);
    vector<int> depth(ecc_cnt);
    vector<int> dp(ecc_cnt);
    auto dfs = [&](auto &self, int u) -> void {
        if (sz[u] >= 3) dp[u]++;
        for (int v : adj[u]) if (v != par[u]) {
            par[v] = u;
            depth[v] = depth[u] + 1;
            dp[v] = dp[u];
            self(self, v);
        }
    };
    dfs(dfs, 0);

    array<vector<int>, 20> jmp;
    jmp[0] = par;
    for (int i = 0; (1 << (i + 1)) - 1 < n - 1; i++) {
        jmp[i + 1].resize(ecc_cnt);
        for (int u = 0; u < ecc_cnt; u++) {
            jmp[i + 1][u] = jmp[i][jmp[i][u]];
        }
    }

    auto lca = [&](int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        for (int d = depth[u] - depth[v], i = __lg(d | 1); i >= 0; i--) {
            if (d >> i & 1) u = jmp[i][u];
        }

        if (u == v) return u;

        for (int i = __lg(depth[u] | 1); i >= 0; i--) {
            int pu = jmp[i][u];
            int pv = jmp[i][v];
            if (pu != pv) u = pu, v = pv;
        }
        return jmp[0][u];
    };

    int q;
    cin >> q;
    while (q--) {
        int u_, v_;
        cin >> u_ >> v_;
        u_--, v_--;
        int u = ecc_id[u_];
        int v = ecc_id[v_];

        int p = lca(u, v);

        auto ans = mod_pow(2, dp[u] + dp[v] - 2 * dp[p] + (sz[p] >= 3));
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}