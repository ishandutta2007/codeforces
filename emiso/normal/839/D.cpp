#include <bits/stdc++.h>
#define MN 202000
#define MOD 1000000007
#define BOUND 1000000

using namespace std;
typedef long long ll;

int n;
ll a[MN], resp[2 * BOUND], f[2 * BOUND];

long long pow_(long long a, long long b) {
    long long ret=1;
    for(;b > 0; b >>= 1) {
        if(b % 2)
            ret = (ret * a) % MOD;
        a = (a*a) % MOD;
    }
    return ret;
}

ll csub(ll x) {
    return (x * pow_(2, x - 1)) % MOD;
}

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%lld", &a[i]);
        f[a[i]]++;
    }

    for(int i = BOUND; i>1; i--) {
        ll intersec = 0;
        ll multiples = f[i];

        for(int j = i + i; j <= BOUND; j += i) {
            multiples = (multiples + f[j]) % MOD;
            intersec = (intersec + resp[j]) % MOD;
        }

        resp[i] = (csub(multiples) - intersec + MOD + MOD) % MOD;
    }

    ll ans = 0;
    for(int i = 2; i <= BOUND; i++) {
        ans = (ans + (i*resp[i])%MOD) % MOD;
    }

    printf("%lld\n", ans);

    return 0;
}