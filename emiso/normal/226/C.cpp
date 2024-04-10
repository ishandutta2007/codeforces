#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll MOD, L, R, d, k, ans;

/// fast fibonacci
map<ll, ll> F;
ll fib(ll x) {
    if(x < 2) return 1 % MOD;
    if(F.count(x)) return F[x];
    ll k = x / 2;
    if(x % 2) return F[x] = (fib(k) * fib(k+1) % MOD + fib(k) * fib(k-1) % MOD) % MOD;
    return F[x] = (fib(k) * fib(k) % MOD + fib(k-1) * fib(k-1) % MOD) %MOD;
}

void cmon(ll x) {
    if(x && R / x - (L-1) / x >= k)
        ans = max(ans, x);
}

void check(ll x) {
    ll l, r;
    for(l = 1; l <= x; l = r + 1) {
        r = x / (x / l);
        cmon(r);
    }
}

int main() {
    scanf("%lld %lld %lld %lld", &MOD, &L, &R, &k);

    d = R - L + 1;
    ans = d / k;

    check(R);
    check(L-1);

    printf("%lld\n", fib(ans-1));
    return 0;
}