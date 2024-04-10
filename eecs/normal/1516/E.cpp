#include <bits/stdc++.h>
using namespace std;

const int maxk = 410, P = 1000000007;
int n, K, f[maxk][maxk], binom[maxk][maxk], ans[maxk], fact[maxk], inv[maxk];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d %d", &n, &K);
    for (int i = fact[0] = binom[0][0] = 1; i <= 2 * K; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
        inv[i] = qp(i, P - 2);
        for (int j = binom[i][0] = 1; j <= i; j++) {
            binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % P;
        }
    }
    for (int i = 0; i <= 2 * K; i++) {
        f[i][0] = 1;
    }
    for (int i = 2; i <= 2 * K; i++) {
        for (int j = 1; j <= 2 * K; j++) {
            for (int k = 1; k <= min(i, j + 1); k++) {
                f[i][j] = (f[i][j] + 1LL * f[i - k][j - k + 1] * binom[i - 1][k - 1] % P * fact[k - 1]) % P;
            }
        }
    }
    for (int i = 0; i <= K; i++) {
        for (int j = 0; j <= 2 * i; j++) {
            int prod = 1;
            for (int k = 0; k <= 2 * i; k++) if (j ^ k) {
                prod = 1LL * prod * (n - k + P) % P * (j > k ? inv[j - k] : P - inv[k - j]) % P;
            }
            ans[i] = (ans[i] + 1LL * f[j][i] * prod) % P;
        }
        if (i > 1) (ans[i] += ans[i - 2]) %= P;
        if (i) printf("%d ", ans[i]);
    }
    return 0;
}