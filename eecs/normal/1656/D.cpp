#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int T;
ll n;
mt19937_64 rnd(time(0));

ll mul(ll a, ll b, ll p) {
    ll r = a * b - ll((long double)a / p * b + 0.5) * p;
    return r < 0 ? r + p : r;
    // return (__int128)a * b % p;
}

ll qp(ll x, ll y, ll p) {
    ll z = 1;
    for (; y; y >>= 1, x = mul(x, x, p)) {
        if (y & 1) z = mul(z, x, p);
    }
    return z;
}

bool MR(ll x, ll b) {
    for (ll k = x - 1; k; k >>= 1) {
        ll cur = qp(b, k, x);
        if (cur != 1 && cur != x - 1) return 0;
        if (k & 1 || cur == x - 1) return 1;
    }
    return true;
}

bool test(ll x) {
    if (x == 1) return 0;
    static ll p[] = {2, 3, 5, 7, 17, 19, 61};
    for (ll y : p) {
        if (x == y) return 1;
        if (!MR(x, y)) return 0;
    }
    return 1;
}

ll PR(ll x) {
    ll s = 0, t = 0, c = rnd() % (x - 1) + 1;
    for (int goal = 1; ; goal <<= 1, s = t) {
        ll v = 1, g;
        for (int step = 1; step <= goal; ++step) {
            t = (mul(t, t, x) + c) % x;
            v = mul(v, abs(t - s), x);
            if (!(step % 127) && (g = __gcd(v, x)) > 1) return g;
        }
        if ((g = __gcd(v, x)) > 1) return g;
    }
}

vector<ll> fact(ll x) {
    if (x == 1) return {};
    if (test(x)) return {x};
    ll p = x;
    while (p >= x) p = PR(x);
    return {p};
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &n);
        if (n % 2 == 1) {
            puts("2");
        } else {
            bool flag = 0;
            ll m = n;
            while (!(m % 2)) m /= 2;
            auto pr = fact(m);
            for (ll k : pr) {
                if ((__int128)k * (k + 1) / 2 <= n) {
                    printf("%lld\n", k), flag = 1; break;
                }
            }
            if (!flag) {
                for (ll k = 2; k * (k + 1) / 2 <= n; k *= 2) {
                    if (n % k == k / 2) {
                        printf("%lld\n", k), flag = 1; break;
                    }
                }
            }
            if (!flag) puts("-1");
        }
    }
    return 0;
}