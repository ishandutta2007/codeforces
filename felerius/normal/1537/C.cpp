// Challenging Cliffs (https://codeforces.com/contest/1537/problem/C)
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

using namespace cp_lib;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector a(n, 0);
        trav(ai, a) cin >> ai;
        sort(all(a));

        auto mn = pair(INF, 0);
        rep(i, 1, n)
            mn = min(mn, pair(a[i] - a[i - 1], i));

        int i = mn.second;
        swap(a[0], a[i - 1]);
        swap(a[i], a[n - 1]);
        auto it_mid = partition(begin(a) + 1, end(a) - 1, [&](int ai) { return ai >= a[0]; });
        sort(begin(a) + 1, it_mid);
        sort(it_mid, end(a) - 1);

        trav(ai, a)
            cout << ai << ' ';
        cout << '\n';
    }

    return 0;
}