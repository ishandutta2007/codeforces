#include <bits/stdc++.h>
using namespace std;

const int maxn = 6010, P = 998244353;
int p, s, r, fact[maxn], finv[maxn], inv[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d %d %d", &p, &s, &r);
    for (int i = fact[0] = finv[0] = 1; i < maxn; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
        inv[i] = qp(i, P - 2), finv[i] = qp(fact[i], P - 2);
    }
    auto binom = [&](int x, int y) {
        if (x < y || y < 0) return 0LL;
        return 1LL * fact[x] * finv[y] % P * finv[x - y] % P;
    };
    auto calc = [&](int n, int lim, int s) {
        if (!n) return !s ? 1 : 0;
        int ans = 0;
        for (int i = 0; i <= n && i * lim <= s; i++) {
            ans = (ans + 1LL * (i & 1 ? P - 1 : 1) * binom(n, i) % P * binom(s - i * lim + n - 1, n - 1)) % P;
        }
        return ans;
    };
    int all = binom(s - r + p - 1, p - 1), ans = 0;
    for (int i = r; i <= s; i++) {
        for (int j = 1; j <= p && i * j <= s; j++) {
            ans = (ans + 1LL * binom(p - 1, j - 1) * inv[j] % P * calc(p - j, i, s - i * j)) % P;
        }
    }
    printf("%lld\n", 1LL * ans * qp(all, P - 2) % P);
    return 0;
}