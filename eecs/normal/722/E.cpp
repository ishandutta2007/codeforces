#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010, maxk = 2010, P = 1000000007;
int n, m, K, s, fact[maxn], finv[maxn], f[21][maxk], ways[maxk][maxk];
array<int, 2> p[maxk];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d %d %d %d", &n, &m, &K, &s);
    for (int i = 1; i <= K; i++) {
        scanf("%d %d", &p[i][0], &p[i][1]);
    }
    p[0] = {1, 1}, p[++K] = {n, m}, sort(p, p + K + 1);
    for (int i = fact[0] = finv[0] = 1; i <= n + m; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
        finv[i] = qp(fact[i], P - 2);
    }
    auto binom = [&](int x, int y) {
        return x < y || y < 0 ? 0 : 1LL * fact[x] * finv[y] % P * finv[x - y] % P;
    };
    for (int i = 0; i <= K; i++) {
        for (int j = i + 1; j <= K; j++) {
            if (p[j][1] < p[i][1]) ways[i][j] = 0;
            else ways[i][j] = binom(p[j][0] + p[j][1] - p[i][0] - p[i][1], p[j][0] - p[i][0]);
        }
    }
    auto upd = [&](int f[maxk]) {
        for (int i = K; ~i; i--) {
            for (int j = i + 1; j <= K; j++) {
                f[i] = (f[i] + 1LL * (P - ways[i][j]) * f[j]) % P;
            }
        }
    };
    int all = binom(n + m - 2, n - 1), ans = 0;
    f[0][K] = 1, upd(f[0]);
    for (int i = 1; i <= 20; i++, s = (s + 1) / 2) {
        for (int j = 0; j <= K; j++) {
            for (int k = j + 1; k <= K; k++) {
                f[i][j] = (f[i][j] + 1LL * ways[j][k] * f[i - 1][k]) % P;
            }
        }
        ans = (ans + 1LL * s * f[i][0]) % P;
        all = (all - f[i][0] + P) % P, upd(f[i]);
    }
    printf("%lld\n", 1LL * (ans + all) * qp(binom(n + m - 2, n - 1), P - 2) % P);
    return 0;
}