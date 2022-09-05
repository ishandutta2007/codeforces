#include <bits/stdc++.h>
using namespace std;

const int maxn = 5010, P = 998244353;
int n, K, ans, sz[maxn], f[maxn][maxn], g[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d %d", &n, &K);
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
                    if (i + j > K) continue;
                    g[max(i, j)] = (g[max(i, j)] + 1LL * f[v][i] * f[u][j]) % P;
                }
            }
            swap(f[v], g), sz[v] += sz[u];
        }
        if (fa) {
            memset(g, 0, sizeof(g));
            for (int i = 0; i <= sz[v]; i++) {
                (g[0] += f[v][i]) %= P;
                (g[i + 1] += f[v][i]) %= P;
            }
            swap(f[v], g);
        }
    };
    dfs(1, 0);
    for (int i = 0; i <= K; i++) {
        (ans += f[1][i]) %= P;
    }
    printf("%d\n", ans);
    return 0;
}