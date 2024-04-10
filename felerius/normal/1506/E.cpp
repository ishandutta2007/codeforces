// Restoring the Permutation (https://codeforces.com/contest/1506/problem/E)
// begin "cp-lib/boilerplate.hpp"
#include <bits/stdc++.h>

#define _choose(_1, _2, _3, chosen, ...) chosen
#define _rep(i, l, r)     for (int i = l; i < r; ++i)
#define _rep0(i, r)       _rep(i, 0, r)
#define _repr(i, r, l)    for (int i = r; i >= l; --i)
#define _repr0(i, r)      _repr(i, r, 0)
#define rep(...)          _choose(__VA_ARGS__, _rep, _rep0, suppress_warning)(__VA_ARGS__)
#define repr(...)         _choose(__VA_ARGS__, _repr, _repr0, suppress_warning)(__VA_ARGS__)
#define all(a)      ::begin(a),::end(a)
#define sz(c)       int(::size(c))
#define trav(a, b)  for(auto& a : b)

using namespace std;

using ll = long long;
using ld = long double;
using u64 = uint64_t;
using u32 = uint32_t;

[[maybe_unused]] static constexpr int INF = int(1e9 + 5);
[[maybe_unused]] static constexpr ll INFL = ll(INF) * INF;
[[maybe_unused]] static mt19937 rng(u32(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count()));

namespace cp_lib {}
// end "cp-lib/boilerplate.hpp"
// begin "cp-lib/ds/segtree/base.hpp"
// begin "_impl.hpp"
// begin "../../bit.hpp"
namespace cp_lib {
    template <class T> constexpr inline bool is_pow2(T n) { return n && !(n & (n - 1)); }
    template <class T> constexpr inline int floor_log2(T n) { return n ? 63 - __builtin_clzll(n) : 0; }
    template <class T> constexpr inline int ceil_log2(T n) { return floor_log2(n) + !is_pow2(n); }
}
// end "../../bit.hpp"

namespace cp_lib::_segtree_detail {
    template <class Derived, class Conf>
    struct SegmentTreeImpl {
     private:
        using T = typename Conf::T;

        void push(int i) { ((Derived*)this)->push(i); }

     protected:
        int n, k;
        vector<T> d;

        void push_path(int i) { repr(s, __builtin_ctz(k), 1) push(i >> s); }
        void recalc(int i) { d[i] = Conf::combine(d[2*i], d[2*i+1]); }

     public:
        explicit SegmentTreeImpl(int n_) : n(n_), k(1 << ceil_log2(n)), d(2 * k, Conf::UNIT) {}

        template <class Iter>
        SegmentTreeImpl(Iter it, Iter end) : n(int(end - it)), k(1 << ceil_log2(n)), d(2 * k, Conf::UNIT) {
            copy(it, end, begin(d) + k);
            build();
        }

        T& root() { return d[1]; }
        T& leaf(int i) { return d[k + i]; }

        // Width of the range represented by a node
        int width(int i) { return min(k >> floor_log2(i), n); }

        // Build the entire tree from the leaves up
        void build() { repr(i, k - 1, 1) recalc(i); }

        // Aggregate for [l, r)
        T query(int l, int r) {
            push_path(l + k);
            push_path(r + k - 1);
            T rl = Conf::UNIT, rr = Conf::UNIT;
            for (l += k, r += k; l < r; l /= 2, r /= 2) {
                if (l % 2) rl = Conf::combine(rl, d[l++]);
                if (r % 2) rr = Conf::combine(d[--r], rr);
            }
            return Conf::combine(rl, rr);
        }

        // Update single leaf value
        template <class F>
        void point_update(int i, F f) {
            push_path(i += k);
            f(d[i]);
            while (i /= 2) recalc(i);
        }

        // First position s.t. prefix matches pred
        template <class Pred>
        int lower_bound(Pred pred) {
            if (!pred(d[1])) return n;
            T pref = Conf::UNIT;
            int i = 1;
            while (i < k)
                if (push(i); !pred(Conf::combine(pref, d[i *= 2])))
                    pref = Conf::combine(pref, d[i++]);
            return i - k;
        }
    };
}
// end "_impl.hpp"

namespace cp_lib {
    template <class Conf>
    struct SegmentTree : _segtree_detail::SegmentTreeImpl<SegmentTree<Conf>, Conf> {
     private:
        using Base = _segtree_detail::SegmentTreeImpl<SegmentTree<Conf>, Conf>;
        friend Base;

        void push(int) {}

     public:
        using Base::Base;
    };
}
// end "cp-lib/ds/segtree/base.hpp"

using namespace cp_lib;

struct SegTreeConf {
    using T = int;
    static constexpr T UNIT = 0;
    static T combine(const T& a, const T& b) { return max(a, b); }
};
using SegTree = SegmentTree<SegTreeConf>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector q(n, 0);
        trav(qi, q) cin >> qi;

        vector pmn(n, 0), pmx(n, 0);
        pmn[0] = pmx[0] = q[0];
        rep(i, 1, n)
            if (q[i] != q[i - 1])
                pmn[i] = pmx[i] = q[i];
        set<int> avail_mn;
        rep(i, 1, n + 1) avail_mn.emplace(i);
        rep(i, n)
            if (pmn[i] != 0)
                avail_mn.erase(pmn[i]);
        rep(i, n)
            if (pmn[i] == 0)
                pmn[i] = *begin(avail_mn), avail_mn.erase(begin(avail_mn));
        trav(i, pmn)
            cout << i << ' ';
        cout << '\n';

        SegTree s(n);
        rep(i, n)
            s.leaf(i) = i + 1;
        s.build();
        rep(i, n)
            if (pmx[i] != 0)
                s.point_update(pmx[i] - 1, [&](int& val) { val = 0; });

        rep(i, n) {
            if (pmx[i] != 0) continue;
            int mx = s.query(0, q[i] - 1);
            pmx[i] = mx;
            s.point_update(mx - 1, [&](int& val) { val = 0; });
        }
        trav(i, pmx)
            cout << i << ' ';
        cout << '\n';
    }

    return 0;
}