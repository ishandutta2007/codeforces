#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010, P = 1000000007;
int n, ans, a[maxn], fact[maxn], finv[maxn], f[20][maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = fact[0] = finv[0] = 1; i <= n; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
        finv[i] = qp(fact[i], P - 2);
    }
    auto binom = [&](int n, int m) {
        return 1LL * fact[n] * finv[m] % P * finv[n - m] % P;
    };
    int m = 0;
    while (m + 4 < n) m += 4;
    for (int i = 0; i <= m; i++) {
        if (!(i & 1)) f[0][i] = binom(m / 2, i / 2);
    }
    auto calc = [&](int x, int y) {
        x++, y++;
        long long z = 1LL * n * (n - 1) / 2 - 1LL * x * (x + 1) / 2 + y;
        return z % 2 == 1;
    };
    for (int i = 1; i < n - m; i++) {
        for (int j = 0; j <= m + i; j++) {
            (f[i][j] += f[i - 1][j]) %= P;
            if (j) {
                if (calc(m + i - 1, j - 1)) (f[i][j] += f[i - 1][j - 1]) %= P;
                else (f[i][j] += P - f[i - 1][j - 1]) %= P;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        ans = (ans + 1LL * f[n - m - 1][i] * a[i]) % P;
    }
    printf("%d\n", ans);
    return 0;
}