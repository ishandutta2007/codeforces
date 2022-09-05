#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const int maxn = 55;
int n, rt, sz[maxn];
ld f[maxn][maxn], g[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    function<void(int, int)> dfs = [&](int v, int fa) {
        sz[v] = f[v][0] = 1;
        for (int u : G[v]) if (u ^ fa) {
            dfs(u, v), memset(g, 0, sizeof(g));
            for (int i = 0; i <= sz[v]; i++) {
                for (int j = 0; j <= sz[u]; j++) {
                    g[i + j + 1] += f[v][i] * f[u][j] / (j + 1) / 2;
                    if (v == rt) continue;
                    g[i + j + 1] -= f[v][i] * f[u][j];
                    g[i + j] += f[v][i] * f[u][j];
                }
            }
            sz[v] += sz[u], copy(g, g + sz[v] + 1, f[v]);
        }
    };
    for (rt = 1; rt <= n; rt++) {
        memset(f, 0, sizeof(f)), dfs(rt, 0);
        printf("%.10Lf\n", accumulate(f[rt], f[rt] + n + 1, (ld)0));
    }
    return 0;
}