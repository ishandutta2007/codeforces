#include <bits/stdc++.h>
using namespace std;
    
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
    
#include <bits/stdc++.h>
    
using namespace std;
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
    
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
    
ull gcd(ull u, ull v) {
    if (u == 0 || v == 0)
        return v ^ u;
    int shift = __builtin_ctzll(u | v);
    u >>= __builtin_ctzll(u);
    do {
        v >>= __builtin_ctzll(v);
        if (u > v) {
            ull t = v;
            v = u;
            u = t;
        }
        v -= u;
    } while (v);
    return u << shift;
}
    
typedef unsigned long long ull;
ull modmul(ull a, ull b, ull M) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
	ull ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2)
		if (e & 1) ans = modmul(ans, b, mod);
	return ans;
}

bool isPrime(ull n) {
	if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
	    s = __builtin_ctzll(n-1), d = n >> s;
	for (ull a : A) {   // ^ count trailing zeroes
		ull p = modpow(a%n, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = modmul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}
    
typedef ull u64;
typedef unsigned int u32;
    
typedef __uint128_t u128;
// typedef __int128_t i128;
typedef long long i64;
typedef unsigned long long u64;
    
u64 hi(u128 x) { return (x >> 64); }
u64 lo(u128 x) { return (x << 64) >> 64; }
struct Mont {
    Mont(u64 n) : mod(n) {
        inv = n;
        rep(i, 0, 6) inv *= 2 - n * inv;
        r2 = -n % n;
        rep(i, 0, 4) if ((r2 <<= 1) >= mod) r2 -= mod;
        rep(i, 0, 5) r2 = mul(r2, r2);
    }
    u64 reduce(u128 x) const {
        u64 y = hi(x) - hi(u128(lo(x) * inv) * mod);
        return i64(y) < 0 ? y + mod : y;
    }
    u64 reduce(u64 x) const { return reduce(x); }
    u64 init(u64 n) const { return reduce(u128(n) * r2); }
    u64 mul(u64 a, u64 b) const { return reduce(u128(a) * b); }
    u64 mod, inv, r2;
};
    
ull pollard(ull n) {
    if (n == 9)
        return 3;
    if (n == 25)
        return 5;
    if (n == 49)
        return 7;
    if (n == 323)
        return 17;
    Mont mont(n);
    auto f = [n, &mont](ull x) { return mont.mul(x, x) + 1; };
    ull x = 0, y = 0, t = 0, prd = 2, i = 1, q;
    while (t++ % 32 || gcd(prd, n) == 1) {
        if (x == y)
            x = ++i, y = f(x);
        if ((q = mont.mul(prd, max(x, y) - min(x, y))))
            prd = q;
        x = f(x), y = f(f(y));
    }
    return gcd(prd, n);
}
    
unordered_map<ll, int> primes;
void factor(ull n) {
    if (n == 1)
        return;
    if (isPrime(n))
        primes[n]++;
    else {
        ull x = pollard(n);
        factor(x), factor(n / x);
    }
}
    
int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    for (cin >> t; t; t--) {
        long long x, y;
        cin >> x >> y;

        primes.clear();

        vector<ll> factors = {1};
        factor(x);

        for (auto [p, c] : primes) {
            int s = sz(factors);
            for (int i = 0; i < s; i++) {
                ll f = 1;
                for (int j = 0; j < c; j++) {
                    f *= p;
                    factors.push_back(factors[i]*f);
                }
            }
        }

        ll ans = 1;
        for (auto f : factors) {
            if (f % y != 0) ans = max(ans, f);
        }
        
        cout << ans << endl;
    }
}