// Cut (https://codeforces.com/contest/1516/problem/D)
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
// begin "cp-lib/math/factorize.hpp"
// begin "primality.hpp"
// begin "montgomery.hpp"
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

namespace cp_lib {
    namespace _montgomery_detail {
        constexpr array<u32, 2> mul(u32 a, u32 b) { u64 r = u64(a) * b; return {u32(r >> 32), u32(r)}; }
        constexpr array<u64, 2> mul(u64 a, u64 b) { auto r = (unsigned __int128)a * b; return {u64(r >> 64), u64(r)}; }
    }

    template <class T, class Tag = void>
    struct MontInt {
        static_assert(is_same_v<T, u32> || is_same_v<T, u64>);
        static constexpr int LOGW = __builtin_ctz(sizeof(T) * 8);
        static T mod, inv, r2;
        static MontInt one;

        static void set_mod(T n) {
            cp_lib_assert(n % 2);
            mod = n, inv = 1, r2 = -n % n;
            rep(_, LOGW) inv *= 2 - n * inv;
            rep(_, 4) r2 <<= 1, r2 -= (r2 >= mod) * mod;
            rep(_, LOGW - 2) r2 = mul(r2, r2);
            one = MontInt(1);
        }

        static T sub(T a, T b) { return b > a ? a + mod - b : a - b; }
        static T reduce(array<T, 2> x) { return sub(x[0], _montgomery_detail::mul(x[1] * inv, mod)[0]); }
        static T mul(T a, T b) { return reduce(_montgomery_detail::mul(a, b)); }
        static auto raw(T v) { MontInt i; i.val = v; return i; }

        T val = 0;

        MontInt() = default;
        explicit MontInt(T v) : val(mul(v, r2)) { cp_lib_assert(val < mod); }

        MontInt& operator+=(MontInt r) { val += r.val; val -= (val >= mod ? mod : 0); return *this; }
        MontInt& operator-=(MontInt r) { val = sub(val, r.val); return *this; }
        MontInt& operator*=(MontInt r) { val = mul(val, r.val); return *this; }
        MontInt operator+(MontInt r) const { return MontInt(*this) += r; }
        MontInt operator-(MontInt r) const { return MontInt(*this) -= r; }
        MontInt operator*(MontInt r) const { return MontInt(*this) *= r; }
        constexpr MontInt& operator++() { return *this += one; }
        constexpr MontInt& operator--() { return *this -= one; }
        constexpr MontInt operator++(int) { auto r = *this; ++*this; return r; }
        constexpr MontInt operator--(int) { auto r = *this; --*this; return r; }

#define DEFINE_CMP(op) bool operator op (MontInt r) const { return val op r.val; }
        DEFINE_CMP(==) DEFINE_CMP(<) DEFINE_CMP(<=) DEFINE_CMP(!=) DEFINE_CMP(>) DEFINE_CMP(>=)
#undef DEFINE_CMP

        template <class I, class = enable_if_t<is_integral_v<I>>>
        explicit operator I() const { return T(reduce({0, val})); }

        template <class I>
        enable_if_t<is_integral_v<T>, MontInt> pow(I e) const {
            MontInt r(1), b = *this;
            for (; e; b *= b, e /= 2)
                if (e & 1) r *= b;
            return r;
        }
    };

    template <class T, class Tag> T MontInt<T, Tag>::mod{};
    template <class T, class Tag> T MontInt<T, Tag>::inv{};
    template <class T, class Tag> T MontInt<T, Tag>::r2{};
    template <class T, class Tag> MontInt<T, Tag> MontInt<T, Tag>::one{};

    template <class T, class Tag>
    ostream& operator<<(ostream& out, MontInt<T, Tag> m) { return out << m.val; }

    namespace _math_detail {
        template <class T, class Tag>
        struct mod_int_info<MontInt<T, Tag>> {
            static T mod() { return MontInt<T, Tag>::mod; }
        };
    }
}
// end "montgomery.hpp"

namespace cp_lib::_primes_detail {
    constexpr array<u32, 3> A32 = {2, 7, 61};
    constexpr array<u64, 7> A64 = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    struct Tag;
    template <class T> using MI = MontInt<T, Tag>;

    template <class T, size_t I>
    constexpr bool miller_rabin(T n, const array<T, I>& as) {
        if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
        MI<T>::set_mod(n);
        int s = __builtin_ctzll(n - 1);
        T d = (n - 1) >> s;
        MI<T> e(1), f(n - 1);
        trav(a, as) {
            auto p = MI<T>(a % n).pow(d);
            if (a % n == 0 || p == e || p == f) continue;
            for (int i = s - 1; p != f && i >= 0; --i)
                p *= p;
            if (p != f) return false;
        }
        return true;
    }

    constexpr bool miller_rabin(u32 n) { return miller_rabin(n, A32); }
    constexpr bool miller_rabin(u64 n) { return miller_rabin(n, A64); }
}

namespace cp_lib {
    constexpr bool is_prime(u64 n) {
        return n < (1 << 30) ? _primes_detail::miller_rabin(u32(n)) : _primes_detail::miller_rabin(n);
    }
}
// end "primality.hpp"

namespace cp_lib::_primes_detail {
    u64 binary_gcd(u64 a, u64 b) {
        if (!a || !b) return a | b;
        int shift = __builtin_ctzll(a | b);
        a >>= __builtin_ctzll(a);
        do {
            b >>= __builtin_ctzll(b);
            if (a > b) swap(a, b);
            b -= a;
        } while (b);
        return a << shift;
    }

    template <class T>
    T pollard(T n) {
        if (!(n % 2)) return 2;
        if (miller_rabin(n)) return n;
        if (MI<T>::mod != n) MI<T>::set_mod(n);
        MI<T> zero(0), one(1), x = zero, y = zero, prd = one, q;
        T t = 160, i = 0;
        auto f = [one](MI<T> z) { return z * z + one; };
        while (t++ % 200 || binary_gcd(u64(prd), n) == 1) {
            if (x == y) x = MI<T>::raw(++i), y = f(x);
            if ((q = prd * (x - y)) != zero) prd = q;
            x = f(x), y = f(f(y));
        }
        return T(binary_gcd(u64(prd), n));
    }
}

namespace cp_lib {
    vector<u64> factorize(u64 n) {
        if (n == 1) return {};
        vector<u64> f = {n};
        for (int i = 0; i < sz(f); ++i) {
            while (1) {
                u64 x = f[i] < (1u << 30) ? _primes_detail::pollard(u32(f[i])) : _primes_detail::pollard(f[i]);
                if (f[i] == x) break;
                f[i] /= x;
                f.push_back(x);
            }
        }
        sort(all(f));
        return f;
    }
}
// end "cp-lib/math/factorize.hpp"

using namespace cp_lib;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vector a(n, 0);
    trav(ai, a) cin >> ai;

    vector last_with_factor(100'005, n);
    vector dp(n, array<int, 20>{});

    repr(i, n - 1) {
        int block_r = n;
        auto factors = factorize(a[i]);
        trav(factor, factors)
            block_r = min(block_r, last_with_factor[factor]);
        if (i + 1 < n)
            block_r = min(block_r, dp[i + 1][0]);

        trav(factor, factors)
            last_with_factor[factor] = i;

        dp[i][0] = block_r;
        rep(j, 1, 20)
            dp[i][j] = (dp[i][j - 1] == n ? n : dp[dp[i][j - 1]][j - 1]);
    }

    while (q--) {
        int l, r; cin >> l >> r; --l;
        int cnt = 0;
        repr(i, 19)
            if (dp[l][i] < r)
                cnt += (1 << i), l = dp[l][i];

        cout << (cnt + 1) << '\n';
    }

    return 0;
}