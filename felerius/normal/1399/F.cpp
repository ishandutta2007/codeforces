// region boilerplate
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <chrono>
#include <cstdint>
#include <deque>
#include <exception>
#include <forward_list>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#if __cplusplus >= 201703L
#   include <optional>
#   include <string_view>
#   include <variant>
#endif

using namespace std;

#if __cplusplus >= 201703L
#   define all(a)      begin(a),end(a)
#   define sz(x)       ((int)size(x))
#else
#   define all(a)      (a).begin(),(a).end()
#   define sz(x)       ((int)(x).size())
#endif

#define rep(a, b)      for(int a = 0; a < (b); ++a)
#define reps(a, b, c)  for(int a = (b); a < (c); ++a)
#define trav(a, b)     for(auto& a : b)

using ll = long long;
using ld = long double;
using u64 = uint64_t;
using u32 = uint32_t;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vpi = vector<pi>;

#if __cplusplus >= 201703L
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define MAYBE_UNUSED
#endif

MAYBE_UNUSED static constexpr int INF = (int)1e9 + 5;
MAYBE_UNUSED static constexpr ll INFL = (ll)1e18 + 5;
MAYBE_UNUSED static mt19937 rng((u32)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
//endregion

namespace snippets_segtree {
    template <class C> struct SegTree_ : private C {
        using typename C::T; using typename C::U; using C::UNIT; using C::combine;

        int k = 1;
        vector<T> d;

        explicit SegTree_(int n) {
            while (k < n) k *= 2;
            d = vector(2 * k, UNIT);
        }

        T& root() { return d[1]; }
        T& leaf(int i) { return d[k + i]; }

        void build() {
            for (int i = k - 1; i; --i)
                d[i] = combine(d[2*i], d[2*i + 1]);
        }

        void update(int i, U upd) {
            C::update(d[i + k], upd);
            for (int j = i + k; j /= 2;)
                d[j] = combine(d[2*j], d[2*j+1]);
        }

        T query(int l, int r) { // [l, r)
            T rl = UNIT, rr = UNIT;
            for (l += k, r += k; l < r; l /= 2, r /= 2) {
                if (l % 2) rl = combine(rl, d[l++]);
                if (r % 2) rr = combine(d[--r], rr);
            }
            return combine(rl, rr);
        }
    };

    struct SegTreeConf {
        using T = int;
        using U = int;

        static constexpr T UNIT = -INF;

        static T combine(const T& l, const T& r) { return max(l, r); }
        static void update(T& v, U upd) { v = max(v, upd); }
    };

    using SegTree = SegTree_<SegTreeConf>;
}
using namespace snippets_segtree;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vpi seg(n);
        vi p = {0, INF};
        for (auto& [l, r] : seg) cin >> l >> r, p.push_back(l), p.push_back(r);

        sort(all(p));
        p.erase(unique(all(p)), end(p));
        auto idx = [&](int i) { return (int)(lower_bound(all(p), i) - begin(p)); };
        for (auto& [l, r] : seg)
            l = idx(l), r = idx(r);
        sort(all(seg), [](pi a, pi b) { return a.second - a.first < b.second - b.first; });
        int w = sz(p);
        seg.emplace_back(0, w - 1);

        vi seg_by_left(n + 1);
        iota(all(seg_by_left), 0);
        sort(all(seg_by_left), [&](int i, int j) { return seg[i] < seg[j]; });

        vi contain(n + 1, 1);
        rep(i, n + 1) {
            auto [l, r] = seg[i];
            SegTree dp(w);
            dp.update(0, 0);

            trav(j, seg_by_left) {
                if (i == j)
                    continue;
                auto [l2, r2] = seg[j];
                if (l <= l2 && r2 <= r)
                    dp.update(r2, dp.query(0, l2) + contain[j]);
            }
            contain[i] = 1 + dp.query(0, r + 1);
        }

        cout << (contain[n] - 1) << '\n';
    }

    return 0;
}