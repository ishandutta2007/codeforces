#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, q, tim, dfn[maxn], low[maxn], bel[maxn];
int fa[maxn], dir[maxn], dep[maxn], par[maxn][20];
bool ban[maxn];
vector<array<int, 2>> G[maxn];
vector<int> H[maxn];

struct DSU {
    int fa[maxn];
    DSU() { iota(fa, fa + maxn, 0); }

    int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
    void unite(int x, int y) { fa[find(x)] = find(y); }
} T1, T2, T3;

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1, u, v; i <= m; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back({v, i}), G[v].push_back({u, i});
    }
    function<void(int, int)> dfs1 = [&](int u, int id) {
        dfn[u] = low[u] = ++tim;
        for (auto &e : G[u]) {
            if (!dfn[e[0]]) {
                dfs1(e[0], e[1]), low[u] = min(low[u], low[e[0]]);
                if (low[e[0]] > dfn[u]) ban[e[1]] = 1;
            } else if (e[1] ^ id) {
                low[u] = min(low[u], dfn[e[0]]);
            }
        }
    };
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) dfs1(i, 0);
    }
    function<void(int)> dfs2 = [&](int u) {
        bel[u] = tim;
        for (auto &e : G[u]) {
            if (!bel[e[0]] && !ban[e[1]]) dfs2(e[0]);
        }
    };
    tim = 0;
    for (int i = 1; i <= n; i++) {
        if (!bel[i]) tim++, dfs2(i);
    }
    for (int i = 1; i <= n; i++) {
        for (auto &e : G[i]) {
            if (ban[e[1]]) H[bel[i]].push_back(bel[e[0]]);
        }
    }
    function<void(int)> dfs3 = [&](int u) {
        dep[u] = dep[par[u][0] = fa[u]] + 1;
        for (int i = 1; 1 << i < dep[u]; i++) {
            par[u][i] = par[par[u][i - 1]][i - 1];
        }
        for (int v : H[u]) if (v ^ fa[u]) {
            fa[v] = u, T3.unite(u, v), dfs3(v);
        }
    };
    for (int i = 1; i <= tim; i++) {
        if (!fa[i]) dfs3(i);
    }
    auto lca = [&](int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        for (int i = 19; ~i; i--) {
            if (dep[par[u][i]] >= dep[v]) u = par[u][i];
        }
        if (u == v) return u;
        for (int i = 19; ~i; i--) {
            if (par[u][i] ^ par[v][i]) u = par[u][i], v = par[v][i];
        }
        return fa[u];
    };
    while (q--) {
        int u, v;
        scanf("%d %d", &u, &v);
        u = bel[u], v = bel[v];
        if (T3.find(u) ^ T3.find(v)) puts("No"), exit(0);
        int l = lca(u, v);
        for (u = T1.find(u); dep[u] > dep[l]; u = T1.find(u)) {
            if (dir[u] == 2) puts("No"), exit(0);
            dir[u] = 1, T1.unite(u, fa[u]);
        }
        for (v = T2.find(v); dep[v] > dep[l]; v = T2.find(v)) {
            if (dir[v] == 1) puts("No"), exit(0);
            dir[v] = 2, T2.unite(v, fa[v]);
        }
    }
    puts("Yes");
    return 0;
}