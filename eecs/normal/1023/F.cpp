#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010;
int n, K, m, jump[maxn], par[maxn], dep[maxn], fa[maxn][20], w[maxn];
vector<int> G[maxn];
set<pair<int, int>> S;
vector<tuple<int, int, int>> E;

int find(int x) {
    return x == jump[x] ? x : jump[x] = find(jump[x]);
}

int find2(int x) {
    return x == par[x] ? x : par[x] = find2(par[x]);
}

int main() {
    scanf("%d %d %d", &n, &K, &m);
    iota(par + 1, par + n + 1, 1);
    while (K--) {
        int u, v; scanf("%d %d", &u, &v);
        S.emplace(min(u, v), max(u, v));
        G[u].push_back(v), G[v].push_back(u);
        par[find2(u)] = find2(v);
    }
    while (m--) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        if (find2(u) == find2(v)) { E.emplace_back(w, u, v); continue; }
        G[u].push_back(v), G[v].push_back(u);
        par[find2(u)] = find2(v);
    }
    function<void(int)> dfs = [&](int v) {
        dep[v] = dep[fa[v][0]] + 1;
        for (int i = 1; 1 << i < dep[v]; i++) {
            fa[v][i] = fa[fa[v][i - 1]][i - 1];
        }
        for (int u : G[v]) if (u ^ fa[v][0]) {
            fa[u][0] = v, dfs(u);
        }
    };
    dfs(1);
    auto lca = [&](int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        for (int i = 19; ~i; i--) {
            if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
        }
        if (u == v) return u;
        for (int i = 19; ~i; i--) {
            if (fa[u][i] ^ fa[v][i]) u = fa[u][i], v = fa[v][i];
        }
        return fa[u][0];
    };
    iota(jump + 1, jump + n + 1, 1);
    for (auto e : E) {
        int u = get<1>(e), v = get<2>(e);
        int l = lca(u, v);
        for (int i = find(u); dep[i] > dep[l]; i = find(i)) {
            w[i] = get<0>(e), jump[i] = fa[i][0];
        }
        for (int i = find(v); dep[i] > dep[l]; i = find(i)) {
            w[i] = get<0>(e), jump[i] = fa[i][0];
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) if (fa[i][0] && S.count(make_pair(min(i, fa[i][0]), max(i, fa[i][0])))) {
        if (!w[i]) puts("-1"), exit(0);
        ans += w[i];
    }
    printf("%lld\n", ans);
    return 0;
}