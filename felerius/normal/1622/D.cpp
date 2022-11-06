// Shuffle (https://codeforces.com/contest/1622/problem/D)
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

    template <class T, class T2 = remove_reference_t<remove_cv_t<T>>>
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
struct Combinatorics {
    vector<MI> f, fi;

    explicit Combinatorics(int n) : f(n + 1), fi(n + 1) {
        f[0] = 1;
        MI m; int i;
        for (i = 1, m = f[0]; i <= n; ++i, ++m)
            f[i] = f[i - 1] * m;
        fi[n] = f[n].inv();
        for (--i, --m; i; --i, --m)
            fi[i - 1] = m * fi[i];
    }

    MI binom(int n, int k) const { return (n >= k && k >= 0 ? f[n] * fi[n - k] * fi[k] : MI(0)); }
    MI stars_bars(int n, int k) const { return binom(n + k - 1, k - 1); }
    MI catalan(int n) const { return f[2 * n] * fi[n + 1] * fi[n]; }
    MI catalan(int n, int k) const { return (k ? k * f[2 * n + k - 1] * fi[n + k] * fi[n] : MI(!n)); }

    template <class It, class ItEnd>
    MI multinom(int n, It it, ItEnd it_end) const {
        MI res = f[n];
        while (it != it_end) res *= fi[*it++];
        return res;
    }
};

int main() {
    int n, k; string s; read(n, k, s);
    using MI = StaticMontgomeryInt<998'244'353, true>;
    Combinatorics<MI> comb(n);

    if (k > count_if(all(s), [&](char c) { return c == '1'; }))
        println(1), exit(0);

    MI ans = 1;
    rep(i, n) {
        int cnt1 = (s[i] == '1');
        rep(j, i + 1, n) {
            cnt1 += (s[j] == '1');
            if (cnt1 > k)
                break;

            array rem = {j - i + 1 - cnt1, cnt1};
            rem[s[i] == '0']--;
            rem[s[j] == '0']--;
            if (rem[0] >= 0 && rem[1] >= 0)
                ans += comb.binom(rem[0] + rem[1], rem[0]);
        }
    }

    println(ans);
}