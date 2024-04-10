#include <bits/stdc++.h>
using namespace std;

const int maxn = 4010, P = 998244353;
int K, ans, binom[80][80];

struct Tree {
    int n, u[maxn], v[maxn], f[80][maxn], g[80][maxn], h[80][maxn], tmp1[80][maxn], tmp2[80][maxn], ans[80];

    void solve() {
        for (int i = 1; i < n; i++) {
            scanf("%d %d", &u[i], &v[i]);
        }
        for (int i = 1; i <= n; i++) {
            f[0][i] = g[0][i] = h[0][i] = 1;
            tmp1[0][i] = tmp2[0][i] = 1;
        }
        ans[0] = n;
        for (int k = 2; k <= K; k++) if (!(k & 1)) {
            for (int i = 1; i < n; i++) {
                for (int j = 0; j <= k - 2; j += 2) {
                    f[k][u[i]] = (f[k][u[i]] + 1LL * h[j][i] * f[k - j - 2][u[i]]) % P;
                    tmp1[k][i] = (tmp1[k][i] + 1LL * h[j][i] * f[k - j - 2][u[i]]) % P;
                    f[k][v[i]] = (f[k][v[i]] + 1LL * g[j][i] * f[k - j - 2][v[i]]) % P;
                    tmp2[k][i] = (tmp2[k][i] + 1LL * g[j][i] * f[k - j - 2][v[i]]) % P;
                }
            }
            for (int i = 1; i <= n; i++) {
                (ans[k] += f[k][i]) %= P;
            }
            for (int i = 1; i < n; i++) {
                g[k][i] = f[k][u[i]], h[k][i] = f[k][v[i]];
                for (int j = 0; j <= k - 2; j += 2) {
                    g[k][i] = (g[k][i] - 1LL * g[j][i] * tmp1[k - j][i] % P + P) % P;
                    h[k][i] = (h[k][i] - 1LL * h[j][i] * tmp2[k - j][i] % P + P) % P;
                    /* for (int $ = 0; $ <= k - j - 2; $ += 2) {
                        g[k][i] = (g[k][i] - 1LL * g[j][i] * h[$][i] % P * f[k - j - $ - 2][u[i]] % P + P) % P;
                        h[k][i] = (h[k][i] - 1LL * h[j][i] * g[$][i] % P * f[k - j - $ - 2][v[i]] % P + P) % P;
                    } */
                }
            }
        }
    }
} T1, T2;

int main() {
    scanf("%d %d %d", &T1.n, &T2.n, &K);
    T1.solve(), T2.solve();
    for (int i = 0; i <= K; i++) {
        for (int j = binom[i][0] = 1; j <= i; j++) {
            binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % P;
        }
    }
    for (int i = 0; i <= K; i++) {
        ans = (ans + 1LL * binom[K][i] * T1.ans[i] % P * T2.ans[K - i]) % P;
    }
    printf("%d\n", ans);
    return 0;
}