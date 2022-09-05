#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int P = 1000000007;
ll n, ans, coef[51][51], fact[100000], finv[100000], inv[100000];
int K, f[10010][51], g[10010][51];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%lld %d", &n, &K);
    ll m = n;
    vector<pair<ll, int>> V;
    for (ll i = 2; i * i <= m; i++) if (!(m % i)) {
        int c = 0;
        while (!(m % i)) m /= i, c++;
        V.emplace_back(i, c);
    }
    if (m > 1) V.emplace_back(m, 1);
    for (int i = fact[0] = finv[0] = 1; i < 100000; i++) {
        fact[i] = i * fact[i - 1] % P;
        finv[i] = qp(fact[i], P - 2);
        inv[i] = qp(i, P - 2);
    }
    for (int i = 0; i <= 50; i++) {
        memset(f, 0, sizeof(f)), f[0][i] = 1;
        memset(g, 0, sizeof(g));
        for (int j = 0; j <= K; j++) {
            for (int k = 0; k <= i; k++) {
                if (k) (g[j][k] += g[j][k - 1]) %= P;
                (f[j][k] += g[j][k]) % P;
            }
            for (int k = 0; k <= i; k++) if (f[j][k]) {
                g[j + 1][0] = (g[j + 1][0] + 1LL * f[j][k] * inv[k + 1]) % P;
                g[j + 1][k + 1] = (g[j + 1][k + 1] - 1LL * f[j][k] * inv[k + 1] % P + P) % P;
            }
        }
        for (int j = 0; j <= i; j++) coef[i][j] = f[K][j];
    }
    auto solve = [&](ll x) {
        ll t = 1;
        for (auto p : V) {
            ll i = x;
            int c = 0;
            while (!(i % p.first)) c++, i /= p.first;
            t = t * coef[p.second][c] % P;
        }
        ans = (ans + x % P * t) % P;
    };
    for (ll i = 1; i * i <= n; i++) if (!(n % i)) {
        solve(i);
        if (i * i < n) solve(n / i);
    }
    printf("%lld\n", ans);
    return 0;
}