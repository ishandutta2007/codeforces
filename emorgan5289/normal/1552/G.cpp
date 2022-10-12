#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

// call randint() for a random integer
mt19937 randint(chrono::steady_clock::now().time_since_epoch().count());

// returns a random integer over [a, b] inclusive
inline int uniform_randint(const int a, const int b) {
    return uniform_int_distribution<int>(a, b)(randint);
}

string bin(unsigned long long x) {
    string s(64, '0');
    for (ll i = 63; x > 0; i--, x >>= 1)
        if (x&1) s[i] = '1';
    return s;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, k; cin >> n >> k;
    bool ok = 1;
    vector<ll> s(k);
    for (ll i = 0; i < k; i++) {
        ll m; cin >> m;
        for (ll j = 0; j < m; j++) {
            ll x; cin >> x;
            s[i] |= 1ll<<(x-1);
        }
    }

    auto apply = [&](array<ll, 2> a, ll x) {
        ll p = __builtin_popcountll(a[1]&s[x]);
        ll q = __builtin_popcountll(s[x])-__builtin_popcountll(a[0]&s[x]&~a[1]);
        vector<array<ll, 2>> out;
        ll m = 0, j = 0;
        if (p <= 0 && 0 <= q)
            out.pb({a[0]|s[x], (a[1]&~s[x])});
        for (ll i = 0; i < n; i++) {
            if (s[x]&(1ll<<i)) {
                m |= 1ll<<i;
                j++;
                if (p <= j && j <= q)
                    out.pb({a[0]|s[x], (a[1]&~s[x])|m});
            }
        }
        return out;
    };

    auto valid = [&](array<ll, 2> a) {
        ll p = __builtin_popcountll(a[0]);
        if (p < n-1) return false;
        if (p == n-1)
            return a[1] == (1ll<<__builtin_ctzll(~a[0]))-1;
        return __builtin_popcountll(a[1]+1) == 1;
    };

    vector<array<ll, 2>> p, q;
    p.pb({0, 0});
    for (int i = 0; i < k; i++) {
        q.clear();
        for (auto& a : p)
            for (auto& b : apply(a, i))
                q.pb(b);
        swap(p, q);
    }
    debug(p);

    for (auto& a : p)
        debug(bin(a[0]), bin(a[1]));

    for (auto& a : p)
        if (!valid(a))
            cout << "REJECTED\n", exit(0);
    cout << "ACCEPTED\n";
}