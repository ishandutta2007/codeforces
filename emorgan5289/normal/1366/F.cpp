#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
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
    const static T max_T = numeric_limits<T>::max()-1000;
    const static T min_T = numeric_limits<T>::min()+1000;

    static T div(T x, T y) {
        return x/y - (is_integral<T>::value ? ((x^y) < 0 && x%y) : 0);
    }

    bool isect(it x, it y) {
        if (y == hull.end())
            return (x->p = max_T, 0);
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

const ll maxn = 2005, mod = 1e9+7;
array<ll, 3> e[maxn];
ll temp[maxn], c[maxn];
lineset<ll> s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m, q; cin >> n >> m >> q;
    for (ll i = 0; i < m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        e[i] = {u-1, v-1, w};
    }
    fill(c+1, c+n, -inf_ll);
    ll out = 0;
    for (ll j = 0; j < maxn && q > 0; j++, q--) {
        copy(c, c+n, temp);
        fill(c, c+n, -inf_ll);
        for (ll i = 0; i < m; i++) {
            auto& [u, v, w] = e[i];
            c[u] = max(c[u], temp[v]+w);
            c[v] = max(c[v], temp[u]+w);
        }
        out = (out+*max_element(c, c+n))%mod;
    }
    for (ll i = 0; i < m; i++) {
        auto& [u, v, w] = e[i];
        if (w > 0) debug(w, max(c[u], c[v]));
        s.insert(w, max(c[u], c[v]));
    }
    ll pp = 0;
    for (auto& [w, b, p] : s.hull) {
        debug(w, b, p);
        ll l = max(0ll, pp), r = min(q, p);
        ll k = r-l; pp = p;
        if (k <= 0) continue;
        out = (out+k*b)%mod;
        l = (l*(l+1)/2)%mod;
        r = (r*(r+1)/2)%mod;
        out = (out+((r-l+mod)%mod)*w)%mod;
    }
    cout << out << "\n";
}