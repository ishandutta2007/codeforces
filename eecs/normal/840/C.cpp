#include <bits/stdc++.h>
using namespace std;

const int maxn = 310, P = 1000000007;
int n, ans, a[maxn], fact[maxn], finv[maxn], f[maxn], g[maxn], coef[maxn];
map<int, int> mp;

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        int x = 1;
        for (int j = 2; j * j <= a[i]; j++) if (!(a[i] % j)) {
            int c = 0;
            while (!(a[i] % j)) c ^= 1, a[i] /= j;
            if (c) x *= j;
        }
        if (a[i] > 1) x *= a[i];
        mp[x]++;
    }
    for (int i = fact[0] = finv[0] = 1; i <= n; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
        finv[i] = qp(fact[i], P - 2);
    }
    auto binom = [&](int n, int m) {
        return 1LL * fact[n] * finv[m] % P * finv[n - m] % P;
    };
    f[0] = 1;
    for (auto p : mp) {
        int m = p.second;
        for (int i = 0; i < m; i++) {
            coef[i] = 1LL * binom(m - 1, i) * fact[m] % P * finv[m - i] % P;
        }
        memset(g, 0, sizeof(g));
        for (int i = 0; i <= n; i++) if (f[i]) {
            for (int j = 0; j < m; j++) {
                g[i + j] = (g[i + j] + 1LL * f[i] * coef[j]) % P;
            }
        }
        memcpy(f, g, sizeof(f));
    }
    for (int i = 0; i <= n; i++) {
        ans = (ans + 1LL * f[i] * (i & 1 ? P - 1 : 1) % P * fact[n - i]) % P;
    }
    printf("%d\n", ans);
    return 0;
}