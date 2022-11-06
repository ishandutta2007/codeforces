// Mocha and Stars (https://codeforces.com/contest/1559/problem/E)
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
// begin "cp-lib/math/combinatorics.hpp"
namespace cp_lib {
    template <class MI, int N>
    struct Combinatorics {
        array<MI, N + 1> f, fi;

        template <class Inv>
        void build(Inv inv) {
            MI m; int i;
            f[0] = MI(1);
            for (i = 1, m = f[0]; i <= N; ++i, ++m)
                f[i] = f[i - 1] * m;
            fi[N] = inv(f[N]);
            for (i = N, m = MI(N); i; --i, --m)
                fi[i - 1] = m * fi[i];
        }

        Combinatorics() { build([](MI i) { return i.inv(); }); }
        template <class Inv> explicit Combinatorics(Inv inv) { build(inv); }

        MI binom(int n, int k) const { return (n >= k && k >= 0 ? f[n] * fi[n - k] * fi[k] : MI(0)); }
        MI stars_bars(int n, int k) const { return binom(n + k - 1, k - 1); }
        MI catalan(int n) const { return f[2 * n] * fi[n + 1] * fi[n]; }
        MI catalan(int n, int k) const { return MI(k + 1) * f[2 * n + k] * fi[n + k + 1] * fi[n]; }

        template <class C>
        MI multinom(int n, C&& c) const {
            MI res = f[n];
            trav(k, c) res *= fi[k];
            return res;
        }
    };
}
// end "cp-lib/math/combinatorics.hpp"
// begin "cp-lib/math/modular.hpp"
// begin "../_assert.hpp"
#ifdef CP_LIB_DEBUG
#define cp_lib_assert(expr) \
    do { if (!(expr)) { \
        ::cerr << "assertion failed: " << #expr << " (" << __FILE__ << ':' << __LINE__ << ")\n"; \
        ::abort(); \
    } } while (0)
#else
#define cp_lib_assert(expr)
#endif
// end "../_assert.hpp"
// begin "_detail/mod-int-info.hpp"
namespace cp_lib::_math_detail {
    template <class T>
    struct mod_int_info {};

    template <class, class = void>
    struct is_mod_int : false_type {};

    template <class T>
    struct is_mod_int<T, void_t<decltype(mod_int_info<T>::mod())>> : true_type {};

    template <class T>
    constexpr bool is_mod_int_v = is_mod_int<T>::value;
}
// end "_detail/mod-int-info.hpp"
// begin "ext-gcd.hpp"
namespace cp_lib {
    // Returns (g, x, y) with |g| = gcd(a, b) and g = a * x + b * y.
    // If both arguments are positive/negative, g also has that sign.
    // Also: |x| < |b / g|, |y| < |a / g|
    template <class I, class = enable_if_t<is_integral_v<I> && is_signed_v<I>>>
    constexpr array<I, 3> ext_gcd(I a, I b) {
        if (!a) return {b, 0, 1};
        auto [d, x1, y1] = ext_gcd(b % a, a);
        return {d, y1 - (b / a) * x1, x1};
    }
}
// end "ext-gcd.hpp"

namespace cp_lib {
    template <uint32_t Mod_, bool Prime = false>
    struct ModInt {
        static constexpr uint32_t Mod = Mod_;
        static_assert(2 * uint64_t(Mod) <= numeric_limits<uint32_t>::max());
        uint32_t val = 0;

        static constexpr ModInt raw(uint32_t x) {
            ModInt m;
            m.val = x;
            return m;
        }

        constexpr ModInt() = default;

        template <class T, enable_if_t<is_integral_v<T> && is_unsigned_v<T>, int> = 0>
        constexpr ModInt(T x) : val(uint32_t(x % Mod)) {}

        template <class T, enable_if_t<is_integral_v<T> && is_signed_v<T>, int> = 0>
        constexpr ModInt(T x) {
            auto y = ll(x) % Mod;
            val = uint32_t(y < 0 ? y + Mod : y);
        }

        template <class T, class = enable_if_t<is_integral_v<T>>>
        constexpr explicit operator T() const { return T(val); }

#define DEFINE_CMP(op) constexpr bool operator op (ModInt r) const { return val op r.val; }
        DEFINE_CMP(==) DEFINE_CMP(<) DEFINE_CMP(<=) DEFINE_CMP(!=) DEFINE_CMP(>) DEFINE_CMP(>=)
#undef DEFINE_CMP

        constexpr ModInt& operator+=(ModInt r) { if ((val += r.val) >= Mod) val -= Mod; return *this; }
        constexpr ModInt& operator-=(ModInt r) { if (r.val > val) val += Mod; val -= r.val; return *this; }
        constexpr ModInt operator+(ModInt r) const { return ModInt(*this) += r; }
        constexpr ModInt operator-(ModInt r) const { return ModInt(*this) -= r; }
        constexpr ModInt operator+() const { return *this; }
        constexpr ModInt operator-() const { return raw(val ? Mod - val : val); }
        constexpr ModInt& operator++() { if (++val == Mod) val = 0; return *this; }
        constexpr ModInt& operator--() { if (!val--) val = Mod - 1; return *this; }
        constexpr ModInt operator++(int) { auto r = *this; ++*this; return r; }
        constexpr ModInt operator--(int) { auto r = *this; --*this; return r; }

        constexpr ModInt operator*(ModInt r) const { return uint64_t(val) * r.val; }
        constexpr ModInt& operator*=(ModInt r) { return *this = *this * r; }

        template <class T>
        constexpr enable_if_t<is_integral_v<T>, ModInt> pow(T e) const {
            ModInt r = 1, b = *this;
            for (; e; b *= b, e /= 2)
                if (e % 2) r *= b;
            return r;
        }

        constexpr ModInt inv() const {
            if constexpr (Prime)
                return pow(Mod - 2);
            auto [g, x, _] = ext_gcd(ll(val), ll(Mod));
            cp_lib_assert(abs(g) == 1);
            return x;
        }

        constexpr ModInt& operator/=(ModInt r) { return *this *= r.inv(); }
        constexpr ModInt operator/(ModInt r) const { return ModInt(*this) /= r; }
    };

#define DEFINE_OP(op) \
        template <class T, uint32_t Mod, bool Prime, class = enable_if_t<is_integral_v<T>>> \
        constexpr auto operator op (T l, ModInt<Mod, Prime> r) { return ModInt<Mod, Prime>(l) op r; }
    DEFINE_OP(==) DEFINE_OP(<) DEFINE_OP(<=) DEFINE_OP(!=) DEFINE_OP(>) DEFINE_OP(>=)
    DEFINE_OP(+) DEFINE_OP(-) DEFINE_OP(*) DEFINE_OP(/)
#undef DEFINE_OP

    template <uint32_t Mod, bool Prime>
    ostream& operator<<(ostream& out, ModInt<Mod, Prime> m) { return out << m.val; }

    template <uint32_t Mod, bool Prime>
    istream& operator>>(istream& in, ModInt<Mod, Prime>& m) {
        uint32_t val; in >> val;
        m = val;
        return in;
    }

    using MI7 = ModInt<1'000'000'007, true>;
    using MI9 = ModInt<998'244'353, true>;

    namespace _math_detail {
        template <uint32_t Mod, bool Prime>
        struct mod_int_info<ModInt<Mod, Prime>> {
            static constexpr auto mod() { return Mod; }
        };
    }
}

namespace std {
    template <uint32_t Mod, bool Prime>
    struct hash<::cp_lib::ModInt<Mod, Prime>> {
        size_t operator()(::cp_lib::ModInt<Mod, Prime> m) const { return hash<uint32_t>{}(m.val); }
    };
}
// end "cp-lib/math/modular.hpp"

using namespace cp_lib;

Combinatorics<MI9, 100'000> comb;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector l(n, 0), r(n, 0);
    rep(i, n)
        cin >> l[i] >> r[i];

    vector div(m + 1, MI9(0));
    for (int i = 1; i * n <= m; ++i) {
        int mn_sum = 0;
        vector incr(n, 0);
        bool pos = true;
        rep(j, n) {
            int mn = i * ((l[j] + i - 1) / i);
            pos &= (mn <= r[j]);
            mn_sum += mn;
            incr[j] = (r[j] - mn) / i;
        }

        if (!pos || mn_sum > m)
            continue;

        int free = (m - mn_sum) / i;
        vector dp(free + 1, MI9(0)), dp_pref = dp;
        dp[0] = 1;
        trav(in, incr) {
            partial_sum(all(dp), begin(dp_pref));
            rep(j, free + 1)
                dp[j] = dp_pref[j] - (j > in ? dp_pref[j - in - 1] : MI9(0));
        }

        div[i] = accumulate(all(dp), MI9(0));
    }

    repr(i, m, 1)
        for (int j = 2 * i; j <= m; j += i)
            div[i] -= div[j];
    cout << div[1] << '\n';
}