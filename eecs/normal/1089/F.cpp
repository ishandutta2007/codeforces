#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) { x = 1, y = 0; return a; }
    ll d = exgcd(b, a % b, y, x);
    return y -= a / b * x, d;
}

int main() {
    ll n;
    scanf("%lld", &n);
    ll m = n - 1, x = n;
    vector<ll> d;
    for (ll i = 2; i * i <= x; i++) if (!(x % i)) {
        d.push_back(i);
        while (!(x % i)) x /= i;
    }
    if (x > 1) d.push_back(x);
    sort(d.begin(), d.end());
    if (d.size() == 1) puts("NO"), exit(0);
    ll p = d[0], q = d[1], y;
    assert(exgcd(p, q, x, y) == 1);
    x *= n - 1, y *= n - 1;
    if (x < 0) {
        ll t = (-x + q - 1) / q;
        x += t * q, y -= t * p;
    }
    if (y < 0) {
        ll t = (-y + p - 1) / p;
        x -= t * q, y += t * p;
    }
    puts("YES\n2");
    printf("%lld %lld\n", x, n / p);
    printf("%lld %lld\n", y, n / q);
    return 0;
}