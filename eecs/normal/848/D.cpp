#include <bits/stdc++.h>
using namespace std;

const int maxn = 55, P = 1000000007;
int n, m, ans, inv[maxn], f[maxn][maxn], g[maxn][maxn], h[maxn][maxn][maxn];

void red(int &x) {
    x += x >> 31 & P;
}

int main() {
    scanf("%d %d", &n, &m);
    f[0][0] = inv[0] = inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        inv[i] = 1LL * (P - P / i) * inv[P % i] % P;
    }
    for (int i = 1; i <= n; i++) {
        memset(g, 0, sizeof(g)), g[0][0] = 1;
        for (int j = 1; j < i; j++) {
            for (int a = i - j; ~a; a--) {
                for (int b = a; ~b; b--) if (g[a][b]) {
                    for (int c = j; a + c <= i; c += j) {
                        for (int d = 0; b + d <= i && d <= c; d++) {
                            red(g[a + c][b + d] += 1LL * g[a][b] * h[j][c][d] % P - P);
                        }
                    }
                }
            }
        }
        for (int j = 0; j < i; j++) {
            for (int a = 0; a <= j; a++) {
                for (int b = 0; b <= i - j - 1; b++) {
                    red(f[i][min(a, b) + 1] += 1LL * f[j][a] * f[i - j - 1][b] % P - P);
                }
            }
        }
        h[i][0][0] = 1;
        for (int j = 1; j <= i; j++) if (f[i][j]) {
            for (int a = n; ~a; a--) {
                for (int b = a; ~b; b--) if (h[i][a][b]) {
                    int pw = 1, d = 0;
                    for (int c = i; a + c <= n; c += i, d++) {
                        pw = 1LL * pw * (f[i][j] + d) % P * inv[d + 1] % P;
                        red(h[i][a + c][b + c / i * j] += 1LL * h[i][a][b] * pw % P - P);
                    }
                }
            }
        }
        for (int j = 1; j <= i; j++) {
            red(f[i][j] += g[i][j] - P);
        }
    }
    printf("%d\n", f[n][m - 1]);
    return 0;
}