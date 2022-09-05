#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, ans, f[maxn], g[maxn], d[maxn];
vector<int> G[maxn];

void chk(int &x, int y) {
    if (x < y) x = y;
}

int main() {
    scanf("%d", &n);
    for (int _ = 1, u, v; _ < n; _++) {
        scanf("%d %d", &u, &v), d[u]++, d[v]++;
        G[u].push_back(v), G[v].push_back(u);
    }
    function<void(int, int)> dfs = [&](int v, int fa) {
        g[v] = 1;
        for (int u : G[v]) if (u ^ fa) {
            dfs(u, v);
            chk(ans, g[v] + f[u]);
            chk(ans, f[v] + g[u]);
            chk(ans, f[v] + f[u]);
            chk(f[v], f[u] + d[v] - 2);
            chk(f[v], g[u] + d[v] - 2);
            chk(g[v], f[u] + 1);
        }
    };
    dfs(1, 0), printf("%d\n", ans);
    return 0;
}