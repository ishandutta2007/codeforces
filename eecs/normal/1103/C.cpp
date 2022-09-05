#include <bits/stdc++.h>
using namespace std;

const int maxn = 250010;
int n, m, K, fa[maxn], dep[maxn], vis[maxn], son[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d %d %d", &n, &m, &K);
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    function<void(int)> dfs = [&](int v) {
        vis[v] = 1;
        for (int u : G[v]) if (!vis[u]) {
            fa[u] = v, dep[u] = dep[v] + 1;
            son[v]++, dfs(u);
        }
    };
    dfs(1);
    int lim = (n + K - 1) / K;
    for (int i = 1; i <= n; i++) if (dep[i] + 1 >= lim) {
        puts("PATH");
        printf("%d\n", dep[i] + 1);
        for (; i; i = fa[i]) printf("%d ", i);
        exit(0);
    }
    puts("CYCLES");
    for (int i = 1; i <= n; i++) if (!son[i]) {
        vector<int> V;
        for (int j : G[i]) if (j ^ fa[i]) {
            V.push_back(j);
        }
        assert(V.size() >= 2);
        int x = V[0], y = V[1];
        if (dep[x] < dep[y]) swap(x, y);
        if ((dep[i] - dep[x] + 1) % 3) {
            printf("%d\n", dep[i] - dep[x] + 1);
            for (int p = i; p ^ x; p = fa[p]) printf("%d ", p);
            printf("%d\n", x);
        } else if ((dep[i] - dep[y] + 1) % 3) {
            printf("%d\n", dep[i] - dep[y] + 1);
            for (int p = i; p ^ y; p = fa[p]) printf("%d ", p);
            printf("%d\n", y);
        } else {
            printf("%d\n", dep[x] - dep[y] + 2);
            printf("%d ", i);
            for (int p = x; p ^ y; p = fa[p]) printf("%d ", p);
            printf("%d\n", y);
        }
        if (!--K) break;
    }
    return 0;
}