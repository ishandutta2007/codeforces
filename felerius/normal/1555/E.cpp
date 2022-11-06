// Boring Segments (https://codeforces.com/contest/1555/problem/E)
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
// begin "cp-lib/ds/segtree/lazy.hpp"
// begin "_impl.hpp"
// begin "../../bit.hpp"
namespace cp_lib {
    template <class T> constexpr inline bool is_pow2(T n) { return n && !(n & (n - 1)); }
    template <class T> constexpr inline int floor_log2(T n) { return n ? 63 - __builtin_clzll(n) : 0; }
    template <class T> constexpr inline int ceil_log2(T n) { return n ? floor_log2(n) + !is_pow2(n) : 0; }
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
    struct LazySegmentTree : _segtree_detail::SegmentTreeImpl<LazySegmentTree<Conf>, Conf> {
     private:
        using Base = _segtree_detail::SegmentTreeImpl<LazySegmentTree<Conf>, Conf>;
        using U = typename Conf::U;
        friend Base;

        vector<U> lz;

        void apply_at(int i, const U& upd) {
            U dummy = Conf::NO_UPD;
            Conf::apply(Base::d[i], (i < Base::k ? lz[i] : dummy), upd, Base::width(i));
        }

        void push(int i) {
            if (lz[i] != Conf::NO_UPD)
                apply_at(2 * i, lz[i]), apply_at(2*i+1, lz[i]), lz[i] = Conf::NO_UPD;
        }

     public:
        explicit LazySegmentTree(int n_) : Base(n_), lz(Base::k, Conf::NO_UPD) {}

        template <class Iter>
        LazySegmentTree(Iter it, Iter end) : Base(it, end), lz(Base::k, Conf::NO_UPD) {}

        // Apply update to range [l, r)
        void update(int l, int r, const U& upd) {
            Base::push_path(l + Base::k);
            Base::push_path(r + Base::k - 1);

            for (int li = l + Base::k, ri = r + Base::k; li < ri; li /= 2, ri /= 2) {
                if (li % 2) apply_at(li++, upd);
                if (ri % 2) apply_at(--ri, upd);
            }

            for (int i : {l + Base::k, r + Base::k - 1})
                while (i /= 2)
                    if (lz[i] == Conf::NO_UPD)
                        Base::recalc(i);
        }
    };
}
// end "cp-lib/ds/segtree/lazy.hpp"

using namespace cp_lib;

struct SegTreeConf {
    using T = int;
    using U = int;
    static constexpr T UNIT = INF;
    static constexpr U NO_UPD = 0;
    static T combine(const T& a, const T& b) { return min(a, b); }
    static void apply(T& val, U& lz, const U& upd, int) {
        val += upd;
        lz += upd;
    }
};
using SegTree = LazySegmentTree<SegTreeConf>;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector a(n, array<int, 3>{});
    for (auto& [w, l, r] : a)
        cin >> l >> r >> w, --l, l *= 2, r = 2 * r - 1;
    sort(all(a));

    SegTree seg(2 * m - 1);
    rep(i, 2 * m - 1)
        seg.leaf(i) = 0;
    seg.build();

    int ans = INF;
    int j = 0;
    rep(i, n) {
        while (j < n && seg.root() == 0)
            seg.update(get<1>(a[j]), get<2>(a[j]), 1), ++j;
        if (seg.root() > 0)
            ans = min(ans, get<0>(a[j - 1]) - get<0>(a[i]));
        seg.update(get<1>(a[i]), get<2>(a[i]), -1);
    }

    cout << ans << '\n';
}