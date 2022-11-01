#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll t = 1, n, ans, a[MN];
//char s[MN]; string str;

#define MOD 998244353

ll expo(ll a, ll b) {
    if(!b) return 1;
    a %= MOD;
    if(b & 1) return a * expo(a * a, b >> 1) % MOD;
    return expo(a * a, b >> 1);
}

ll inv_mod(ll a) { return expo(a, MOD - 2); }

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld", &n);

    ll tot = n * (n - 1) % MOD * inv_mod(2) % MOD;

    int f[2] = {0, 0};
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        f[a[i]]++;
    }

    ll wrong = 0;
    for(int i = 0; i < f[0]; i++) {
        if (a[i] == 1) {
            wrong++;
        }
    }

    for (ll i = wrong; i > 0; i--) {
        ll inv = inv_mod(i);
        ans += tot * inv % MOD * inv % MOD;
        if (ans >= MOD) ans -= MOD;
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}