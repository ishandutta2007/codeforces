#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n; ll l, r, f[61], g[61];

ll qp(ll x, ll y) {
    if (x > g[y]) return LLONG_MAX;
    ll z = 1;
    for (; y; y >>= 1, x *= x) {
        if (y & 1) z *= x;
    }
    return z;
}

bool chk(ll n, int k) {
    ll x = 1e18, m = 1;
    while (k--) {
        if (x / m < n) return 0;
        m *= n;
    }
    return 1;
}

ll get(ll n, int k) {
    ll x = pow(n, 1.0 / k) - 1;
    while (qp(x + 1, k) <= n) x++;
    return x;
}

ll solve(ll x) {
    if (!x) return 0;
    for (int i = 60; i >= 2; i--) {
        f[i] = get(x, i) - 1;
        for (int j = i + i; j <= 60; j += i) {
            f[i] -= f[j];
        }
    }
    return accumulate(f + 2, f + 61, 0) + 1;
}

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= 60; i++) {
        g[i] = pow(1e18, 1.0 / i) - 1;
        while (chk(g[i] + 1, i)) g[i]++;
    }
    while (n--) {
        scanf("%lld %lld", &l, &r);
        printf("%lld\n", solve(r) - solve(l - 1));
    }
    return 0;
}