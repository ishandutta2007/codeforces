// Permutation Counting (https://codeforces.com/contest/1671/problem/F)
#pragma GCC optimize("fast-math")

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


#ifdef CP_LIB_DEBUG
#define cp_lib_assert(expr) \
    do { if (!(expr)) { \
        ::cerr << "assertion failed: " << #expr << " (" << __FILE__ << ':' << __LINE__ << ")\n"; \
        ::abort(); \
    } } while (0)
#else
#define cp_lib_assert(expr)
#endif


#if __cplusplus < 202002L
struct identity { template <class T> constexpr T&& operator()(T&& t) const noexcept { return forward<T>(t); }; };
template <class T> using remove_cvref_t = remove_cv_t<remove_reference_t<T>>;
#endif

namespace cp_lib_type_meta {
    struct NoOp { template <class... Args> void operator()(Args&&...) const noexcept {} };
    template <class T, class = void> constexpr bool is_tuple_like = false;
    template <class T> constexpr bool is_tuple_like<T, void_t<tuple_element_t<0, T>>> = true;
}


namespace cp_lib_modint { struct ModIntTag {}; }
#include <unistd.h>

namespace cp_lib_io {
    constexpr int BUF_SIZE = 1 << 20;
    constexpr array<array<char, 4>, 10'000> DIGITS = []{
        array<array<char, 4>, 10'000> digits{};
        for (int i = 3, d = 1; i >= 0; --i, d *= 10)
            rep(j, 10'000)
                digits[j][i] = char('0' + j / d % 10);
        return digits;
    }();
    array<char, BUF_SIZE> ibuf, obuf;
    char *iptr = data(ibuf), *iend = iptr, *optr = data(obuf);

    template <class T> constexpr bool is_std_array = false;
    template <class T, size_t I> constexpr bool is_std_array<array<T, I>> = true;

    void flush() {
        for (auto* p = begin(obuf); p != optr; p += write(STDOUT_FILENO, p, optr - p));
        optr = begin(obuf);
    }
    int _flush_atexit = []{ atexit(flush); return 0; }();

    void refill() {
        memmove(begin(ibuf), iptr, iend - iptr);
        iend -= iptr - begin(ibuf);
        iptr = begin(ibuf);
        iend += read(STDIN_FILENO, iend, end(ibuf) - 1 - iend);
        *iend = '\0';
    }

    template <class T, class T2 = remove_cvref_t<T>>
    void print(T&& val) {
        if (end(obuf) - optr < 64)
            flush();

        if constexpr (is_same_v<T2, char>)
            *optr++ = val;
        else if constexpr (is_same_v<T2, bool> || is_same_v<T2, vector<bool>::reference>)
            return print(int(val));
        else if constexpr (is_integral_v<T2> && is_signed_v<T2>) {
            if (val < 0)
                *optr++ = '-';
            using U = make_unsigned_t<T2>;
            return print(U(val < 0 ? -U(val) : U(val)));
        } else if constexpr (is_integral_v<T2> && is_unsigned_v<T2>) {
            T2 val2 = val;
            array<char, 64> tmp;
            char* tptr = end(tmp);
            while (val2 >= 10'000)
                tptr -= 4, memcpy(tptr, &DIGITS[val2 % 10'000][0], 4), val2 /= T2(10'000);
            int d = (val2 >= 100 ? (val2 >= 1000 ? 4 : 3) : (val2 >= 10 ? 2 : 1));
            memcpy(optr, &DIGITS[val2][4 - d], d);
            memcpy(optr + d, tptr, end(tmp) - tptr);
            optr += d + int(end(tmp) - tptr);
        } else if constexpr (is_floating_point_v<T2>)
            optr += sprintf(optr, "%.30Lf", (long double)val);
        else if constexpr (is_convertible_v<T, string_view>) {
            string_view sv(val);
            if (sz(sv) + 1 <= end(obuf) - optr)
                memcpy(optr, data(sv), sz(sv)), optr += sz(sv);
            else {
                flush();
                for (auto *p = data(sv), *pe = p + sz(sv); p != pe; p += write(STDOUT_FILENO, p, pe - p));
            }
        } else if constexpr (is_base_of_v<cp_lib_modint::ModIntTag, T2>)
            return print(decltype(T2::mod())(val));
        else if constexpr (cp_lib_type_meta::is_tuple_like<T2> && !is_std_array<T2>)
            return apply([](auto&&... items) { (print(items), ...); }, forward<T>(val));
        else {
            trav(item, val)
                print(item);
            return;
        }
        *optr++ = ' ';
    }

    template <class T>
    void read(T& val) {
        do {
            for (; iptr != iend && *iptr <= ' '; ++iptr);
            if (iend - iptr < 64)
                refill();
        } while (*iptr <= ' ');

        auto read_other = [&](auto other) {
            read(other);
            return other;
        };

        if constexpr (is_same_v<T, char>)
            val = *iptr++;
        else if constexpr (is_same_v<T, bool> || is_same_v<T, vector<bool>::reference>) {
            val = bool(read_other(uint8_t()));
        } else if constexpr (is_base_of_v<cp_lib_modint::ModIntTag, T>) {
            val = T(read_other(ll()));
        } else if constexpr (is_integral_v<T>) {
            if (is_signed_v<T> && *iptr == '-')
                ++iptr, val = T(-read_other(make_unsigned_t<T>()));
            else
                for (val = 0; iptr != iend && *iptr > ' '; val = T(10 * val + (*iptr++ & 15)));
        } else if constexpr (is_floating_point_v<T>)
            val = T(strtold(iptr, &iptr));
        else if constexpr (is_same_v<T, string>) {
            val.clear();
            do {
                auto* after = find_if(iptr, iend, [](char c) { return c <= ' '; });
                val.append(iptr, after);
                if ((iptr = after) != iend)
                    break;
                refill();
            } while (iptr != iend);
        } else if constexpr (cp_lib_type_meta::is_tuple_like<T> && !is_std_array<T>)
            apply([](auto&... items) { (read(items), ...); }, val);
        else
            trav(item, val)
                read(item);
    }
}

using cp_lib_io::flush;

template <class... Args>
void print(Args&&... args) { (cp_lib_io::print(forward<Args>(args)), ...); }

template <class... Args>
void println(Args&&... args) {
    if (sizeof...(Args))
        (cp_lib_io::print(forward<Args>(args)), ...), *(cp_lib_io::optr - 1) = '\n';
    else
        print('\n'), --cp_lib_io::optr;
}

template <class... Args>
void read(Args&... args) { (cp_lib_io::read(args), ...); }


template <class T> constexpr inline bool is_pow2(T n) { return n && !(n & (n - 1)); }
template <class T> constexpr inline int floor_log2(T n) { return n ? 63 - __builtin_clzll(n) : 0; }
template <class T> constexpr inline int ceil_log2(T n) { return n ? floor_log2(n) + !is_pow2(n) : 0; }

template <class MI>
class NumberTheoreticTransform {
    int max_exp;
    array<array<array<MI, 30>, 31>, 2> z_step{};

 public:
    explicit NumberTheoreticTransform(MI g) : max_exp(min(30, __builtin_ctzll(MI::mod() - 1))) {
        rep(w, max_exp) {
            auto z_w = g.pow((MI::mod() - 1) >> (w + 1));
            rep(i, w) {
                int diff = (1 << (w - 1 - i)) - (((1 << i) - 1) << (w - i));
                auto z = z_w.pow(abs(diff));
                rep(inv, 2)
                    z_step[inv][w][i] = ((diff < 0) ^ inv ? z.inv() : z);
            }
        }
    }

    template <class It, class ItEnd>
    void ntt_to_rev(It it, ItEnd it_end) {
        int n = int(it_end - it);
        cp_lib_assert(is_pow2(n) && __builtin_ctz(n) <= max_exp);
        for (int k = n >> 1, w = 0; k; k >>= 1, ++w) {
            MI z = 1, a1;
            for (int i = 0, x = 0; i < n; i += (k << 1), z *= z_step[0][w][__builtin_ctz(~x++)])
                rep(j, i, i + k)
                    a1 = it[j + k] * z, it[j + k] = it[j] - a1, it[j] += a1;
        }
    }

    template <class It, class ItEnd>
    void intt_from_rev(It it, ItEnd it_end) {
        int n = int(it_end - it);
        cp_lib_assert(is_pow2(n) && __builtin_ctz(n) <= max_exp);
        for (int k = 1, w = __builtin_ctz(n) - 1; k < n; k <<= 1, --w) {
            MI z = 1, a1;
            for (int i = 0, x = 3 << w; i < n; i += 2 * k, z *= z_step[1][w][__builtin_ctz(--x)])
                rep(j, i, i + k)
                    a1 = it[j + k], it[j + k] = (it[j] - a1) * z, it[j] += a1;
        }
    }

    template <class ItA, class ItAEnd, class ItB, class ItBEnd>
    vector<MI> convolution(ItA it_a, ItAEnd it_a_end, ItB it_b, ItBEnd it_b_end) {
        int la = int(it_a_end - it_a), lb = int(it_b_end - it_b), n = 1 << ceil_log2(la + lb - 1);
        if (!la || !lb)
            return {};
        if (min(la, lb) < 32) {
            vector<MI> a(la), b(lb), r(la + lb - 1);
            transform(it_a, it_a_end, begin(a), [](auto&& x) { return MI(x); });
            transform(it_b, it_b_end, begin(b), [](auto&& x) { return MI(x); });
            rep(i, la) rep(j, lb)
                r[i + j] += a[i] * b[j];
            return r;
        }

        vector<MI> f(n), g(n);
        transform(it_a, it_a_end, begin(f), [](auto&& x) { return MI(x); });
        transform(it_b, it_b_end, begin(g), [](auto&& x) { return MI(x); });

        ntt_to_rev(all(f));
        ntt_to_rev(all(g));
        auto inv_n = MI(n).inv();
        rep(i, n)
            f[i] *= g[i] * inv_n;
        intt_from_rev(all(f));

        f.resize(la + lb - 1);
        return f;
    }
};




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

template <class MI>
MI kth_term_of_linear_recurrence(ll k, const vector<MI>& a, vector<MI> c,
                                 NumberTheoreticTransform<MI>& ntt) {
    if (k < sz(a))
        return a[k];

    int n = sz(c);
    trav(ci, c)
        ci = -ci;
    c.emplace(begin(c), 1);
    auto p = ntt.convolution(all(a), all(c));

    for (; k; k >>= 1) {
        p.resize(n);
        auto c2 = c;
        for (int i = 0; i < sz(c); i += 2)
            c2[i] = -c2[i];
        p = ntt.convolution(all(p), all(c2));
        c2 = ntt.convolution(all(c), all(c2));
        rep(i, n)
            c[i] = c2[i << 1], p[i] = p[(i << 1) + int(k % 2)];
        c[n] = c2[n << 1];
    }

    return p[0] / c[0];
}

template <class T = void, class It>
auto berlekamp_massey(It it, It it_end) {
    using MI = conditional_t<is_void_v<T>, typename iterator_traits<It>::value_type, T>;
    int n = int(it_end - it), l = 0, m = 1;
    if (!n)
        return vector<MI>{};
    vector<MI> c(n + 1), b(n + 1), tmp;
    MI bf1 = c[0] = b[0] = 1;

    for (int i = 0; i < n; ++i, ++m) {
        MI d = it[i];
        rep(j, 1, l + 1)
            d += c[j] * it[i - j];
        if (!d)
            continue;
        tmp = c;
        auto coef = d / bf1;
        rep(j, l)
            c[j + m] -= coef * b[j];
        if (2 * l <= i)
            l = i + 1 - l, b = tmp, bf1 = d, m = 0;
    }

    c.erase(transform(begin(c) + 1, begin(c) + l + 1, begin(c), negate<>{}), end(c));
    return c;
}

using MI = StaticMontgomeryInt<998'244'353, true>;
constexpr int N = 50, K = 12;
// dp[n][i][k][x] = #perms of len n with last elem i with k inversions and x local inversions
MI dp[N][N][K][K];

int main() {
    dp[1][0][0][0] = 1;
    rep(n, 1, N - 1) rep(i, n) rep(k, K) rep(x, K) rep(i2, n + 1) {
        int k2 = k + (n - i2);
        int x2 = x + (i2 <= i);
        if (k2 < K)
            dp[n + 1][i2][k2][x2] += dp[n][i][k][x];
    }

    array<array<vector<MI>, K>, K> vals{}, recs{};
    rep(k, K) rep(x, K) {
        vals[k][x].resize(N, MI(0));
        rep(n, N) rep(i, n)
            vals[k][x][n] += dp[n][i][k][x];
        recs[k][x] = berlekamp_massey(all(vals[k][x]));
    }

    int t; read(t);
    NumberTheoreticTransform ntt(MI(3));
    while (t--) {
        int n, k, x; read(n, k, x);
        if (sz(recs[k][x]))
            println(kth_term_of_linear_recurrence(n, vals[k][x], recs[k][x], ntt));
        else
            println(0);
    }
}