// Gold Transfer (https://codeforces.com/contest/1535/problem/E)
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

    int q; cin >> q;
    vector a(q + 1, 0), c(q + 1, 0);
    cin >> a[0] >> c[0];
    constexpr int LOG = 19;
    vector up(q + 1, array<int, 19>{});
    up[0].fill(-1);

    rep(i, 1, q + 1) {
        int ty; cin >> ty;
        if (ty == 1) {
            cin >> up[i][0] >> a[i] >> c[i];
            rep(j, 1, LOG)
                up[i][j] = (up[i][j - 1] == -1 ? -1 : up[up[i][j - 1]][j - 1]);
        } else {
            int v, w; cin >> v >> w;
            int vr = v, x = 0, rem = w;
            repr(j, LOG - 1)
                if (up[vr][j] != -1 && a[up[vr][j]] > 0)
                    vr = up[vr][j], x += 1 << j;
            ll cost = 0;
            while (rem > 0 && x >= 0) {
                vr = v;
                rep(j, LOG)
                    if ((x >> j) & 1)
                        vr = up[vr][j];
                int buy = min(a[vr], rem);
                cost += c[vr] * ll(buy);
                a[vr] -= buy;
                rem -= buy;
                --x;
            }

            cout << (w - rem) << ' ' << cost << '\n' << flush;
        }
    }

    return 0;
}