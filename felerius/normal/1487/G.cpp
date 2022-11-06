#pragma GCC optimize("fast-math")
// begin "cp-lib/prelude.hpp"
#include <bits/stdc++.h>
#ifdef LOCAL
#  include <dbg.h>
#else
#  define dbg(...) do {} while (0)
#endif

#define cp_lib_4th(_1, _2, _3, x, ...)  x
#define cp_lib_rep(i, l, r)             for (int i = (l); (i) < (r); ++(i))
#define cp_lib_rep0(i, r)               cp_lib_rep(i, 0, r)
#define rep(...)                        cp_lib_4th(__VA_ARGS__, cp_lib_rep, cp_lib_rep0, _)(__VA_ARGS__)
#define cp_lib_repr(i, r, l, ...)       for (int i = (r); (i) >= (l); --(i))
#define repr(...)                       cp_lib_repr(__VA_ARGS__, 0)
#define all(a)                          ::begin(a),::end(a)
#define trav(a, b)                      for (auto&& a : (b))

using namespace std;
using ll = long long;
using ld = long double;
[[maybe_unused]] static constexpr int INF = int(1e9 + 5);
[[maybe_unused]] static constexpr ll INFL = ll(INF) * INF;
template <class C> int sz(const C& c) { return int(::size(c)); }
// end "cp-lib/prelude.hpp"
// begin "cp-lib/io.hpp"
// begin "_assert.hpp"
#ifdef CP_LIB_DEBUG
#define cp_lib_assert(expr) \
    do { if (!(expr)) { \
        ::cerr << "assertion failed: " << #expr << " (" << __FILE__ << ':' << __LINE__ << ")\n"; \
        ::abort(); \
    } } while (0)
#else
#define cp_lib_assert(expr)
#endif
// end "_assert.hpp"
// begin "_type-meta.hpp"
#if __cplusplus < 202002L
struct identity { template <class T> constexpr T&& operator()(T&& t) const noexcept { return forward<T>(t); }; };
template <class T> using remove_cvref_t = remove_cv_t<remove_reference_t<T>>;
#endif

namespace cp_lib_type_meta {
    struct NoOp { template <class... Args> void operator()(Args&&...) const noexcept {} };
    template <class T, class = void> struct is_tuple_like : false_type {};
    template <class T> struct is_tuple_like<T, void_t<tuple_element_t<0, T>>> : true_type {};
}
// end "_type-meta.hpp"
// begin "modint/_detect.hpp"
namespace cp_lib_modint { struct ModIntTag {}; }
// end "modint/_detect.hpp"
#include <unistd.h>

namespace cp_lib_io {
    constexpr int BUF_SIZE = 1 << 20;
    array<char, BUF_SIZE> ibuf, obuf;
    char *iptr = data(ibuf), *iend = iptr, *optr = data(obuf);

    template <class T> struct is_std_array : false_type {};
    template <class T, size_t I> struct is_std_array<array<T, I>> : true_type {};

    void flush() { write(STDOUT_FILENO, begin(obuf), optr - begin(obuf)); optr = begin(obuf); }
    void ensure_write(int l) { if (end(obuf) - optr < l) flush(); }
    int _flush_atexit = []{ atexit(flush); return 0; }();
    void refill() {
        memmove(begin(ibuf), iptr, iend - iptr);
        iend -= iptr - begin(ibuf);
        iptr = begin(ibuf);
        iend += read(STDIN_FILENO, iend, end(ibuf) - iend);
    }
    void skip_ensure_read(int l) {
        do {
            while (iptr != iend && *iptr <= ' ') ++iptr;
            if (iend - iptr < l) refill();
        } while (*iptr <= ' ');
    }

    template <class T, class T2 = remove_reference_t<remove_cv_t<T>>>
    void print(T&& val) {
        if constexpr (is_same_v<T2, char>)
            ensure_write(2), *optr++ = val;
        else if constexpr (is_integral_v<T2> && !is_same_v<T2, bool>) {
            ensure_write(numeric_limits<T>::digits10 + 1 + is_signed_v<T2>);
            if (val < 0) { *optr++ = '-'; print(make_unsigned_t<T2>(-make_unsigned_t<T2>(val))); return; }
            array<char, 128> tmp;
            char* tptr = end(tmp);
            remove_const_t<T2> val_copy = val;
            do { *--tptr = char('0' + val_copy % 10), val_copy /= 10; } while (val_copy);
            memcpy(optr, tptr, end(tmp) - tptr);
            optr += end(tmp) - tptr;
#if __cpp_lib_to_chars >= 201611
        } else if constexpr (is_floating_point_v<T2>) {
            ensure_write(64);
            auto res = to_chars(optr, end(obuf), val, chars_format::fixed, 30);
            cp_lib_assert(res.ec == errc());
            optr = res.ptr;
#endif
        } else if constexpr (is_convertible_v<T, string_view>) {
            string_view sv(val);
            if (sz(sv) + 1 <= end(obuf) - optr)
                memcpy(optr, data(sv), sz(sv)), optr += sz(sv);
            else
                flush(), write(STDOUT_FILENO, data(sv), sz(sv));
        } else {
            if constexpr (is_same_v<T2, bool> || is_same_v<T2, vector<bool>::reference>)
                print(int(val));
            else if constexpr (is_base_of_v<cp_lib_modint::ModIntTag, T2>)
                print(decltype(T2::mod())(val));
            else if constexpr (cp_lib_type_meta::is_tuple_like<T2>() && !is_std_array<T2>())
                apply([](auto&&... items) { (print(items), ...); }, forward<T>(val));
            else
                trav(item, val) print(item);
            return;
        }
        *optr++ = ' ';
    }

    template <class T>
    void read(T& val) {
        if constexpr (is_same_v<T, char>)
            skip_ensure_read(1), val = *iptr++;
        else if constexpr (is_same_v<T, bool> || is_same_v<T, vector<bool>::reference>) {
            uint8_t ival; read(ival), val = bool(ival);
        } else if constexpr (is_base_of_v<cp_lib_modint::ModIntTag, T>) {
            ll ival; read(ival); val = T(ival);
        } else if constexpr (is_integral_v<T>) {
            skip_ensure_read(numeric_limits<T>::digits10 + 1 + is_signed_v<T>);
            if (is_signed_v<T> && *iptr == '-') {
                ++iptr;
                make_unsigned_t<T> uval;
                read(uval);
                val = T(-uval);
            } else {
                val = 0;
                while (iptr != iend && *iptr > ' ') val = T(10 * val + (*iptr++ - '0'));
            }
#if __cpp_lib_to_chars >= 201611
        } else if constexpr (is_floating_point_v<T>) {
            skip_ensure_read(128);
            auto res = from_chars(iptr, iend, val);
            assert(res.ec == errc());
            iptr = const_cast<char*>(res.ptr);
#endif
        } else if constexpr (is_same_v<T, string>) {
            val = string();
            skip_ensure_read(1);
            do {
                auto* after = iptr;
                while (after != iend && *after > ' ') ++after;
                copy(iptr, after, back_inserter(val));
                if ((iptr = after) == iend)
                    refill();
                else
                    break;
            } while (iptr != iend);
        } else if constexpr (cp_lib_type_meta::is_tuple_like<T>() && !is_std_array<T>())
            apply([](auto&... items) { (read(items), ...); }, val);
        else
            trav(item, val) read(item);
    }
}

using cp_lib_io::flush;

template <class... Args>
void print(Args&&... args) { (cp_lib_io::print(forward<Args>(args)), ...); }

template <class... Args>
void println(Args&&... args) {
    if (sizeof...(Args) > 0)
        (cp_lib_io::print(forward<Args>(args)), ...), *(cp_lib_io::optr - 1) = '\n';
    else
        cp_lib_io::ensure_write(1), *cp_lib_io::optr++ = '\n';
}

template <class... Args>
void printlns(Args&&... args) {
    ((cp_lib_io::print(forward<Args>(args)), *(cp_lib_io::optr - 1) = '\n'), ...);
}

template <class... Args>
void read(Args&... args) { (cp_lib_io::read(args), ...); }
// end "cp-lib/io.hpp"
// begin "cp-lib/modint/static-montgomery.hpp"
// begin "_base.hpp"
// begin "../math/ext-gcd.hpp"
template <class I>
constexpr enable_if_t<is_signed_v<I>, array<I, 3>> ext_gcd(I a, I b) {
    I x(1), y(0), x1(0), y1(1);
    while (b) {
        I t = a / b;
        tie(x, x1) = pair(x1, x - t * x1);
        tie(y, y1) = pair(y1, y - t * y1);
        tie(a, b) = pair(b, a - t * b);
    }
    return {a, x, y};
}
// end "../math/ext-gcd.hpp"

namespace cp_lib_modint {
    template <class Self, class Int>
    struct Base : ModIntTag {
        static_assert(is_same_v<Int, uint32_t> || is_same_v<Int, uint64_t>);

        friend constexpr Self operator+(Self l, Self r) { return l += r; }
        friend constexpr Self operator-(Self l, Self r) { return l -= r; }
        friend constexpr Self operator*(Self l, Self r) { return l *= r; }
        friend constexpr Self operator/(Self l, Self r) { return l * r.inv(); }
        friend constexpr Self& operator/=(Self& l, Self r) { return l *= r.inv(); }
        friend constexpr Self operator+(Self x) { return x; }
        friend constexpr Self operator-(Self x) { return Self(0) - x; }
        friend constexpr Self& operator++(Self& x) { return x += Self(1); }
        friend constexpr Self& operator--(Self& x) { return x -= Self(1); }
        friend constexpr Self operator++(Self& x, int) { auto y = x; ++x; return y; }
        friend constexpr Self operator--(Self& x, int) { auto y = x; --x; return y; }

#define CP_LIB_DEF(op) \
        template <class T, enable_if_t<is_integral_v<T>, int> = 0> \
        friend constexpr auto operator op(T l, Self r) { return Self(l) op r; }
        CP_LIB_DEF(==) CP_LIB_DEF(!=) CP_LIB_DEF(<) CP_LIB_DEF(+) CP_LIB_DEF(-) CP_LIB_DEF(*) CP_LIB_DEF(/)
#undef CP_LIB_DEF

        template <class T>
        constexpr enable_if_t<is_integral_v<T>, Self> pow(T e) const {
            Self r(1), b(*(Self*)(this));
            for (; e; b *= b, e >>= 1)
                if (e & 1) r *= b;
            return r;
        }

        constexpr optional<Self> try_inv() const {
            if (Self::is_prime())
                return *(Self*)this == Self() ? nullopt : optional(pow(Self::mod() - 2));
            auto [g, x, _] = ext_gcd(ll(*(Self*)this), ll(Self::mod()));
            return (abs(g) == 1 ? optional(Self(x)) : nullopt);
        }
        constexpr Self inv() const {
            if (Self::is_prime()) return pow(Self::mod() - 2);
            auto [g, x, _] = ext_gcd(ll(*(Self*)this), ll(Self::mod()));
            cp_lib_assert(abs(g) == 1);
            return x;
        }

        friend ostream& operator<<(ostream& out, Self m) { return out << uint64_t(m); }
        friend istream& operator>>(istream& in, Self& m) { ll x; in >> x; m = x; return in; }

     protected:
        Int i = 0;
    };

    template <class Int> using Wide = conditional_t<is_same_v<uint64_t, Int>, unsigned __int128, uint64_t>;
}
// end "_base.hpp"

namespace cp_lib_modint {
    template <class Int, Int Mod, bool IsPrime>
    class StaticMontgomery : public Base<StaticMontgomery<Int, Mod, IsPrime>, Int> {
        static_assert(Mod % 2 && Mod < (1ull << (sizeof(Int) * 8 - 2)));
        static constexpr Int INV = []{
            Int inv = Mod;
            rep(_, __builtin_ctz(sizeof(Int) * 8) - 1) inv *= 2 - Mod * inv;
            return inv;
        }();
        static constexpr Int R2 = Int(-Wide<Int>(Mod) % Mod);
        static constexpr Int reduce(Wide<Int> x) {
            return Int((x - Int(x) * INV * Wide<Int>(Mod)) >> (sizeof(Int) * 8)) + Mod;
        }
        constexpr Int norm(Int x) const { return x >= Mod ? x - Mod : x; }

     public:
        static constexpr Int mod() { return Mod; }
        static constexpr bool is_prime() { return IsPrime; }

        StaticMontgomery() = default;
        template <class T, enable_if_t<is_unsigned_v<T>, int> = 0>
        constexpr StaticMontgomery(T x) { this->i = reduce(Wide<Int>(uint64_t(x) % Mod) * R2); }
        template <class T, enable_if_t<is_signed_v<T>, int> = 0>
        constexpr StaticMontgomery(T x) { this->i = reduce(Wide<Int>(ll(x) % ll(Mod) + ll(Mod)) * R2); }

        template <class T, enable_if_t<is_integral_v<T>, int> = 0>
        constexpr explicit operator T() const { return T(norm(reduce(this->i))); }
        constexpr Int raw() const { return norm(this->i); }

        constexpr bool operator==(StaticMontgomery r) const { return norm(this->i) == norm(r.i); }
        constexpr bool operator!=(StaticMontgomery r) const { return norm(this->i) != norm(r.i); }
        constexpr bool operator<(StaticMontgomery r) const { return norm(this->i) < norm(r.i); }

        constexpr StaticMontgomery& operator+=(StaticMontgomery r) {
            if ((this->i += r.i) >= 2 * Mod)
                this->i -= 2 * Mod;
            return *this;
        }
        constexpr StaticMontgomery& operator-=(StaticMontgomery r) {
            if (make_signed_t<Int>(this->i -= r.i) < 0)
                this->i += 2 * Mod;
            return *this;
        }
        constexpr StaticMontgomery& operator*=(StaticMontgomery r) {
            this->i = reduce(Wide<Int>(this->i) * r.i);
            return *this;
        }
    };
}
template <uint32_t Mod, bool IsPrime> using StaticMontgomeryInt = cp_lib_modint::StaticMontgomery<uint32_t, Mod, IsPrime>;
template <uint64_t Mod, bool IsPrime> using StaticMontgomeryInt64 = cp_lib_modint::StaticMontgomery<uint64_t, Mod, IsPrime>;
// end "cp-lib/modint/static-montgomery.hpp"

int main() {
    using MI = StaticMontgomeryInt<998'244'353, true>;
    int n; read(n);
    array<int, 26> c;
    read(c);
    int max_cnt = (n + 1) / 2 + 5;

    // dp1[l][n][b1][b2] = #beautiful strings of len l containing a specific char n times
    //                     (b1: second to last char is specific char, b2: same for last char).
    vector dp1(n + 1, vector(max_cnt + 1, array<array<MI, 2>, 2>()));
    rep(b1, 2) rep(b2, 2)
        dp1[2][b1 + b2][b1][b2] = (b1 ? 1 : 25) * (b2 ? 1 : 25);
    rep(l, 3, n + 1) rep(x, max_cnt + 1) rep(b, 2) {
        dp1[l][x][b][0] = 25 * dp1[l - 1][x][1][b] + 24 * dp1[l - 1][x][0][b];
        if (x)
            dp1[l][x][b][1] = dp1[l - 1][x - 1][0][b];
    }

    vector cnt1(max_cnt + 1, MI(0));
    rep(i, max_cnt + 1) rep(b1, 2) rep(b2, 2)
        cnt1[i] += dp1[n][i][b1][b2];
    partial_sum(rbegin(cnt1), rend(cnt1), rbegin(cnt1));

    // dp2[l][n1][n2][b1][b2] = #beautiful strings of len l containing a specific char n1 times and
    //                          another n2 times, with b1/b2 denoting which type the last two chars
    //                          belong to.
    vector dp2(n + 1, vector(max_cnt + 1, vector(max_cnt + 1, array<array<MI, 3>, 3>())));
    rep(b1, 3) rep(b2, 3)
        dp2[2][(b1 == 1) + (b2 == 1)][(b1 == 2) + (b2 == 2)][b1][b2] = (b1 ? 1 : 24) * (b2 ? 1 : 24);
    rep(l, 3, n + 1) rep(x1, max_cnt + 1) rep(x2, max_cnt + 1) rep(b, 3) {
        dp2[l][x1][x2][b][0] = 24 * (dp2[l - 1][x1][x2][1][b] + dp2[l - 1][x1][x2][2][b]) +
                               23 * dp2[l - 1][x1][x2][0][b];
        if (x1)
            dp2[l][x1][x2][b][1] = dp2[l - 1][x1 - 1][x2][0][b] + dp2[l - 1][x1 - 1][x2][2][b];
        if (x2)
            dp2[l][x1][x2][b][2] = dp2[l - 1][x1][x2 - 1][0][b] + dp2[l - 1][x1][x2 - 1][1][b];
    }

    vector cnt2(max_cnt + 1, vector(max_cnt + 1, MI(0)));
    rep(i, max_cnt + 1) rep(j, max_cnt + 1) rep(b1, 3) rep(b2, 3)
        cnt2[i][j] += dp2[n][i][j][b1][b2];

    MI test = 0;
    rep(i, max_cnt + 1) rep(b1, 2) rep(b2, 2)
        test += dp1[6][i][b1][b2];
    dbg(test);

    MI ans = 26 * 26 * MI(25).pow(n - 2);
    rep(i, 26)
        if (c[i] < max_cnt)
            ans -= cnt1[c[i] + 1];
    rep(i, 26) rep(j, i + 1, 26)
        rep(c1, c[i] + 1, max_cnt + 1) rep(c2, c[j] + 1, max_cnt + 1)
            ans += cnt2[c1][c2];

    println(ans);
}