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
#define debug(...)
#else
#include "../../debug.cpp"
#endif

template<typename T>
struct lineset {

    struct line {
        mutable T m, b, p;
        bool operator<(const line& o) const { return m < o.m; }
        bool operator<(T x) const { return p < x; }
    };

    multiset<line, less<>> hull;
    using it = decltype(hull.end());
    constexpr static T max_T = numeric_limits<T>::max();
    constexpr static T min_T = numeric_limits<T>::min();

    static T div(T x, T y) {
        if constexpr (!is_integral<T>::value) return x/y;
        else return x/y - ((x^y) < 0 && x%y);
    }

    bool isect(it x, it y) {
        if (y == hull.end())
            return x->p = max_T, 0;
        if (x->m == y->m)
            x->p = x->b > y->b ? max_T : min_T;
        else
            x->p = div(y->b - x->b, x->m - y->m);
        return x->p >= y->p;
    }

    // remove all lines from the set
    void clear() {
        hull.clear();
    }

    // insert the line mx+b into the set, runs in O(logn).
    void insert(T m, T b) {
        it z = hull.insert({m, b, 0}), y = z++, x = y;
        while (isect(y, z)) z = hull.erase(z);
        if (x != hull.begin() && isect(--x, y))
            isect(x, y = hull.erase(y));
        while ((y = x) != hull.begin() && (--x)->p >= y->p)
            isect(x, hull.erase(y));
    }

    // returns the maximum value of mx+b over all lines in the set, runs in O(logn).
    T query(T x) const {
        auto [m, b, _] = *hull.lower_bound(x);
        return m*x + b;
    }
};

const int N = 2e5+5;
lineset<ll> s;

ll min_geq(ll k) {
    ll x = 1;
    while (s.query(x) < k) x *= 2;
    for (ll i = 1ll<<60; i > 0; i /= 2)
        if (x-i >= 0 && s.query(x-i) >= k) x -= i;
    return x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, k; cin >> n >> k;
    vector<array<ll, 2>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i][1] >> a[i][0];
    sort(all(a));
    ll mv = 0;
    s.insert(0, 0);
    for (auto& [c, v] : a) {
        if (v <= mv) continue;
        cmax(mv, v);
        ll x = min_geq(c);
        s.insert(v, s.query(x)-c-v*x);
    }
    cout << min_geq(k) << "\n";
}