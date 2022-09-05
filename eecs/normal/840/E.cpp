#include <bits/stdc++.h>
using namespace std;

const int maxn = 50010, SZ = 256;
int n, q, a[maxn], fa[maxn], dep[maxn], jump[maxn], f[maxn][SZ];
vector<int> G[maxn];

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    function<void(int)> dfs = [&](int v) {
        dep[v] = dep[fa[v]] + 1;
        for (int u : G[v]) if (u ^ fa[v]) {
            fa[u] = v, dfs(u);
        }
        if (dep[v] >= SZ) {
            int u = v;
            for (int i = 0; i < SZ; i++, u = fa[u]) {
                int x = ((i ^ a[u]) >> 8) ^ 255;
                f[v][x] = max(f[v][x], (255 << 8) | (i ^ a[u]));
            }
            jump[v] = u;
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < SZ; j++) {
                    f[v][j] = max(f[v][j], f[v][j ^ (1 << i)] - (SZ << i));
                }
            }
        }
    };
    dfs(1);
    while (q--) {
        int u, v;
        scanf("%d %d", &u, &v);
        int d = dep[v] - dep[u] + 1, ans = 0;
        for (int i = 0; i < d / SZ; i++, v = jump[v]) ans = max(ans, f[v][i]);
        for (int i = d / SZ * SZ; i < d; i++, v = fa[v]) ans = max(ans, i ^ a[v]);
        printf("%d\n", ans);
    }
    return 0;
}