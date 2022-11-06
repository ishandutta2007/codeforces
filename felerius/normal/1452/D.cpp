// Radio Towers (https://codeforces.com/contest/1452/problem/D)

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
#   define all(a)      ::begin(a),::end(a)
#   define sz(x)       ((int)::size(x))
#else
#   define all(a)      (a).begin(),(a).end()
#   define sz(x)       ((int)(x).size())
#endif

#define _choose(_1, _2, _3, chosen, ...) chosen
#define _rep0(i, r)       for (int i = 0; i < r; ++i)
#define _repn(i, l, r)    for (int i = l; i < r; ++i)
#define _repr0(i, r)      for (int i = r; i >= 0; --i)
#define _reprn(i, r, l)   for (int i = r; i >= l; --i)
#define rep(...)          _choose(__VA_ARGS__, _repn, _rep0, suppress_warning)(__VA_ARGS__)
#define repr(...)         _choose(__VA_ARGS__, _reprn, _repr0, suppress_warning)(__VA_ARGS__)
#define trav(a, b)        for(auto& a : b)

using ll = long long;
using ld = long double;

#if __cplusplus >= 201703L
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define MAYBE_UNUSED
#endif

MAYBE_UNUSED static constexpr int INF = (int)1e9 + 5;
MAYBE_UNUSED static constexpr ll INFL = (ll)INF * INF;
MAYBE_UNUSED static mt19937 rng((uint32_t)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());

namespace cp_lib {}



namespace cp_lib {
    // Returns (g, x, y) with |g| = gcd(a, b) and g = a * x + b * y.
    // If both arguments are positive/negative, g also has that sign.
    // Also: |x| < |b / g|, |y| < |a / g|
    template <class I, class = enable_if_t<is_integral_v<I> && is_signed_v<I>>>
    array<I, 3> ext_gcd(I a, I b) {
        if (!a) return {b, 0, 1};
        auto [d, x1, y1] = ext_gcd(b % a, a);
        return {d, y1 - (b / a) * x1, x1};
    }
}

namespace cp_lib {
    template <class I, I M, class Enable = void>
    struct Modular;

    template <class I, I M>
    struct Modular<I, M, enable_if_t<is_integral_v<I> && is_signed_v<I>>> {
        I val = 0;
        constexpr static I Mod = M;

     private:
#ifdef __SIZEOF_INT128__
        using Mul = conditional_t<sizeof(I) <= 4, uint64_t, unsigned __int128>;
#else
        static_assert(sizeof(I) <= 4, "cannot multipy without int128");
        using Mul = uint64_t;
#endif

        struct Unchecked {};
        constexpr Modular(I val_, Unchecked) : val{val_} {}
     public:

        constexpr Modular() = default;
        template <class T, class = enable_if_t<is_integral_v<T>>>
        constexpr Modular(T val_) { val = (I)(val_ % M); if (val < 0) val += M; }

        template <class T, class = enable_if_t<is_integral_v<T>>>
        constexpr explicit operator T() const { return (T)val; }

#define DEFINE_CMP(op) constexpr bool operator op (Modular r) const { return val op r.val; }
        DEFINE_CMP(==) DEFINE_CMP(<) DEFINE_CMP(<=)
        DEFINE_CMP(!=) DEFINE_CMP(>) DEFINE_CMP(>=)
#undef DEFINE_CMP

        constexpr Modular& operator+=(Modular r) { if ((val += r.val) >= M) val -= M; return *this; }
        constexpr Modular& operator-=(Modular r) { if (r.val > val) val += M; val -= r.val; return *this; }
        template <class T>
        constexpr enable_if_t<is_integral_v<T, Modular>> operator+=(T r) { return *this += Modular(r); }
        template <class T>
        constexpr enable_if_t<is_integral_v<T, Modular>> operator-=(T r) { return *this -= Modular(r); }

        constexpr Modular operator+(Modular r) const { return Modular(*this) += r; }
        constexpr Modular operator-(Modular r) const { return Modular(*this) -= r; }
        constexpr Modular operator+() const { return *this; }
        constexpr Modular operator-() const { return {val ? M - val : val, Unchecked{}}; }
        constexpr Modular& operator++() { if (++val == M) val = 0; return *this; }
        constexpr Modular& operator--() { if (!val--) val = M - 1; return *this; }
        constexpr Modular operator++(int) { auto r = *this; ++*this; return r; }
        constexpr Modular operator--(int) { auto r = *this; --*this; return r; }

        constexpr Modular operator*(Modular r) const { return {(I)((Mul)val * (Mul)r.val % M), Unchecked{}}; }
        template <class T>
        constexpr enable_if_t<is_integral_v<T>, Modular&> operator*=(T r) { return *this *= Modular(r); }
        constexpr Modular& operator*=(Modular r) { return *this = *this * r; }

        constexpr Modular inv() const { return ext_gcd(val, M)[1]; }
        template <class T>
        constexpr enable_if_t<is_integral_v<T>, Modular> pow(T e) const {
            if (!val) return 1;
            Modular a = 1, b = *this;
            for (; e > 0; b *= b, e /= 2)
                if (e % 2) a *= b;
            return a;
        }

        constexpr Modular& operator/=(Modular r) { return *this *= r.inv(); }
        template <class T>
        constexpr enable_if_t<is_integral_v<T>, Modular&> operator/=(T r) { return *this /= Modular(r); }
        constexpr Modular operator/(Modular r) const { return Modular(*this) /= r; }
     };

#define DEFINE_OPS(op) \
        template <class I, I M, class T, class = enable_if_t<is_integral_v<T>>> \
        constexpr auto operator op (Modular<I, M> l, T r) { return l op Modular<I, M>(r); } \
        template <class I, I M, class T, class = enable_if_t<is_integral_v<T>>> \
        constexpr auto operator op (T l, Modular<I, M> r) { return Modular<I, M>(l) op r; }
    DEFINE_OPS(==) DEFINE_OPS(<) DEFINE_OPS(<=)
    DEFINE_OPS(!=) DEFINE_OPS(>) DEFINE_OPS(>=)
    DEFINE_OPS(+) DEFINE_OPS(-) DEFINE_OPS(*) DEFINE_OPS(/)
#undef DEFINE_OPS

    template <class I, I M>
    ostream& operator<<(ostream& out, Modular<I, M> m) { return out << m.val; }
    template <class I, I M>
    istream& operator>>(istream& in, Modular<I, M>& m) {
        // Avoid reading character types
        using T = conditional_t<is_same_v<I, signed char> || is_same_v<I, char>, int, I>;
        T val{};
        in >> val;
        m = Modular<I, M>(val);
        return in;
    }

    template<class I, I M> string to_string(Modular<I, M> m) { return ::to_string(m.val); }

    using MI7 = Modular<int, 1'000'000'007>;
    using MI9 = Modular<int, 998'244'353>;
}

namespace std {
    template <class I, I M>
    struct hash<::cp_lib::Modular<I, M>> {
        size_t operator()(::cp_lib::Modular<I, M> m) const { return hash<I>{}(m.val); }
    };
}

using namespace cp_lib;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    MI9 cur = 0, prev = 1;

    vector<MI9> dp(n);
    rep(i, n) {
        dp[i] = prev / 2;
        cur = cur / 4 + dp[i];
        swap(cur, prev);
    }

    cout << dp.back() << '\n';
    return 0;
}