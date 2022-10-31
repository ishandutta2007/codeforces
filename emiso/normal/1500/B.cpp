#include <bits/stdc++.h>

using namespace std;
typedef long long ll; /// dont use unsigned

ll xgcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1; y = 0;
        return a;
    }
    ll g = xgcd(b, a%b, x, y), x1 = y;
    y = x - (a / b) * y;
    x = x1;
    return g;
}

ll inv_mod(ll a, ll mod) {
    ll x, y;
    xgcd(a, mod, x, y);
    return (x % mod + mod) % mod;
}

/// has answer iff a[i] = a[j] mod gcd(n[i], n[j])
ll chinese_remainder(ll *a, ll *n, int size) {
    if (size == 1) return a[0];

    ll tmp = inv_mod(n[0], n[1]) * (a[1] - a[0]) % n[1];
    if(tmp < 0) tmp += n[1];

    ll a1 = a[1], g = __gcd(n[0], n[1]);
    a[1] = a[0] + n[0] / g * tmp;
    n[1] *= n[0] / g;
    ll ret = chinese_remainder(a + 1, n + 1, size - 1);
    n[1] /= n[0] / g;
    a[1] = a1;
    return ret;
}

#define MN 1000100
ll sz, t[MN], fa[MN], fb[MN], a[MN], b[MN], x[2], mod[2], n, m, k;

ll solve(ll d) {
    ll ret = 0;
    for(int i = 1; i <= 2* max(n, m); i++) {
        if(a[i] == -1 || b[i] == -1) continue;
        if(d < t[i]) continue;
        ret += 1 + (d - t[i]) / sz;
    }
    return d - ret;
}

int main() {
    scanf("%lld %lld %lld", &n, &m, &k);

    memset(a, -1, sizeof a);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &fa[i]);
        a[fa[i]] = i;
    }
    memset(b, -1, sizeof b);
    for(int i = 1; i <= m; i++) {
        scanf("%lld", &fb[i]);
        b[fb[i]] = i;
    }

    sz = n / __gcd(n, m) * m;
    mod[0] = n; mod[1] = m;
    for(int i = 1; i <= 2* max(n, m); i++) {
        if(a[i] == -1 || b[i] == -1) continue;

        x[0] = a[i]; x[1] = b[i];
        t[i] = chinese_remainder(x, mod, 2);

        if((t[i] % mod[0]) != (x[0] % mod[0])) a[i] = b[i] = -1; // no solution
        else if((t[i] % mod[1]) != (x[1] % mod[1])) a[i] = b[i] = -1; // no solution
        else assert(t[i] >= x[0] && t[i] >= x[1]);
    }

    ll l = 1, r = 1e18, mid;
    while(l < r) {
        mid = (l + r) / 2;
        if(solve(mid) < k) l = mid + 1;
        else r = mid;
    }

    printf("%lld\n", l);
    return 0;
}