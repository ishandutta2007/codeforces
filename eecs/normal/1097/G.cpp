#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, P = 1000000007;
int n, K, ans, sz[maxn], f[maxn][210][2], g[210][2][2], h[210][2][2], S2[210][210];
vector<int> G[maxn];

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    for (int i = S2[0][0] = 1; i <= K; i++) {
        for (int j = 1; j <= i; j++) {
            S2[i][j] = (S2[i - 1][j - 1] + 1LL * j * S2[i - 1][j]) % P;
        }
    }
    function<void(int, int)> dfs = [&](int v, int fa) {
        sz[v] = 1;
        for (int u : G[v]) if (u ^ fa) {
            dfs(u, v), sz[v] += sz[u];
        }
        memset(g, 0, sizeof(g)), g[0][1][0] = 1;
        int cur = 0;
        for (int u : G[v]) if (u ^ fa) {
            memcpy(h, g, sizeof(h)), memset(g, 0, sizeof(g));
            for (int i = 0; i <= min(cur, K); i++) {
                for (int p : {0, 1}) for (int t : {0, 1}) if (h[i][p][t]) {
                    g[i][p][t] = (g[i][p][t] + h[i][p][t]) % P;
                    for (int j = 0; j <= min(sz[u], K - i); j++) for (int q : {0, 1}) {
                        g[i + j][q | t][1] = (g[i + j][q | t][1] + 1LL * h[i][p][t] * f[u][j][q]) % P;
                    }
                }
            }
            cur += sz[u];
        }
        for (int i = 0; i <= K; i++) {
            for (int j : {0, 1}) for (int k : {0, 1}) if (g[i][j][k]) {
                f[v][i][1] = (f[v][i][1] + g[i][j][k]) % P;
                if (i < K) f[v][i + 1][0] = (f[v][i + 1][0] + g[i][j][k]) % P;
                f[v][i][j] = (f[v][i][j] + g[i][j][k]) % P;
                if (i < K) f[v][i + 1][0] = (f[v][i + 1][0] + g[i][j][k]) % P;
            }
        }
        (f[v][0][1] += P - 1) %= P;
        (f[v][1][0] += P - 1) %= P;
    };
    dfs(1, 0);
    for (int i = 1, j = 1; i <= K; i++) {
        j = 1LL * i * j % P;
        ans = (ans + 1LL * f[1][i][1] * S2[K][i] % P * j) % P;
    }
    printf("%d\n", ans);
    return 0;
}