// Integers Have Friends (https://codeforces.com/contest/1549/problem/D)
#pragma GCC optimize("fast-math")
// begin "cp-lib/boilerplate.hpp"
#include <bits/stdc++.h>
#ifdef LOCAL
#  include <dbg.h>
#else
#  define dbg(...) do {} while (0)
#endif

#define _choose(_1, _2, _3, x, ...)     x
#define _rep(i, l, r)                   for (int i = l; i < r; ++i)
#define _rep0(i, r)                     _rep(i, 0, r)
#define rep(...)                        _choose(__VA_ARGS__, _rep, _rep0, _)(__VA_ARGS__)
#define _repr(i, r, l, ...)             for (int i = r; i >= l; --i)
#define repr(...)                       _repr(__VA_ARGS__, 0)
#define all(a)                          ::begin(a),::end(a)
#define trav(a, b)                      for (auto&& a : b)

using namespace std;
namespace cp_lib {}

using ll = long long;
using ld = long double;
[[maybe_unused]] static constexpr int INF = int(1e9 + 5);
[[maybe_unused]] static constexpr ll INFL = ll(INF) * INF;
template <class C> int sz(const C& c) { return int(::size(c)); }
// end "cp-lib/boilerplate.hpp"
// begin "cp-lib/ds/queue.hpp"
namespace cp_lib {
    template <class T, T Unit, class Comp>
    struct ExtremeValueQueue {
     protected:
        Comp c;
        array<vector<pair<T, T>>, 2> q{};

        T extreme(int i) const { return sz(q[i]) ? q[i].back().second : Unit; }
        void push(int i, T val) {
            T ex = extreme(i);
            q[i].emplace_back(val, c(val, ex) ? val : ex);
        }

     public:
        size_t size() const { return ::size(q[0]) + ::size(q[1]); }

        void push(T val) { push(0, val); }

        T pop() {
            if (!sz(q[1]))
                while (sz(q[0]))
                    push(1, q[0].back().first), q[0].pop_back();
            T val = q[1].back().first;
            q[1].pop_back();
            return val;
        }
    };

    template <class T>
    struct MinQueue;

    template <>
    struct MinQueue<int> : ExtremeValueQueue<int, INF, less<>> {
        int min() const { return ::min(extreme(0), extreme(1)); }
    };

    template <>
    struct MinQueue<ll> : ExtremeValueQueue<ll, INFL, less<>> {
        ll min() const { return ::min(extreme(0), extreme(1)); }
    };

    template <class T>
    struct MaxQueue;

    template <>
    struct MaxQueue<int> : ExtremeValueQueue<int, -INF, greater<>> {
        int max() { return ::max(extreme(0), extreme(1)); }
    };

    template <>
    struct MaxQueue<ll> : ExtremeValueQueue<ll, -INFL, greater<>> {
        ll max() { return ::max(extreme(0), extreme(1)); }
    };
}
// end "cp-lib/ds/queue.hpp"

using namespace cp_lib;

struct GcdQueue {
    array<vector<pair<ll, ll>>, 2> q{};

    ll get(int i) const { return (sz(q[i]) ? q[i].back().second : 0ll); }
    void push(int i, ll val) { q[i].emplace_back(val, gcd(val, get(i))); }

    size_t size() const { return ::size(q[0]) + ::size(q[1]); }
    ll get() const { return gcd(get(0), get(1)); }
    void push(ll val) { push(0, val); }
    ll pop() {
        if (!sz(q[1]))
            while (sz(q[0]))
                push(1, q[0].back().first), q[0].pop_back();
        ll val = q[1].back().first;
        q[1].pop_back();
        return val;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector a(n, 0ll);
        trav(ai, a) cin >> ai;

        vector b(n - 1, 0ll);
        rep(i, n - 1)
            b[i] = a[i + 1] - a[i];

        GcdQueue q;
        int r = 0, mx = 1;
        rep(l, n - 1) {
            while (r < n - 1 && q.get() != 1)
                q.push(b[r++]);
            mx = max(mx, sz(q) + (q.get() != 1));
            q.pop();
        }

        cout << mx << '\n';
    }
}