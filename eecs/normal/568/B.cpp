#include <bits/stdc++.h>
using namespace std;

const int maxn = 4010, P = 1000000007;
int n, ans, f[maxn], fact[maxn], finv[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d", &n);
    for (int i = fact[0] = finv[0] = 1; i <= n; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
        finv[i] = qp(fact[i], P - 2);
    }
    auto binom = [&](int i, int j) {
        return 1LL * fact[i] * finv[j] % P * finv[i - j] % P;
    };
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= i; j++) {
            f[i] = (f[i] + f[i - j] * binom(i - 1, j - 1)) % P;
        }
    }
    for (int i = 0; i < n; i++) {
        ans = (ans + f[i] * binom(n, i) % P * (qp(2, n - i) - 1)) % P;
    }
    printf("%d\n", ans);
    return 0;
}