#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, P = 1000000007;
int T, n, K, fact[maxn], finv[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d", &T);
    for (int i = fact[0] = finv[0] = 1; i <= 100000; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
        finv[i] = qp(fact[i], P - 2);
    }
    auto binom = [&](int n, int m) {
        if (n < m || n < 0) return 0LL;
        return 1LL * fact[n] * finv[m] % P * finv[n - m] % P;
    };
    while (T--) {
        scanf("%d %d", &n, &K), K--;
        int ans = 0;
        for (int i = 1; i <= n && (i - 1) * K <= n; i++) {
            int s = binom(n - (i - 1) * K, i);
            ans = (ans + 1LL * s * fact[i] % P * fact[n - i]) % P;
        }
        ans = 1LL * ans * finv[n] % P;
        printf("%d\n", (ans + 1) % P);
    }
    return 0;
}