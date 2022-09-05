#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010, P = 998244353;
int n, f[maxn][2][2], g[2][2], h[2][2];
vector<int> G[maxn];

inline void red(int &x) { x += x >> 31 & P; }

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    function<void(int, int)> dfs = [&](int v, int fa) {
        for (int u : G[v]) if (u ^ fa) dfs(u, v);
        memset(g, 0, sizeof(g)), g[0][0] = 1;
        for (int u : G[v]) if (u ^ fa) {
            memset(h, 0, sizeof(h));
            for (int p : {0, 1}) for (int q : {0, 1}) if (f[u][p][q]) {
                for (int x : {0, 1}) for (int y : {0, 1}) {
                    int t = 1LL * f[u][p][q] * g[x][y] % P;
                    if (!p) red(h[x][y] += t - P);
                    else if (q) red(h[1][y] += t - P);
                    else if (!y) red(h[1][1] += t - P);
                }
            }
            memcpy(g, h, sizeof(g));
        }
        f[v][0][0] = (g[0][0] + g[1][1]) % P;
        f[v][1][0] = (g[0][0] + g[1][0]) % P;
        f[v][1][1] = g[1][1];
    };
    dfs(1, 0), printf("%d\n", f[1][0][0]);
    return 0;
}