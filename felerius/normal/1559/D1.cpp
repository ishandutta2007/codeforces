// Mocha and Diana (Easy Version) (https://codeforces.com/contest/1559/problem/D1)
#pragma GCC optimize("fast-math")
// begin "cp-lib/ds/dsu/base.hpp"
// begin "../../boilerplate.hpp"
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
// end "../../boilerplate.hpp"

namespace cp_lib {
    struct Dsu {
        vector<int> p;

        explicit Dsu(int n) : p(n, -1) {}

        int find(int i) { return p[i] < 0 ? i : p[i] = find(p[i]); }
        bool same(int i, int j) { return find(i) == find(j); }
        int size(int i) { return -p[find(i)]; }
        bool join(int i, int j) {
            i = find(i), j = find(j);
            if (i == j) return false;
            if (p[i] > p[j]) swap(i, j);
            p[i] += p[j], p[j] = i;
            return true;
        }
    };
}
// end "cp-lib/ds/dsu/base.hpp"

using namespace cp_lib;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m1, m2; cin >> n >> m1 >> m2;
    Dsu dsu1(n), dsu2(n);
    rep(_, m1) {
        int u, v; cin >> u >> v; --u, --v;
        dsu1.join(u, v);
    }
    rep(_, m2) {
        int u, v; cin >> u >> v; --u, --v;
        dsu2.join(u, v);
    }

    cout << (n - 1 - max(m1, m2)) << '\n';
    rep(i, n) rep(j, i + 1, n)
        if (!dsu1.same(i, j) && !dsu2.same(i, j))
            cout << (i + 1) << ' ' << (j + 1) << '\n', dsu1.join(i, j), dsu2.join(i, j);
}