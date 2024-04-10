// Jumping Around (https://codeforces.com/contest/1550/problem/F)
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
// begin "cp-lib/ds/dsu/base.hpp"
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

    int n, Q, s, d; cin >> n >> Q >> s >> d; --s;
    vector a(n, 0);
    trav(ai, a) cin >> ai;

    vector<array<int, 4>> nearest(n);
    rep(i, n) {
        auto it = upper_bound(all(a), a[i] - d);
        nearest[i][0] = (it == begin(a) ? -1 : int(it - begin(a) - 1));

        it = lower_bound(all(a), a[i] - d);
        nearest[i][1] = (it == end(a) ? -1 : int(it - begin(a)));

        it = upper_bound(all(a), a[i] + d);
        nearest[i][2] = (it == begin(a) ? -1 : int(it - begin(a) - 1));

        it = lower_bound(all(a), a[i] + d);
        nearest[i][3] = (it == end(a) ? -1 : int(it - begin(a)));
    }

    vector adj(n, vector<pair<int, int>>());
    int comp = n;
    Dsu dsu(n);
    while (comp > 1) {
        vector below(n, pair(-1, -1)), above(n, pair(-1, -1));
        rep(i, n) {
            if (i)
                below[i] = below[i - 1];
            if (below[i].first == -1 || dsu.same(i, below[i].first))
                below[i].first = i;
            else
                below[i] = {i, below[i].first};
        }

        repr(i, n - 1) {
            if (i + 1 < n)
                above[i] = above[i + 1];
            if (above[i].first == -1 || dsu.same(i, above[i].first))
                above[i].first = i;
            else
                above[i] = {i, above[i].first};
        }

        vector mn_out(n, tuple(INF, -1, 0));
        rep(i, n) {
            auto [u, v, w, x] = nearest[i];

            auto other_below = [&](int j) {
                if (j == -1) return -1;
                return dsu.same(below[j].first, i) ? below[j].second : below[j].first;
            };
            auto other_above = [&](int j) {
                if (j == -1) return -1;
                return dsu.same(above[j].first, i) ? above[j].second : above[j].first;
            };

            array<int, 4> cand = {
                other_below(u),
                other_above(v),
                other_below(w),
                other_above(x)
            };
            trav(c, cand)
                if (c != -1)
                    mn_out[dsu.find(i)] = min(mn_out[dsu.find(i)], tuple(abs(abs(a[i] - a[c]) - d), c, i));
        }

        rep(j, n) {
            auto [w, v2, v] = mn_out[j];
            if (v2 == -1)
                continue;
            if (dsu.join(j, v2)) {
                comp--;
                adj[v].emplace_back(v2, w);
                adj[v2].emplace_back(v, w);
            }
        }
    }

    vector dist(n, INF);
    queue<int> q;
    dist[s] = 0;
    q.emplace(s);
    while (sz(q)) {
        int v = q.front(); q.pop();
        for (auto [v2, w] : adj[v])
            if (dist[v2] == INF)
                dist[v2] = max(w, dist[v]), q.emplace(v2);
    }

    while (Q--) {
        int v, k; cin >> v >> k; --v;
        cout << (dist[v] <= k ? "Yes\n" : "No\n");
    }
}