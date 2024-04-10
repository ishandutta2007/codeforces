#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010, P = 1000000007;
int n, ans, fact[maxn], finv[maxn], f[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d", &n);
    for (int i = fact[0] = 1; i <= n + 1; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
    }
    finv[n + 1] = qp(fact[n + 1], P - 2);
    for (int i = n; ~i; i--) {
        finv[i] = 1LL * (i + 1) * finv[i + 1] % P;
    }
    auto binom = [&](int n, int m) {
        if (n < m || m < 0) return 0LL;
        return 1LL * fact[n] * finv[m] % P * finv[n - m] % P;
    };
    for (int i = 0; i + i <= n; i++) if ((n - i) % 2 == 0) {
        int ways = binom(n - i + 1, i);
        if (i > 1) ways = (ways - binom(n - i - 1, i - 2) % P + P) % P;
        ans = (ans + 1LL * fact[n - i] * ways) % P;
    }
    printf("%d\n", (ans + ans) % P);
    return 0;
}