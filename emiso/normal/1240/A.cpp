#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, p[MN], x, a, y, b, t, ja[MN], k;

bool can(ll q) {
    for(int i = 0; i <= q; i++) ja[i] = 0;
    ll ans = 0, s = a / __gcd(a, b) * b, z = 0;

    for(ll i = s; i <= q; i += s) {
        ans += (x + y) * p[z++];
        ja[i] = 1;
    }

    for(int i = a; i <= q; i += a) {
        if(ja[i]) continue;
        ans += x * p[z++];
        ja[i] = 1;
    }

    for(int i = b; i <= q; i += b) {
        if(ja[i]) continue;
        ans += y * p[z++];
        ja[i] = 1;
    }

    assert(z <= q);
    return (ans >= k);
}

bool ok(ll q) {
    ll o1 = can(q);
    swap(x, y);
    swap(a, b);
    return o1 || can(q);
}

int main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld", &n);
        for(int i = 0; i < n; i++) {
            scanf("%lld", &p[i]);
            p[i] /= 100;
        }
        sort(p, p + n, greater<ll>());

        scanf("%lld %lld", &x, &a);
        scanf("%lld %lld", &y, &b);
        scanf("%lld", &k);

        ll l = 1, r = n+1, m;
        while(l < r) {
            m = (l + r) / 2;
            if(ok(m)) r = m;
            else l = m + 1;
        }

        if(l > n) puts("-1");
        else printf("%lld\n", l);
    }
    return 0;
}