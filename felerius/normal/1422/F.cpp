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

namespace snippets_modular {
    template <class C>
    struct Modular {
        using I = decltype(C::m());
        I val = 0;

    private:
#ifdef __SIZEOF_INT128__
        using Mul = conditional_t<sizeof(I) >= 5, unsigned __int128, uint64_t>;
#else
        static_assert(sizeof(I) <= 4, "cannot multiply larger than 64-bit");
        using Mul = uint64_t;
#endif

        struct Unchecked {};
        constexpr Modular(I _val, Unchecked) : val(_val) {}
        static constexpr array<I, 3> ext_gcd(I a, I b) {
            if (!a) return {b,0,1};
            auto ar = ext_gcd(b % a, a);
            return {ar[0], ar[2] - (b / a) * ar[1], ar[1]};
        }
    public:

        constexpr Modular() = default;
        template <class T>
        constexpr Modular(T _val) { _val %= C::m(); if (_val < 0) _val += C::m(); val = static_cast<I>(_val); }

        template <class T>
        constexpr explicit operator T() const { return static_cast<T>(val); }

#define DEFINE_CMP(op) constexpr bool operator op (Modular r) const { return val op r.val; }
        DEFINE_CMP(==) DEFINE_CMP(!=) DEFINE_CMP(<) DEFINE_CMP(<=) DEFINE_CMP(>) DEFINE_CMP(>=)
#undef DEFINE_CMP

        constexpr Modular& operator+=(Modular r) { if ((val += r.val) >= C::m()) val -= C::m(); return *this; }
        constexpr Modular& operator-=(Modular r) { if (r.val > val) val += C::m(); val -= r.val; return *this; }
        template <class T> constexpr enable_if_t<is_integral<T>::value, Modular&> operator+=(T r) { return *this += Modular(r); }
        template <class T> constexpr enable_if_t<is_integral<T>::value, Modular&> operator-=(T r) { return *this -= Modular(r); }
        constexpr Modular operator+(Modular r) const { return Modular(*this) += r; }
        constexpr Modular operator-(Modular r) const { return Modular(*this) -= r; }

        constexpr Modular operator*(Modular r) const { return Modular(static_cast<Mul>(val) * static_cast<Mul>(r.val)); }
        constexpr Modular& operator*=(Modular r) { return *this = *this * r; }
        template <class T> constexpr enable_if_t<is_integral<T>::value, Modular&> operator*=(T r) { return *this *= Modular(r); }

        template <class T> constexpr Modular pow(T e) const {
            Modular a = 1, b = *this;
            for (; e > 0; b *= b, e /= 2)
                if (e % 2) a *= b;
            return a;
        }
        constexpr Modular inv() const { I x = ext_gcd(val, C::m())[1]; return Modular(x < 0 ? x + C::m() : x, Unchecked{}); }

        constexpr Modular& operator/=(Modular r) { return *this *= r.inv(); }
        template <class T> constexpr enable_if_t<is_integral<T>::value, Modular&> operator/=(T r) { return *this /= Modular(r); }
        constexpr Modular operator/(Modular r) const { return Modular(*this) /= r; }

        constexpr Modular operator+() const { return *this; }
        constexpr Modular operator-() const { return Modular(val ? -val + C::m() : val, Unchecked{}); }
        constexpr Modular& operator++() { return *this += 1; }
        constexpr Modular& operator--() { return *this -= 1; }
        constexpr Modular operator++(int) { auto r = *this; *this += 1; return r; }
        constexpr Modular operator--(int) { auto r = *this; *this -= 1; return r; }
    };

#define DEFINE_OPS(op) \
        template <class C, class T, class = enable_if_t<is_integral<T>::value>> \
        constexpr auto operator op (Modular<C> l, T r) { return Modular<C>(l) op Modular<C>(r); } \
        template <class C, class T, class = enable_if_t<is_integral<T>::value>> \
        constexpr auto operator op (T l, Modular<C> r) { return Modular<C>(l) op Modular<C>(r); }
    DEFINE_OPS(==) DEFINE_OPS(!=) DEFINE_OPS(<) DEFINE_OPS(<=) DEFINE_OPS(>) DEFINE_OPS(>=)
    DEFINE_OPS(+) DEFINE_OPS(-) DEFINE_OPS(*) DEFINE_OPS(/)
#undef DEFINE_OPS

    template<class C> std::ostream& operator<<(std::ostream& out, Modular<C> m) { return out << m.val; }
    template <class C> std::istream& operator>>(std::istream& in, Modular<C>& m) {
        // Avoid reading character types
        using I = typename Modular<C>::I;
        using T = conditional_t<is_same<I, signed char>::value || is_same<I, unsigned char>::value || is_same<I, char>::value, int, I>;

        T val{};
        in >> val;
        m = Modular<C>(val);
        return in;
    }
    template<class C> string to_string(Modular<C> m) { return ::to_string(m.val); }

    template <class I, I M> struct ConstMod { static constexpr I m() { return M; } };
    using MI = Modular<ConstMod<int, (int)1e9 + 7>>;
    using vMI = vector<MI>;
} using namespace snippets_modular;
namespace std {
    template <class C> struct hash<Modular<C>> {
        size_t operator()(Modular<C> m) const { return hash<typename Modular<C>::I>()(m.val); }
    };
}

struct SegTree {
    struct Node {
        int32_t l = -1, r = -1;
        MI val = 1;
    };

    vector<Node> d;

    explicit SegTree(int n) {
        build(0, n);
    }

    int build(int l, int r) {
        int j = sz(d);
        d.emplace_back();
        if (r - l > 1) {
            int m = (l + r) / 2;
            d[j].l = build(l, m);
            d[j].r = build(m, r);
        }
        return j;
    }

    MI query(int i, int l, int r, int ql, int qr) {
        if (qr <= l || r <= ql)
            return 1;
        if (ql <= l && r <= qr)
            return d[i].val;

        int m = (l + r) / 2;
        return query(d[i].l, l, m, ql, qr) * query(d[i].r, m, r, ql, qr);
    }

    template <class It>
    int update(int i, int l, int r, It it, It it_end) {
        if (it == it_end)
            return i;

        int j = sz(d);
        d.push_back(d[i]);
        if (r - l == 1) {
            while (it != it_end)
                d[j].val *= it++->second;
        } else {
            int m = (l + r) / 2;
            auto it_mid = lower_bound(it, it_end, pair(m, MI(0)));
            d[j].l = update(d[j].l, l, m, it, it_mid);
            d[j].r = update(d[j].r, m, r, it_mid, it_end);
            d[j].val = d[d[j].l].val * d[d[j].r].val;
        }

        return j;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    map<int, vpi> exps;
    SegTree s(n);
    vi roots(n + 1);

    rep(i, n) {
        vector<pair<int, MI>> updates;
        auto add_factor = [&](int p, int e) {
            auto& stack = exps[p];
            int prev_e = 0;
            while (sz(stack) && stack.back().first <= e) {
                auto [e2, j] = stack.back();
                stack.pop_back();
                updates.emplace_back(j, MI(p).pow(e2 - prev_e).inv());
                prev_e = e2;
            }

            if (sz(stack)) {
                auto [e2, j] = stack.back();
                updates.emplace_back(j, MI(p).pow(e - prev_e).inv());
            }

            stack.emplace_back(e, i);
            reverse(all(updates));
            updates.emplace_back(i, MI(p).pow(e));
        };

        int ai; cin >> ai;
        for (int j = 2; j * j <= ai; ++j) {
            if (ai % j) continue;
            int e = 0;
            while (ai % j == 0)
                ai /= j, ++e;
            add_factor(j, e);
        }
        if (ai > 1)
            add_factor(ai, 1);
        sort(all(updates));
        roots[i + 1] = s.update(roots[i], 0, n, all(updates));
    }

    int last = 0;
    int q; cin >> q;
    while (q--) {
        int x, y; cin >> x >> y;
        int l = (last + x) % n, r = (last + y) % n;
        if (l > r) swap(l, r);
        ++r;

        last = (int)s.query(roots[r], 0, n, l, r);
        cout << last << '\n';
    }

    return 0;
}