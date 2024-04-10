// Contest: CodeCraft-20 (Div. 2) (https://codeforces.com/contest/1316)
// Problem: F: Battalion Strength (https://codeforces.com/contest/1316/problem/F)


// region {{{ boilerplate
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
//endregion }}}

template <class C>
struct Modular {
    using I = decltype(((int)1e9 + 7));
    I val = 0;

private:
    struct _Unchecked {};
    using _Mul = uint64_t;
    constexpr Modular(I _val, _Unchecked) : val(_val) {}
    static constexpr array<I, 3> ext_gcd(I a, I b) {
        if (!a) return {b,0,1};
        auto ar = ext_gcd(b % a, a);
        return {ar[0], ar[2] - (b / a) * ar[1], ar[1]};
    }
public:

    constexpr Modular() = default;
    template <class T>
    constexpr Modular(T _val) { val = _val % ((int)1e9 + 7); if (val < 0) val += ((int)1e9 + 7); }

    template <class T>
    constexpr explicit operator T() const { return static_cast<T>(val); }

#define DEFINE_CMP(op) constexpr bool operator op (Modular r) const { return val op r.val; }
    DEFINE_CMP(==) DEFINE_CMP(!=) DEFINE_CMP(<) DEFINE_CMP(<=) DEFINE_CMP(>) DEFINE_CMP(>=)
#undef DEFINE_CMP

    constexpr Modular& operator+=(Modular r) { if ((val += r.val) >= ((int)1e9 + 7)) val -= ((int)1e9 + 7); return *this; }
    constexpr Modular& operator-=(Modular r) { if (r.val > val) val += ((int)1e9 + 7); val -= r.val; return *this; }
    template <class T> constexpr enable_if_t<is_integral<T>::value, Modular&> operator+=(T r) { return *this += Modular(r); }
    template <class T> constexpr enable_if_t<is_integral<T>::value, Modular&> operator-=(T r) { return *this -= Modular(r); }
    constexpr Modular operator+(Modular r) const { return Modular(*this) += r; }
    constexpr Modular operator-(Modular r) const { return Modular(*this) -= r; }

    constexpr Modular operator*(Modular r) const { return Modular(static_cast<_Mul>(val) * static_cast<_Mul>(r.val)); }
    constexpr Modular& operator*=(Modular r) { return *this = *this * r; }
    template <class T> constexpr enable_if_t<is_integral<T>::value, Modular&> operator*=(T r) { return *this *= Modular(r); }

    template <class T> constexpr Modular pow(T e) const {
        Modular a = 1, b = *this;
        for (; e > 0; b *= b, e /= 2)
            if (e % 2) a *= b;
        return a;
    }
    constexpr Modular inv() const { I x = ext_gcd(val, ((int)1e9 + 7))[1]; return Modular(x < 0 ? x + ((int)1e9 + 7) : x, _Unchecked{}); }

    constexpr Modular& operator/=(Modular r) { return *this *= r.inv(); }
    template <class T> constexpr enable_if_t<is_integral<T>::value, Modular&> operator/=(T r) { return *this *= Modular(r); }
    constexpr Modular operator/(Modular r) const { return Modular(*this) /= r; }

    constexpr Modular operator+() const { return *this; }
    constexpr Modular operator-() const { return Modular(-val + ((int)1e9 + 7), _Unchecked{}); }
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
    using T = conditional_t<is_same<I, signed char>::value, int,
            conditional_t<is_same<I, unsigned char>::value, unsigned int,
                    conditional_t<is_same<I, char>::value, conditional_t<is_signed<char>::value, int, unsigned int>,
                            I>>>;
    T val{};
    in >> val;
    m = Modular<C>(val);
    return in;
}
template<class C> string to_string(Modular<C> m) { return to_string(m.val); }

namespace std {
    template <class C> struct hash<Modular<C>> {
        size_t operator()(Modular<C> m) const { return hash<typename Modular<C>::I>()(m.val); }
    };
}

template <class I, I M> struct ConstMod { static constexpr I m() { return M; } };
using MI = Modular<ConstMod<int, (int)1e9 + 7>>;
using vMI = vector<MI>;

MI operator ""_mi(unsigned long long i) { return MI(i); }

array<MI, 300005> tp, tpi;

struct SegTree {
    struct T {
        MI val, l, r;
        int cnt;
    };
    static constexpr T UNIT = T{0, 0, 0, 0};
    static T combine(T& a, T& b) {
        return {
                a.val + b.val + a.l * b.r * tpi[a.cnt],
                a.l + b.l * tp[a.cnt],
                a.r + b.r * tpi[a.cnt],
                a.cnt + b.cnt,
        };
    }

    int k = 1;
    vector<T> d;

    explicit SegTree(int n) {
        while (k < n) k *= 2;
        d = vector(2 * k, UNIT);
    }

    T& root() { return d[1]; }
    T& leaf(int i) { return d[k + i]; }

    void build() {
        for (int i = k - 1; i; --i)
            d[i] = combine(d[2*i], d[2*i + 1]);
    }

    void set(int i, int p) {
        d[i + k] = {0, p, p * tpi[1], 1};
        for (int j = i + k; j /= 2;)
            d[j] = combine(d[2*j], d[2*j+1]);
    }

    void reset(int i) {
        d[i + k] = UNIT;
        for (int j = i + k; j /= 2;)
            d[j] = combine(d[2*j], d[2*j+1]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    tp[0] = 1, tpi[0] = 1;
    MI twoinv = MI(2).inv();
    reps(i, 1, sz(tp))
        tp[i] = tp[i-1] * 2, tpi[i] = tpi[i-1] * twoinv;

    int n; cin >> n;
    vi p(n);
    vpi allp;
    rep(i, n) cin >> p[i], allp.emplace_back(p[i], i);
    int q; cin >> q;
    vpi up(q);
    rep(i, q) cin >> up[i].first >> up[i].second, --up[i].first, allp.emplace_back(up[i].second, n + i);
    sort(all(allp));
    auto idx = [&](pi p) { return (int)(lower_bound(all(allp), p) - begin(allp)); };
    vi cur(n);
    rep(i, n) cur[i] = idx(pi(p[i], i));

    SegTree seg(sz(allp));
    seg.build();
    rep(i, n)
        seg.set(cur[i], p[i]);

    cout << seg.root().val << '\n';
    rep(i, q) {
        auto [j, np] = up[i];
        seg.reset(cur[j]);
        cur[j] = idx(pi(np, n + i));
        seg.set(cur[j], np);
        cout << seg.root().val << '\n';
    }

    return 0;
}