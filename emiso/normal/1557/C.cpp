#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, k, ans, a[MN];
pair<int, int> b[MN];
//char s[MN]; string str;

#define MOD 1'000'000'007

ll expo(ll a, ll b) {
    if(!b) return 1;
    a %= MOD;
    if(b & 1) return a * expo(a * a, b >> 1) % MOD;
    return expo(a * a, b >> 1);
}

ll inv_mod(ll a) {
    return expo(a, MOD - 2);
}

ll fat[MN], invfat[MN];

void prep() {
    fat[0] = 1;
    for(ll i = 1; i < MN; i++)
        fat[i] = (fat[i-1] * i) % MOD;

    invfat[MN-1] = inv_mod(fat[MN-1]);
    for(ll i = MN-1; i > 0; i--)
        invfat[i-1] = (i * invfat[i]) % MOD;
}

ll nCr(ll n, ll k) {
    if(k < 0 || k > n) return 0;
    return fat[n] * invfat[k] % MOD * invfat[n - k] % MOD;
}

int main() {
    prep();
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld", &n, &k);

    ll mult = 1, even = 0;

    for(int i = 0; i < n; i += 2) {
        even += nCr(n, i);
        if(even >= MOD) even -= MOD;
    }

    for(int i = 0; i < k; i++) {
        ll cur = 0;
        if(n % 2) {
            cur = even + 1;
            if(cur >= MOD) cur -= MOD;
            mult = mult * cur % MOD;
        } else {
            cur = even;
            ans = (ans + mult * expo(2, n*(k-i-1))) % MOD;
            mult = mult * cur % MOD;
        }
    }
    
    ans += mult;
    if(ans >= MOD) ans -= MOD;
    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}