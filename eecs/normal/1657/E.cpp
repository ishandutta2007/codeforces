#include <bits/stdc++.h>
using namespace std;

const int maxn = 255, P = 998244353;
int n, K, binom[maxn][maxn], f[maxn][maxn], pw[maxn][maxn * maxn];

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 0; i <= n; i++) {
        for (int j = binom[i][0] = 1; j <= i; j++) {
            binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % P;
        }
    }
    for (int i = 0; i <= K; i++) {
        for (int j = pw[i][0] = 1; j <= n * n; j++) {
            pw[i][j] = 1LL * i * pw[i][j - 1] % P;
        }
    }
    f[0][1] = 1;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; j + k <= n; k++) {
                f[i + 1][j + k] = (f[i + 1][j + k] + 1LL * f[i][j] * binom[n - j][k] % P
                    * pw[K - i][k * (k - 1) / 2 + k * (j - 1)]) % P;
            }
        }
    }
    printf("%d\n", f[K][n]);
    return 0;
}