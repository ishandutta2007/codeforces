#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll m, t, MOD, n, bt[21], invn;
vector<ll> e(1 << 20), b(1 << 20), c;

ll mul_mod(ll a, ll b) {
    ll x = a*b, y = (long double)a*b/MOD;
    return (x - y*MOD)%MOD;
}

void tr(vector<ll> &a, bool inverse = false) {
    for(int b = 0; b < m; b++)
        for(int i = 0; i < n; i++)
            if((i & (1 << b)) == 0) {
                ll u = a[i], v = a[i + (1 << b)];
                a[i] = (u + v) % MOD;
                a[i + (1 << b)] = (u - v + MOD) % MOD;
            }

	if (inverse)
		for (int i = 0; i < n; i++)
			a[i] >>= m;
}

ll pow(ll b, ll e) {
    if(e == 0) return 1;
    b %= MOD;
    if(e % 2) return mul_mod(b, pow(mul_mod(b, b), e/2));
    return pow(mul_mod(b, b), e/2);
}

int main() {
    scanf("%lld %lld %lld", &m, &t, &MOD);
    n = 1 << m;
    MOD <<= m;

    for(int i = 0; i < n; i++) {
        scanf("%lld", &e[i]);
        e[i] %= MOD;
    }

    for(int i = 0; i <= m; i++) {
        scanf("%lld", &bt[i]);
        bt[i] %= MOD;
    }

    for(int i = 0; i < n; i++) {
        b[i] = bt[__builtin_popcount(i)];
    }

    tr(e);
    tr(b);
    for(int i = 0; i < n; i++) {
        e[i] = mul_mod(e[i], pow(b[i], t));
    }

    tr(e, true);
    for(int i=0; i<n; i++) {
        printf("%lld\n", e[i]);
    }
    return 0;
}