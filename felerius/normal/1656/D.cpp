// K-good (https://codeforces.com/contest/1656/problem/D)
#pragma GCC optimize("fast-math")

#include <bits/stdc++.h>
#if __has_include("dbg.h")
#  include "dbg.h"
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



#if __cpp_lib_remove_cvref < 201711L
template <class T> using remove_cvref_t = remove_cv_t<remove_reference_t<T>>;
#endif
#if __cplusplus < 202002L
struct identity { template <class T> constexpr T&& operator()(T&& t) const noexcept { return forward<T>(t); }; };
template <class T> using iter_value_t = typename iterator_traits<remove_cvref_t<T>>::value_type;
#endif

namespace cp_lib_type_meta {
    template <class T, class = void> constexpr bool is_tuple_like = false;
    template <class T> constexpr bool is_tuple_like<T, void_t<tuple_element_t<0, T>>> = true;
}


namespace cp_lib_modint { struct ModIntTag {}; }
template <class T> constexpr bool IsModInt = is_base_of_v<cp_lib_modint::ModIntTag, T>;
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
        } else if constexpr (IsModInt<T2>)
            return print(typename T2::Int(val));
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
        auto skip_ws = [] {
            do {
                for (; iptr != iend && *iptr <= ' '; ++iptr);
                if (iend - iptr < 64)
                    refill();
            } while (*iptr <= ' ');
        };
        auto read_other = [&](auto other) {
            read(other);
            return other;
        };

        if constexpr (is_same_v<T, char>)
            skip_ws(), val = *iptr++;
        else if constexpr (is_same_v<T, bool> || is_same_v<T, vector<bool>::reference>) {
            val = bool(read_other(uint8_t()));
        } else if constexpr (IsModInt<T>) {
            val = T(read_other(ll()));
        } else if constexpr (is_integral_v<T>) {
            skip_ws();
            if (is_signed_v<T> && *iptr == '-')
                ++iptr, val = T(-read_other(make_unsigned_t<T>()));
            else
                for (val = 0; iptr != iend && *iptr > ' '; val = T(10 * val + (*iptr++ & 15)));
        } else if constexpr (is_floating_point_v<T>)
            skip_ws(), val = T(strtold(iptr, &iptr));
        else if constexpr (is_same_v<T, string>) {
            skip_ws();
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



[[maybe_unused]] static mt19937 rng(uint32_t(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count()));



#ifdef CP_LIB_DEBUG
#define cp_lib_assert(expr) \
    do { if (!(expr)) { \
        ::cerr << "assertion failed: " << #expr << " (" << __FILE__ << ':' << __LINE__ << ")\n"; \
        ::abort(); \
    } } while (0)
#else
#define cp_lib_assert(expr)
#endif



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

template <bool> class Hasher;

namespace cp_lib_modint {
    template <class Self, class Int_, bool Lazy>
    struct Base : ModIntTag {
        using Int = Int_;
        static_assert(is_same_v<Int, uint32_t> || is_same_v<Int, uint64_t>);
        template <bool> friend class ::Hasher;

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
        friend constexpr bool operator==(Self l, Self r) { return normed(l.i) == normed(r.i); }
        friend constexpr bool operator!=(Self l, Self r) { return normed(l.i) != normed(r.i); }
        friend constexpr bool operator<(Self l, Self r) { return normed(l.i) < normed(r.i); }

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
            return (g == 1 || g == -1 ? optional(Self(x)) : nullopt);
        }
        constexpr Self inv() const {
            if (Self::is_prime())
                return pow(Self::mod() - 2);
            auto [g, x, _] = ext_gcd(ll(*(Self*)this), ll(Self::mod()));
            cp_lib_assert(g == 1 || g == -1);
            return x;
        }

        friend ostream& operator<<(ostream& out, Self m) { return out << uint64_t(m); }
        friend istream& operator>>(istream& in, Self& m) { ll x; in >> x; m = x; return in; }

     protected:
        constexpr static Int_ normed(Int_ x) { return Lazy && x >= Self::mod() ? x - Self::mod() : x; }

        Int i = 0;
    };

    template <class Int> using Wide = conditional_t<is_same_v<uint64_t, Int>, unsigned __int128, uint64_t>;
}

namespace cp_lib_modint {
    template <class Int, class Tag = void>
    class DynamicMontgomery : public Base<DynamicMontgomery<Int, Tag>, Int, true> {
        static Int mod_, inv_, r2;
        static bool is_prime_;

        static Int reduce(Wide<Int> x) {
            return Int((x - Int(x) * inv_ * Wide<Int>(mod_)) >> (sizeof(Int) * 8)) + mod_;
        }

     public:
        static Int mod() { return mod_; }
        static bool is_prime() { return is_prime_; }

        static void set_mod(Int mod, bool is_prime) {
            cp_lib_assert(mod % 2 && mod < (1ll << (sizeof(Int) * 8 - 2)));
            is_prime_ = is_prime;
            mod_ = inv_ = mod;
            rep(_, __builtin_ctz(sizeof(Int) * 8) - 1)
                inv_ *= 2 - mod * inv_;
            r2 = Int(-Wide<Int>(mod) % mod);
        }

        DynamicMontgomery() = default;
        template <class T, enable_if_t<is_unsigned_v<T>, int> = 0>
        DynamicMontgomery(T x) { this->i = reduce(Wide<Int>(uint64_t(x) % mod_) * r2); }
        template <class T, enable_if_t<is_signed_v<T>, int> = 0>
        DynamicMontgomery(T x) { this->i = reduce(Wide<Int>(ll(x) % ll(mod_) + (x < 0 ? ll(mod_) : 0ll)) * r2); }

        template <class T, enable_if_t<is_integral_v<T>, int> = 0>
        explicit operator T() const { return T(this->normed(reduce(this->i))); }

        DynamicMontgomery& operator+=(DynamicMontgomery r) {
            if ((this->i += r.i) >= 2 * mod_)
                this->i -= 2 * mod_;
            return *this;
        }
        DynamicMontgomery& operator-=(DynamicMontgomery r) {
            if (make_signed_t<Int>(this->i -= r.i) < 0)
                this->i += 2 * mod_;
            return *this;
        }
        DynamicMontgomery& operator*=(DynamicMontgomery r) {
            this->i = reduce(Wide<Int>(this->i) * r.i);
            return *this;
        }
    };

    template <class Int, class Tag> Int DynamicMontgomery<Int, Tag>::mod_;
    template <class Int, class Tag> Int DynamicMontgomery<Int, Tag>::inv_;
    template <class Int, class Tag> Int DynamicMontgomery<Int, Tag>::r2;
    template <class Int, class Tag> bool DynamicMontgomery<Int, Tag>::is_prime_;
}

template <class Tag = void> using DynamicMontgomeryInt = cp_lib_modint::DynamicMontgomery<uint32_t, Tag>;
template <class Tag = void> using DynamicMontgomeryInt64 = cp_lib_modint::DynamicMontgomery<uint64_t, Tag>;

namespace cp_lib_primes {
    struct Tag;
    template <class T> using MI = cp_lib_modint::DynamicMontgomery<T, Tag>;

    template <class T, size_t I>
    bool miller_rabin(T n, const array<T, I>& as) {
        if (n < 2 || n % 6 % 4 != 1)
            return (n | 1) == 3;
        MI<T>::set_mod(n, false);
        int s = __builtin_ctzll(n - 1);
        T d = (n - 1) >> s;
        MI<T> e(1), f(n - 1);
        return all_of(all(as), [&](auto a) {
            auto p = MI<T>(a), pe = p.pow(d);
            if (!p || pe == e || pe == f)
                return true;
            for (int i = s - 1; pe != f && i >= 0; --i)
                pe *= pe;
            return pe == f;
        });
    }

    inline bool miller_rabin(uint32_t n) { return miller_rabin(n, array<uint32_t, 3>{2, 7, 61}); }
    inline bool miller_rabin(uint64_t n) { return miller_rabin(n, array<uint64_t, 7>{2, 325, 9375, 28178, 450775, 9780504, 1795265022}); }
}

inline bool is_prime(uint64_t n) {
    return n < (1 << 30) ? cp_lib_primes::miller_rabin(uint32_t(n)) : cp_lib_primes::miller_rabin(n);
}

namespace cp_lib_primes {
    auto binary_gcd(uint64_t a, uint64_t b) {
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
        if (!(n & 1)) return 2;
        if (miller_rabin(n)) return n;
        if (MI<T>::mod() != n) MI<T>::set_mod(n, false);
        while (true) {
            MI<T> x, y(rng() % (n - 2) + 2), ys, z(rng() % (n - 2) + 2), q(1);
            auto f = [&](MI<T> v) { return v * v + z; };
            T g = 1;
            for (int r = 1; g == 1; r <<= 1) {
                x = y;
                rep(_, r) y = f(y);
                for (int k = 0; g == 1 && k < r; k += 256) {
                    ys = y;
                    rep(_, min(256, r - k)) q *= x - (y = f(y));
                    g = T(binary_gcd(uint64_t(q), n));
                }
            }
            if (g == n)
                do { g = T(binary_gcd(uint64_t(x - (ys = f(ys))), n)); } while (g == 1);
            if (g != n) return g;
        }
    }
}

vector<uint64_t> factorize(uint64_t n) {
    if (n == 1) return {};
    vector<uint64_t> f = {n};
    for (int i = 0; i < sz(f); ) {
        auto x = (f[i] < (1 << 30) ? cp_lib_primes::pollard(uint32_t(f[i])) : cp_lib_primes::pollard(f[i]));
        if (f[i] == x)
            ++i;
        else
            f[i] /= x, f.push_back(x);
    }
    sort(all(f));
    return f;
}

int main() {
    // k * (k - 1) / 2 = n  (mod k)
    // k * (k - 1) = 2n  (mod k)
    // 2n = 0  (mod k)
    // k divides 2n
    // k * (k + 1) / 2 <= n

    int t; read(t);
    while (t--) {
        ll n; read(n);
        bool done = false;
        for (ll p = 2; p * (p + 1) / 2 <= n; p *= 2) {
            if ((n - p * (p + 1) / 2) % p == 0) {
                println(p);
                done = true;
                break;
            }
        }

        if (done)
            continue;

        auto n2 = n;
        while (n2 % 2 == 0)
            n2 /= 2;
        if (n2 == 1) {
            println(-1);
            continue;
        }

        auto f = factorize(n2);
        ll p = f[0];
        println(p * (p + 1) / 2 <= n ? p : -1ll);
    }
}