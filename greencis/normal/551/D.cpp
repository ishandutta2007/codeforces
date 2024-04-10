#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

map<ll,ll> precalc_fib;
ll n,k,l,m;

ll fib(ll num) {
    if (!precalc_fib[num]) {
        ll cur = 0ll;
        if (!(num % 2ll)) cur = fib(num / 2ll) * fib(num / 2ll) + fib(num / 2ll - 1ll) * fib(num / 2ll - 1ll);
        else cur = fib(num / 2ll + 1ll) * fib(num / 2ll) + fib(num / 2ll) * fib(num / 2ll - 1ll);
        precalc_fib[num] = cur % m + 1ll;
    }
    return precalc_fib[num] - 1ll;
}

ll binpow(ll num, ll deg) {
    if (deg == 0ll) return 1ll;
    if (deg % 2ll) return (num * binpow(num, deg - 1ll)) % m;
    num = binpow(num, deg / 2ll);
    return (num * num) % m;
}

int main()
{
    cin >> n >> k >> l >> m;

    precalc_fib[0] = 2ll;
    precalc_fib[1] = 2ll;

    int len = 0;
    ll kk = k;
    while (kk) ++len, kk >>= 1ll;
    if (len > l) { cout << 0; return 0; }

    ll ans = 1ll;
    ll fibb = fib(n+1ll);
    ll binp = binpow(2, n);

    for (int i = 0; i < l; ++i) {
        int curbit = int((k >> (ll)i) & 1ll);
        if (!curbit) ans = (ans * fibb) % m;
        else ans = (ans * (((binp - fibb) % m + m) % m)) % m;
    }

    cout << ans % m;

    return 0;
}