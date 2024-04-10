#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, m, ans, fa[maxn], dep[maxn];
int tim, tid[maxn], sz[maxn], mx[maxn], cnt[maxn], cur[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &fa[i]), G[fa[i]].push_back(i);
    }
    function<void(int)> init = [&](int u) {
        tid[u] = ++tim, dep[u] = dep[fa[u]] + (sz[u] = 1);
        for (int v : G[u]) init(v), sz[u] += sz[v];
    };
    init(1);
    vector<array<int, 2>> cross;
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u == fa[v] || v == fa[u]) puts("-1"), exit(0);
        if (tid[v] <= tid[u] && tid[u] < tid[v] + sz[v]) mx[u] = max(mx[u], dep[v]);
        else if (tid[u] <= tid[v] && tid[v] < tid[u] + sz[u]) mx[v] = max(mx[v], dep[u]);
        else cross.push_back({u, v});
    }
    function<void(int)> dfs = [&](int u) {
        for (int v : G[u]) {
            dfs(v), cnt[u] += cnt[v];
        }
        for (int v : G[u]) {
            if (cnt[u] == cnt[v]) cur[u] = max(cur[u], cur[v]);
        }
        if (u > 1 && cur[u] == dep[u] - 1) cnt[u]++, ans++, cur[u] = 0;
        if (mx[u]) cur[u] = max(cur[u], mx[u]);
    };
    dfs(1);
    for (auto &p : cross) {
        if (cnt[p[0]] + cnt[p[1]] == ans) { ans++; break; }
    }
    printf("%d\n", ans);
    return 0;
}