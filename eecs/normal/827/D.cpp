#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, dep[maxn], par[maxn], low[maxn], fa[maxn][20], mx[maxn][20];
bool mark[maxn];
vector<tuple<int, int, int>> G[maxn];
vector<tuple<int, int, int, int>> E;
struct edge { int u, v, c; } e[maxn];

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1, u, v, c; i <= m; i++) {
        scanf("%d %d %d", &u, &v, &c);
        e[i] = (edge){u, v, c};
        G[u].emplace_back(v, c, i), G[v].emplace_back(u, c, i);
        E.emplace_back(c, u, v, i);
    }
    sort(E.begin(), E.end());
    iota(par + 1, par + n + 1, 1);
    int cnt = 0;
    for (auto e : E) if (find(get<1>(e)) ^ find(get<2>(e))) {
        par[find(get<1>(e))] = find(get<2>(e));
        cnt++, mark[get<3>(e)] = 1;
    }
    function<void(int)> dfs = [&](int v) {
        dep[v] = dep[fa[v][0]] + 1;
        for (int i = 1; 1 << i < dep[v]; i++) {
            fa[v][i] = fa[fa[v][i - 1]][i - 1];
            mx[v][i] = max(mx[v][i - 1], mx[fa[v][i - 1]][i - 1]);
        }
        for (auto e : G[v]) {
            int u = get<0>(e);
            if (u == fa[v][0] || !mark[get<2>(e)]) continue;
            fa[u][0] = v, mx[u][0] = get<1>(e), dfs(u);
        }
    };
    dfs(1);
    if (cnt < n - 1) {
        for (int i = 1; i <= m; i++) printf("-1 ");
        exit(0);
    }
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
    auto calc = [&](int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        int ans = 0;
        for (int i = 19; ~i; i--) if (dep[fa[u][i]] >= dep[v]) {
            ans = max(ans, mx[u][i]), u = fa[u][i];
        }
        if (u == v) return ans;
        for (int i = 19; ~i; i--) if (fa[u][i] ^ fa[v][i]) {
            ans = max({ans, mx[u][i], mx[v][i]});
            u = fa[u][i], v = fa[v][i];
        }
        return max({ans, mx[u][0], mx[v][0]});
    };
    iota(par + 1, par + n + 1, 1);
    for (auto e : E) if (!mark[get<3>(e)]) {
        int u = get<1>(e), v = get<2>(e), l = lca(u, v);
        for (int i = find(u); dep[i] > dep[l]; i = find(i)) {
            low[i] = get<0>(e), par[i] = fa[i][0];
        }
        for (int i = find(v); dep[i] > dep[l]; i = find(i)) {
            low[i] = get<0>(e), par[i] = fa[i][0];
        }
    }
    for (int i = 1; i <= m; i++) {
        if (!mark[i]) {
            printf("%d ", calc(e[i].u, e[i].v) - 1);
        } else {
            if (dep[e[i].u] < dep[e[i].v]) swap(e[i].u, e[i].v);
            printf("%d ", !low[e[i].u] ? -1 : (low[e[i].u] - 1));
        }
    }
    return 0;
}