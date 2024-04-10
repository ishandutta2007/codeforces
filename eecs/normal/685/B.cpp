#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, q, dep[maxn], sz[maxn], ans[maxn], par[maxn], fa[maxn][20];
vector<int> G[maxn];

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 2, p; i <= n; i++) {
        scanf("%d", &p), G[p].push_back(i);
    }
    iota(par, par + n + 1, 0);
    function<void(int)> dfs1 = [&](int v) {
        sz[v] = 1, dep[v] = dep[fa[v][0]] + 1;
        for (int i = 1; 1 << i < dep[v]; i++) {
            fa[v][i] = fa[fa[v][i - 1]][i - 1];
        }
        for (int u : G[v]) if (u ^ fa[v][0]) {
            fa[u][0] = v, dfs1(u), sz[v] += sz[u];
        }
    };
    function<void(int)> dfs2 = [&](int v) {
        int mx = 0;
        for (int u : G[v]) if (u ^ fa[v][0]) {
            mx = max(mx, sz[u]);
        }
        int l = 2 * mx, r = 2 * sz[v];
        int v1 = v, v2 = v;
        for (int i = 19; ~i; i--) {
            if (fa[v1][i] && sz[fa[v1][i]] < l) v1 = fa[v1][i];
            if (fa[v2][i] && sz[fa[v2][i]] <= r) v2 = fa[v2][i];
        }
        if (sz[v1] < l) v1 = fa[v1][0];
        if (sz[v1] >= l && sz[v2] <= r && dep[v1] >= dep[v2]) {
            for (int i = find(v1); dep[i] >= dep[v2]; i = find(i)) {
                ans[i] = v, par[i] = fa[i][0];
            }
        }
        for (int u : G[v]) if (u ^ fa[v][0]) {
            dfs2(u);
        }
    };
    dfs1(1), dfs2(1);
    while (q--) {
        int v; scanf("%d", &v);
        printf("%d\n", ans[v]);
    }
    return 0;
}