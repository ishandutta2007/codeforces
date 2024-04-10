#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010, P = 998244353;
int T, n, a[maxn], f[maxn], g[maxn];
int fact[maxn], inv[maxn], finv[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d", &T);
    fact[0] = inv[0] = inv[1] = finv[0] = 1;
    for (int i = 1; i < maxn; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
        if (i > 1) inv[i] = 1LL * (P - P / i) * inv[P % i] % P;
        finv[i] = 1LL * finv[i - 1] * inv[i] % P;
    }
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            a[i] = f[i] = g[i] = 0;
        }
        for (int i = 1, x; i <= n; i++) {
            scanf("%d", &x), a[x]++;
        }
        if (*max_element(a + 1, a + n + 1) == n) {
            puts("1"); continue;
        }
        int ways = 0, ans = 0, gv = n;
        vector<int> V;
        for (int i = 1; i <= n; i++) if (a[i]) {
            gv = __gcd(gv, a[i]), V.push_back(a[i]);
        }
        for (int i = 1; i <= n; i++) if (!(n % i) && !(gv % (n / i))) {
            int foo = fact[i], bar = 0, num = n / i;
            for (int j : V) {
                foo = 1LL * foo * finv[j / num] % P;
            }
            for (int j : V) if (j / num > 1) {
                bar = (bar + 1LL * foo * finv[i] % P * fact[i - 1] % P * fact[j / num] % P * finv[j / num - 2]) % P;
                bar = (bar + 1LL * foo * finv[i] % P * fact[i - 2] % P * fact[j / num] % P * finv[j / num - 2]) % P;
            }
            bar = 1LL * bar * num % P;
            (f[i] += foo) %= P, (g[i] += bar) %= P;
            for (int j = i + i; j <= n; j += i) {
                f[j] = (f[j] - f[i] + P) % P;
                g[j] = (g[j] - g[i] + P) % P;
            }
            ways = (ways + 1LL * inv[i] * f[i]) % P;
            ans = (ans + 1LL * inv[i] * g[i]) % P;
        }
        ans = (1LL * ways * n - ans + P) % P;
        printf("%lld\n", 1LL * ans * qp(ways, P - 2) % P);
    }
    return 0;
}