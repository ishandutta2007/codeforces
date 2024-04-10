#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000010, P = 1000000007;
int T, n, m, K, fact[maxn], finv[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d", &T);
    for (int i = fact[0] = finv[0] = 1; i <= 2000000; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
        finv[i] = qp(fact[i], P - 2);
    }
    auto binom = [&](int x, int y) {
        if (x < y || y < 0) return 0LL;
        return 1LL * fact[x] * finv[y] % P * finv[x - y] % P;
    };
    auto calc = [&](int x, int y) {
        if (!x && !y) return 1LL;
        return binom(x - 1, x - y - 1);
    };
    while (T--) {
        scanf("%d %d %d", &n, &m, &K);
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            ans = (ans + 1LL * qp((P + 1) / 2, n - i) * calc(n - i, m - i) % P * i) % P;
        }
        printf("%lld\n", 1LL * K * ans % P);
    }
    return 0;
}