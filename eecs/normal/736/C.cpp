#include <bits/stdc++.h>
using namespace std;

const int maxn = 110, P = 1000000007;
int n, K, ans, dep[maxn];
int foo[maxn], bar[maxn], f[maxn][maxn], g[maxn][maxn];
vector<int> G[maxn];

void red(int &x) {
    x += x >> 31 & P;
}

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    function<void(int, int)> dfs = [&](int v, int fa) {
        dep[v] = dep[fa] + 1;
        f[v][dep[v]] = g[v][dep[v]] = 1;
        for (int u : G[v]) if (u ^ fa) {
            dfs(u, v);
            memset(foo, 0, sizeof(foo));
            memset(bar, 0, sizeof(bar));
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    // f, f
                    red(foo[min(i, j)] += 1LL * f[v][i] * f[u][j] % P - P);
                    // g, g
                    red(bar[max(i, j)] += 1LL * g[v][i] * g[u][j] % P - P);
                    // f, g
                    if (i + j - dep[v] * 2 <= K) red(foo[i] += 1LL * f[v][i] * g[u][j] % P - P);
                    else red(bar[j] += 1LL * f[v][i] * g[u][j] % P - P);
                    // g, f
                    if (i + j - dep[v] * 2 <= K) red(foo[j] += 1LL * g[v][i] * f[u][j] % P - P);
                    else red(bar[i] += 1LL * g[v][i] * f[u][j] % P - P);
                }
            }
            memcpy(f[v], foo, sizeof(foo));
            memcpy(g[v], bar, sizeof(bar));
        }
    };
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        red(ans += f[1][i] - P);
    }
    printf("%d\n", ans);
    return 0;
}