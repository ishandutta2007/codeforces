#include <bits/stdc++.h>

// Contest: Codeforces Round #589 (Div. 2) (https://codeforces.com/contest/1228)
// Problem: C: Primes and Multiplication (https://codeforces.com/contest/1228/problem/C)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

ll MOD = 1e9 + 7;

ll mod_pow(ll base, ll exp) {
    if (exp == 0)
        return 1;
    if (exp == 1)
        return base;
    ll val = mod_pow(base, exp / 2);
    if (exp % 2)
        return val * val % MOD * base % MOD;
    return val * val % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x, n; cin >> x >> n;
    ll res = 1;
    for (ll i = 2; i * i <= x; ++i) {
        if (x % i)
            continue;
        ll exp = 0;
        for (ll j = n; j > 1; j /= i)
            exp += j / i;
        res = (res * mod_pow(i, exp)) % MOD;
        while (x % i == 0)
            x /= i;
    }
    if (x > 1) {
        ll exp = 0;
        for (ll j = n; j > 1; j /= x)
            exp += j / x;
        res = (res * mod_pow(x, exp)) % MOD;
    }

    cout << res << '\n';
    return 0;
}