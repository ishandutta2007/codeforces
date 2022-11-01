#include <bits/stdc++.h>

#define MOD 1000000009
#define MN 100010

using namespace std;
typedef long long ll;

ll n, a, b, k, x, m, A, B, ans;
char s[MN]; string str;

ll expo(ll a, ll b) {
	a %= MOD;
	if(!b) return 1;
	if(b % 2) return (a * expo(a * a, b / 2)) % MOD;
	return expo(a * a, b / 2);
}

ll invmod(ll x) {
	return expo(x, MOD - 2);
}

ll mul(ll a, ll b) {
    a %= MOD; b %= MOD;
    return (a * b) % MOD;
}

int main() {
    scanf("%lld %lld %lld %lld %s", &n, &A, &B, &k, s);
    str = s;

    a = expo(A, n);
    b = 1;

    m = mul(expo(B, k), invmod(expo(A, k)));

    for(int i = 0; i < k; i++) {
        ll val = (mul(a, b) * (str[i] == '+' ? 1 : -1) + MOD) % MOD;
        x = (x + val) % MOD;
        a = (a * invmod(A)) % MOD;
        b = (b * B) % MOD;
    }

    if(m == 1) {
        ans = mul(x, (n + 1) / k);
    }
    else {
        ans = (1 - expo(m, (n + 1) / k) + MOD) % MOD;
        ans = (ans * invmod((1 - m + MOD) % MOD)) % MOD;
        ans = mul(ans, x);
    }

    printf("%lld\n", ans);
    return 0;
}