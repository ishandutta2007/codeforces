#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,mmx,abm,avx,avx2,tune=native")

template<typename T>
struct lineset {

    struct line {
        mutable T m, b, p;
        bool operator<(const line& o) const { return m < o.m; }
        bool operator<(T x) const { return p < x; }
    };

    multiset<line, less<>> hull;
    using it = decltype(hull.end());
    constexpr static T max_T = 1e18;
    constexpr static T min_T = -1e18;

    static T div(T x, T y) {
        return x/y;
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

typedef long double ld;

const int N = 2005;
array<ld, 3> a[N];

lineset<ld> mins, maxs;
multiset<pair<ld, ld>> s = {};

ld qry(ld x) {
    return maxs.query(x)+mins.query(x);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i][1] >> a[i][2] >> a[i][0];
    for (int i = 0; i < n; i++) {
        mins.insert(-a[i][0], -a[i][1]);
        maxs.insert(a[i][0], a[i][2]);
    }
    ld x = -1e9, y = 1e9;
    for (int i = 0; i < 1e5; i++) {
        ld m1 = (2*x+y)/3, m2 = (2*y+x)/3;
        if (qry(m1) > qry(m2))
            x = m1;
        else
            y = m2;
    }
    ld eps = 1e-12;
    sort(a, a+n);
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++) {
            if (a[i][0] == a[j][0]) continue;
            ld p = (a[j][2]-a[i][1])/(a[i][0]-a[j][0])+eps;
            ld q = (a[j][1]-a[i][2])/(a[i][0]-a[j][0])-eps;
            if (s.empty()) {
                s.insert({p, q});
                continue;
            }
            auto it = s.lower_bound({p, q});
            if (it != s.begin()) {
                it--;
                if (it->second > q) continue;
                if (it->second > p) {
                    p = it->first;
                    s.erase(it);
                }
            }
            it = ++s.insert({p, q});
            while (it != s.end() && it->second < q)
                s.erase(it++);
            if (it != s.end() && it->first < q) {
                q = it->second;
                s.erase(it--);
                s.erase(it);
                s.insert({p, q});
            }
        }
    if (s.empty()) {
        s.insert({x, x});
    } else {
        auto it = --s.lower_bound({x, x});
        if (!(it->first < x && it->second > x))
            s.insert({x, x});
    }
    ld ans = 1e18;
    for (auto& [p, q] : s) {
        ans = min(ans, qry(p));
        ans = min(ans, qry(q));
    }
    cout << setprecision(25) << ans << "\n";
}