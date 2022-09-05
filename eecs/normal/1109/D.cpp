#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000010, P = 1000000007;
int n, m, ans, pw[maxn], pw2[maxn], fact[maxn], finv[maxn], inv[maxn];

int main() {
    scanf("%d %d", &n, &m);
    inv[0] = inv[1] = pw[0] = pw2[0] = fact[0] = finv[0] = 1;
    for (int i = 1; i <= max(n, m); i++) {
        pw[i] = 1LL * pw[i - 1] * m % P;
        pw2[i] = 1LL * pw2[i - 1] * n % P;
        fact[i] = 1LL * i * fact[i - 1] % P;
        if (i > 1) inv[i] = 1LL * (P - P / i) * inv[P % i] % P;
        finv[i] = 1LL * inv[i] * finv[i - 1] % P;
    }
    auto binom = [&](int n, int m) {
        assert(n >= m);
        return 1LL * fact[n] * finv[m] % P * finv[n - m] % P;
    };
    for (int i = 1; i <= min(n - 1, m); i++) {
        ans = (ans + binom(m - 1, i - 1) * binom(n - 1, i) % P * pw2[n - 1 - i] % P
            * pw[n - i - 1] % P * fact[i + 1]) % P;
    }
    ans = 1LL * ans * inv[n - 1] % P * inv[n] % P;
    printf("%d\n", ans);
    return 0;
}