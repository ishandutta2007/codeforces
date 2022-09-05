#include <bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7;
int n, ans, a[14], f[1 << 14], inv[2000010], prob[14][1 << 14];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= 2000000; i++) {
        inv[i] = qp(i, P - 2);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 1 << n; j++) if (!(j >> i & 1)) {
            prob[i][j] = 1;
            for (int k = 0; k < n; k++) if (j >> k & 1) {
                prob[i][j] = 1LL * prob[i][j] * a[i] % P * inv[a[i] + a[k]] % P;
            }
        }
    }
    for (int i = 1; i < 1 << n; i++) {
        f[i] = 1;
        for (int j = 0; j < n; j++) if (i >> j & 1) {
            f[i] = 1LL * f[i] * prob[j][((1 << n) - 1) ^ i] % P;
        }
        for (int j = i & (i - 1); j; j = (j - 1) & i) {
            int coef = 1;
            for (int k = 0; k < n; k++) if (!(j >> k & 1) && (i >> k & 1)) {
                coef = 1LL * coef * prob[k][((1 << n) - 1) ^ i] % P;
            }
            f[i] = (f[i] - 1LL * coef * f[j] % P + P) % P;
        }
        ans = (ans + 1LL * f[i] * __builtin_popcount(i)) % P;
    }
    printf("%d\n", ans);
    return 0;
}