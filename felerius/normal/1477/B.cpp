// Nezzar and Binary String (https://codeforces.com/contest/1477/problem/B)
// begin "cp-lib/boilerplate.hpp"
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <chrono>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#if __cplusplus >= 201703L
#   include <optional>
#   include <string_view>
#   define all(a)      ::begin(a),::end(a)
#   define sz(x)       ((int)::size(x))
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define all(a)      (a).begin(),(a).end()
#   define sz(x)       ((int)(x).size())
#   define MAYBE_UNUSED
#endif

#define _choose(_1, _2, _3, chosen, ...) chosen
#define _rep0(i, r)       for (int i = 0; i < r; ++i)
#define _repn(i, l, r)    for (int i = l; i < r; ++i)
#define _repr0(i, r)      for (int i = r; i >= 0; --i)
#define _reprn(i, r, l)   for (int i = r; i >= l; --i)
#define rep(...)          _choose(__VA_ARGS__, _repn, _rep0, suppress_warning)(__VA_ARGS__)
#define repr(...)         _choose(__VA_ARGS__, _reprn, _repr0, suppress_warning)(__VA_ARGS__)
#define trav(a, b)        for(auto& a : b)

using namespace std;

using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using u64 = uint64_t;
using u32 = uint32_t;

MAYBE_UNUSED static constexpr int INF = (int)1e9 + 5;
MAYBE_UNUSED static constexpr ll INFL = (ll)INF * INF;
MAYBE_UNUSED static mt19937 rng((u32)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());

namespace cp_lib {}
// end "cp-lib/boilerplate.hpp"
// begin "cp-lib/ds/segtree/lazy.hpp"
// begin "base.hpp"
namespace cp_lib::_segtree_detail {
    template <class Derived, class Conf>
    struct SegmentTreeImpl {
     private:
        using T = typename Conf::T;

        void push(int i) { ((Derived*)this)->push(i); }

     protected:
        int n, k = 1;
        vector<T> d;

        void push_path(int i) {
            int h = __builtin_ctz(k);
            repr(s, h, 1) push(i >> s);
        }
        void recalc(int i) { d[i] = Conf::combine(d[2*i], d[2*i+1]); }

     public:
        explicit SegmentTreeImpl(int n_) : n(n_) {
            while (k < n) k *= 2;
            d.resize(2 * k, Conf::UNIT);
        }

        template <class Iter>
        SegmentTreeImpl(Iter it, Iter end) : n((int)(end - it)) {
            while (k < n) k *= 2;
            d.resize(2 * k, Conf::UNIT);
            copy(it, end, begin(d) + k);
            build();
        }

        T& root() { return d[1]; }
        T& leaf(int i) { return d[k + i]; }

        // Width of the range represented by a node
        int width(int i) { return min(k >> (31 - __builtin_clz(i)), n); }

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
// end "base.hpp"

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
                apply_at(2*i, lz[i]), apply_at(2*i+1, lz[i]), lz[i] = Conf::NO_UPD;
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
    static constexpr T UNIT = 0;
    static constexpr U NO_UPD = -1;
    static T combine(const T& a, const T& b) { return a + b; }
    static void apply(T& val, U& lz, const U& upd, int w) {
        if (upd == NO_UPD) return;
        val = upd * w;
        lz = upd;
    }
};
using SegTree = LazySegmentTree<SegTreeConf>;

bool solve() {
    int n, q; cin >> n >> q;
    string s, f; cin >> s >> f;
    vector<pair<int, int>> qs(q);
    for (auto& [l, r] : qs) cin >> l >> r, --l;
    reverse(all(qs));

    SegTree seg(n);
    rep(i, n)
        seg.point_update(i, [&](int& val) { val = f[i] - '0'; });

    for (auto& [l, r] : qs) {
        auto sum = seg.query(l, r);
        int w = r - l;
        if (w % 2 == 0 && sum == w / 2)
            return false;
        if (sum <= w / 2)
            seg.update(l, r, 0);
        else
            seg.update(l, r, 1);
    }

    rep(i, n)
        if (seg.query(i, i + 1) != s[i] - '0')
            return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--)
        cout << (solve() ? "YES\n" : "NO\n");

    return 0;
}