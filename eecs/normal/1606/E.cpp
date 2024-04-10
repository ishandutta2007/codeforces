#include <bits/stdc++.h>
using namespace std;

const int maxn = 510, P = 998244353;
int n, x, f[maxn][maxn], binom[maxn][maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d %d", &n, &x);
    for (int i = 0; i <= n; i++) {
        for (int j = binom[i][0] = 1; j <= i; j++) {
            binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % P;
        }
    }
    iota(f[1] + 1, f[1] + x + 1, 1);
    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= x; j++) {
            for (int k = 0; k < i; k++) {
                f[i][j] = (f[i][j] + 1LL * binom[i][k] * qp(i - 1, k) % P *
                    f[i - k][j - i + 1]) % P;
            }
        }
    }
    printf("%d\n", (qp(x, n) - f[n][x] + P) % P);
    return 0;
}