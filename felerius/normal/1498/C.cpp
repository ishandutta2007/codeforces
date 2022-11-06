// Planar Reflections (https://codeforces.com/contest/1498/problem/C)
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
    template <u32 Mod_, bool Prime = false>
    struct ModInt {
        static constexpr u32 Mod = Mod_;
        static_assert(2 * u64(Mod) <= numeric_limits<u32>::max());
        u32 val = 0;

        static constexpr ModInt raw(u32 x) {
            ModInt m;
            m.val = x;
            return m;
        }

        constexpr ModInt() = default;

        template <class T, enable_if_t<is_integral_v<T> && is_unsigned_v<T>, int> = 0>
        constexpr ModInt(T x) : val(u32(x % Mod)) {}

        template <class T, enable_if_t<is_integral_v<T> && is_signed_v<T>, int> = 0>
        constexpr ModInt(T x) {
            auto y = ll(x) % Mod;
            val = u32(y < 0 ? y + Mod : y);
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

        constexpr ModInt operator*(ModInt r) const { return u64(val) * r.val; }
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
        template <class T, u32 Mod, bool Prime, class = enable_if_t<is_integral_v<T>>> \
        constexpr auto operator op (T l, ModInt<Mod, Prime> r) { return ModInt<Mod, Prime>(l) op r; }
    DEFINE_OP(==) DEFINE_OP(<) DEFINE_OP(<=) DEFINE_OP(!=) DEFINE_OP(>) DEFINE_OP(>=)
    DEFINE_OP(+) DEFINE_OP(-) DEFINE_OP(*) DEFINE_OP(/)
#undef DEFINE_OP

    template <u32 Mod, bool Prime>
    ostream& operator<<(ostream& out, ModInt<Mod, Prime> m) { return out << m.val; }

    template <u32 Mod, bool Prime>
    istream& operator>>(istream& in, ModInt<Mod, Prime>& m) {
        u32 val; in >> val;
        m = val;
        return in;
    }

    using MI7 = ModInt<1'000'000'007, true>;
    using MI9 = ModInt<998'244'353, true>;

    namespace _math_detail {
        template <u32 Mod, bool Prime>
        struct mod_int_info<ModInt<Mod, Prime>> {
            static constexpr u32 mod() { return Mod; }
        };
    }
}

namespace std {
    template <u32 Mod, bool Prime>
    struct hash<::cp_lib::ModInt<Mod, Prime>> {
        size_t operator()(::cp_lib::ModInt<Mod, Prime> m) const { return hash<u32>{}(m.val); }
    };
}
// end "cp-lib/math/modular.hpp"

using namespace cp_lib;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector dp(k, vector(n, MI7(0)));
        MI7 ans = 1;
        rep(i, n)
            dp[k - 1][i] = 1;
        repr(i, k - 1, 1) {
            rep(j, n) {
                // we spawn dp[i][j] many D(i) particles at plane j
                ans += dp[i][j];
                if ((k - i) % 2) {
                    // going left
                    dp[i - 1][0] += dp[i][j];
                    dp[i - 1][j] -= dp[i][j];
                } else {
                    // going right
                    if (j + 1 < n)
                        dp[i - 1][j + 1] += dp[i][j];
                }
            }

            partial_sum(all(dp[i - 1]), begin(dp[i - 1]));
        }

        cout << ans << '\n';
    }

    return 0;
}