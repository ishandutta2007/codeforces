#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ll mod = 1000003;

ll binpow(ll x, ll deg) {
    if (!deg) return 1;
    if (deg & 1ll) return (x * binpow(x, deg ^ 1ll)) % mod;
    x = binpow(x, deg >> 1ll);
    return (x * x) % mod;
}

ll divide(ll a, ll b) {
    return (a * binpow(b, mod - 2)) % mod;
}

ll n, k;

int main()
{
    cin >> n >> k;
    if (n <= 60 && (1LL << n) < k) {
        cout << "1 1\n";
        return 0;
    }

    ll cur = binpow(2, n);
    for (ll i = 1; cur && i <= k - 1; ++i)
        cur = ((cur * (binpow(2, n) - i)) % mod + mod) % mod;

    ll todiv = 0;
    for (ll i = 1; i <= 60; ++i) {
        todiv = (todiv + ((k - 1) / (1LL << i))) % (mod - 1);
    }

    ll B = binpow(binpow(2, n), k);
    ll g = (binpow(2, n) * binpow(2, todiv)) % mod;
    ll A = divide(cur, g);
    B = divide(B, g);
    A = ((B - A) % mod + mod) % mod;
    cout << A << " " << B << "\n";

    return 0;
}