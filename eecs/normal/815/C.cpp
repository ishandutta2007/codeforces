#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5010;
int n, b, ans, c[maxn], d[maxn], sz[maxn];
ll f[maxn][maxn][2], g[maxn][2];
vector<int> G[maxn];

int main() {
    scanf("%d %d", &n, &b);
    for (int i = 1, f; i <= n; i++) {
        scanf("%d %d", &c[i], &d[i]);
        if (i > 1) scanf("%d", &f), G[f].push_back(i);
    }
    function<void(int)> dfs = [&](int v) {
        f[v][0][0] = 0, f[v][1][0] = c[v];
        f[v][1][1] = c[v] - d[v], sz[v] = 1;
        for (int u : G[v]) {
            dfs(u);
            for (int i = 0; i <= sz[v] + sz[u]; i++) {
                g[i][0] = g[i][1] = 1e18;
            }
            for (int i = 0; i <= sz[v]; i++) for (int a : {0, 1}) {
                for (int j = 0; j <= sz[u]; j++) for (int b : {0, 1}) if (b <= a) {
                    g[i + j][a] = min(g[i + j][a], f[v][i][a] + f[u][j][b]);
                }
            }
            sz[v] += sz[u];
            for (int i = 0; i <= sz[v]; i++) {
                f[v][i][0] = g[i][0], f[v][i][1] = g[i][1];
            }
        }
    };
    memset(f, 0x3f, sizeof(f)), dfs(1);
    for (int i = n; i; i--) {
        if (min(f[1][i][0], f[1][i][1]) <= b) { ans = i; break; }
    }
    printf("%d\n", ans);
    return 0;
}