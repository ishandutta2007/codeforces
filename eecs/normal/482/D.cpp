#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, P = 1000000007;
int n, f[maxn][2], g[maxn][2][2];
vector<int> G[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 2, p; i <= n; i++) {
        scanf("%d", &p), G[p].push_back(i);
    }
    function<void(int)> dfs = [&](int v) {
        for (int u : G[v]) dfs(u);
        g[v][0][0] = g[v][0][1] = f[v][1] = 1;
        for (int u : G[v]) {
            int foo = (1LL * f[v][0] * f[u][1] + 1LL * f[v][1] * f[u][0]) % P;
            int bar = (1LL * f[v][0] * f[u][0] + 1LL * f[v][1] * f[u][1]) % P;
            (f[v][0] += bar) %= P, (f[v][1] += foo) %= P;
            g[v][0][0] = (g[v][0][0] + 1LL * g[v][0][0] * f[u][0]) % P;
            int x = g[v][0][1], y = g[v][1][1];
            g[v][0][1] = (g[v][0][1] + 1LL * y * f[u][1]) % P;
            g[v][1][1] = (g[v][1][1] + 1LL * x * f[u][1]) % P;
        }
        f[v][0] = (2LL * f[v][0] - g[v][1][1] + P) % P;
        f[v][1] = (2LL * f[v][1] - g[v][0][0] + P) % P;
    };
    dfs(1), printf("%d\n", (f[1][0] + f[1][1]) % P);
    return 0;
}