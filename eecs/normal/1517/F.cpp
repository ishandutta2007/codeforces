#include <bits/stdc++.h>
using namespace std;

const int maxn = 310, P = 998244353;
int n, ans, R, dep[maxn], prob[maxn], h[maxn];
int f[maxn][maxn], g[maxn][maxn], foo[maxn], bar[maxn];
vector<int> G[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

inline void red(int &x) {
    x -= P, x += x >> 31 & P;
}

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    function<void(int, int)> dfs = [&](int v, int fa) {
        dep[v] = dep[fa] + 1;
        h[v] = 0, f[v][0] = g[v][0] = 1;
        for (int u : G[v]) if (u ^ fa) {
            dfs(u, v);
            copy(f[v], f[v] + h[v] + 1, foo), fill(f[v], f[v] + h[v] + 1, 0);
            copy(g[v], g[v] + h[v] + 1, bar), fill(g[v], g[v] + h[v] + 1, 0);
            for (int i = 0; i <= h[v]; i++) {
                for (int j = 0; j <= h[u]; j++) {
                    red(f[v][max(i, j + 1)] += 1LL * foo[i] * f[u][j] % P);
                    red(g[v][min(i, j + 1)] += 1LL * bar[i] * g[u][j] % P);
                    if (i + j + 1 <= R) {
                        red(g[v][j + 1] += 1LL * foo[i] * g[u][j] % P);
                        red(g[v][i] += 1LL * bar[i] * f[u][j] % P);
                    } else {
                        red(f[v][i] += 1LL * foo[i] * g[u][j] % P);
                        red(f[v][j + 1] += 1LL * bar[i] * f[u][j] % P);
                    }
                }
            }
            h[v] = max(h[v], h[u] + 1);
        }
    };
    for (int r = 0; r <= n; r++) {
        memset(f, 0, sizeof(f)), memset(g, 0, sizeof(g));
        R = r + 1, dfs(1, 0);
        for (int i = 0; i <= h[1]; i++) red(prob[r] += g[1][i]);
    }
    for (int r = 0; r <= n; r++) {
        red(ans += 1LL * r * (prob[r] - (r ? prob[r - 1] : 0) + P) % P);
    }
    printf("%lld\n", 1LL * (ans + n - 1) * qp(2, P - 1 - n) % P);
    return 0;
}