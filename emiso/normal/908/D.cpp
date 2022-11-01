#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD 1'000'000'007

ll expo(ll a, ll b) {
    if(!b) return 1;
    a %= MOD;
    if(b & 1) return a * expo(a * a, b >> 1) % MOD;
    return expo(a * a, b >> 1);
}

ll inv_mod(ll a) { return expo(a, MOD - 2); }

ll k, pa, pb, p[1010][2010];

int main() {
    scanf("%lld %lld %lld", &k, &pa, &pb);
    ll inv = inv_mod(pa + pb);
    pa = pa * inv % MOD;
    pb = pb * inv % MOD;
    
    p[1][0] = 1;
    for (int ab = 0; ab < k; ab++) {
        for (int a = 1; a <= k; a++) {
            p[a+1][ab] += p[a][ab] * pa % MOD;
            if (p[a+1][ab] >= MOD) p[a+1][ab] -= MOD;

            p[a][ab+a] += p[a][ab] * pb % MOD;
            if (p[a][ab+a] >= MOD) p[a][ab+a] -= MOD;
        }
    }

    ll ans = 0;
    for (int ab = k; ab <= 2*k; ab++)
        for (int a = 1; a <= k; a++)
            ans = (ans + p[a][ab] * ab) % MOD;

    for (int ab = 0; ab < k; ab++) {
        ll a = k + inv_mod(pb);
        ans = (ans + p[k+1][ab] * (ab + a)) % MOD;
    }

    printf("%lld\n", ans);
    return 0;
}