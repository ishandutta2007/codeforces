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
    template <class Self, class Int_>
    struct Base : ModIntTag {
        using Int = Int_;
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


namespace cp_lib_convolution {
    template <class T, bool PreConvert = false, class ItA, class ItB>
    vector<T> brute(ItA it_a, ItA it_a_end, ItB it_b, ItB it_b_end) {
        if constexpr (PreConvert) {
            vector<T> a(it_a, it_a_end), b(it_b, it_b_end);
            return brute<T, false>(all(a), all(b));
        } else {
            if (it_a == it_a_end || it_b == it_b_end)
                return {};
            vector<T> c((it_a_end - it_a) + (it_b_end - it_b) - 1);
            rep(i, int(it_a_end - it_a)) rep(j, int(it_b_end - it_b))
                c[i + j] += T(T(it_a[i]) * T(it_b[j]));
            return c;
        }
    }
}


template <class T> constexpr inline bool is_pow2(T n) { return n && !(n & (n - 1)); }
template <class T> constexpr inline int floor_log2(T n) { return n ? 63 - __builtin_clzll(n) : 0; }
template <class T> constexpr inline int ceil_log2(T n) { return n ? floor_log2(n) + !is_pow2(n) : 0; }

template <class MI>
class NumberTheoreticTransform {
    int max_exp;
    array<array<array<MI, 30>, 31>, 2> z_step{};

 public:
    constexpr explicit NumberTheoreticTransform(MI g) : max_exp(min(30, __builtin_ctzll(MI::mod() - 1))) {
        rep(w, max_exp) {
            auto z_w = g.pow((MI::mod() - 1) >> (w + 1));
            rep(i, w) {
                int diff = (1 << (w - 1 - i)) - (((1 << i) - 1) << (w - i));
                auto z = z_w.pow(diff < 0 ? -diff : diff);
                rep(inv, 2)
                    z_step[inv][w][i] = ((diff < 0) ^ inv ? z.inv() : z);
            }
        }
    }

    template <class It>
    void ntt_to_rev(It it, It it_end) const {
        int n = int(it_end - it);
        cp_lib_assert(is_pow2(n) && __builtin_ctz(n) <= max_exp);
        for (int k = n >> 1, w = 0; k; k >>= 1, ++w) {
            MI z = 1, a1;
            for (int i = 0, x = 0; i < n; i += (k << 1), z *= z_step[0][w][__builtin_ctz(~x++)])
                rep(j, i, i + k)
                    a1 = it[j + k] * z, it[j + k] = it[j] - a1, it[j] += a1;
        }
    }

    template <class It>
    void intt_from_rev(It it, It it_end) const {
        int n = int(it_end - it);
        cp_lib_assert(is_pow2(n) && __builtin_ctz(n) <= max_exp);
        for (int k = 1, w = __builtin_ctz(n) - 1; k < n; k <<= 1, --w) {
            MI z = 1, a1;
            for (int i = 0, x = 3 << w; i < n; i += 2 * k, z *= z_step[1][w][__builtin_ctz(--x)])
                rep(j, i, i + k)
                    a1 = it[j + k], it[j + k] = (it[j] - a1) * z, it[j] += a1;
        }
    }

    template <class ItA, class ItB>
    vector<MI> convolution(ItA it_a, ItA it_a_end, ItB it_b, ItB it_b_end) const {
        if (min(it_a_end - it_a, it_b_end - it_b) <= 32)
            return cp_lib_convolution::brute<MI, true>(it_a, it_a_end, it_b, it_b_end);
        int m = int((it_a_end - it_a) + (it_b_end - it_b)) - 1, n = 1 << ceil_log2(m);
        vector<MI> f(n), g(n);
        transform(it_a, it_a_end, begin(f), [](auto&& x) { return MI(x); });
        transform(it_b, it_b_end, begin(g), [](auto&& x) { return MI(x); });

        ntt_to_rev(all(f));
        ntt_to_rev(all(g));
        auto inv_n = MI(n).inv();
        rep(i, n)
            f[i] *= g[i] * inv_n;
        intt_from_rev(all(f));

        f.resize(m);
        return f;
    }
};

template <class... ModInts>
class ArbitraryNtt {
    template <class T, class = void> struct Unwrap { using type = T; };
    template <class T> struct Unwrap<T, enable_if_t<IsModInt<T>>> { using type = typename T::Int; };
    static constexpr int N = sizeof...(ModInts);
    static constexpr array MODS{uint64_t(ModInts::mod())...};
    static constexpr tuple R{[](auto x) {
        using MI = remove_cvref_t<decltype(x)>;
        return array{(MI(ModInts::mod()) == MI(0) ? MI(0) : MI(ModInts::mod()).inv())...};
    }(ModInts())...};
    tuple<NumberTheoreticTransform<ModInts>...> ntts;

    template <class MI, size_t... Idx>
    static void calc_x(MI ci, array<uint64_t, N>& x, index_sequence<Idx...>) {
        ((ci = (ci - MI(x[Idx])) * get<sizeof...(Idx)>(R)[Idx]), ...);
        x[sizeof...(Idx)] = uint64_t(ci);
    }

    template <class MI, class ItA, class ItB, size_t... Idx>
    auto conv_impl(ItA it_a, ItA it_a_end, ItB it_b, ItB it_b_end, index_sequence<Idx...>) const {
        tuple cs(get<Idx>(ntts).convolution(it_a, it_a_end, it_b, it_b_end)...);
        if (min(it_a_end - it_a, it_b_end - it_b) <= 32)
            return cp_lib_convolution::brute<MI, true>(it_a, it_a_end, it_b, it_b_end);
        vector<MI> c(sz(get<0>(cs)));
        rep(i, sz(c)) {
            array<uint64_t, N> x{};
            (calc_x(get<Idx>(cs)[i], x, make_index_sequence<Idx>()), ...);
            repr(j, N - 1)
                c[i] = c[i] * MI(MODS[j]) + MI(x[j]);
        }
        return c;
    }

 public:
    constexpr ArbitraryNtt(ModInts... roots) : ntts(NumberTheoreticTransform(roots)...) {}

    template <class T = void, class ItA, class ItB>
    auto convolution(ItA it_a, ItA it_a_end, ItB it_b, ItB it_b_end) const {
        using MI = conditional_t<is_void_v<T>, iter_value_t<ItA>, T>;
        vector<typename Unwrap<iter_value_t<ItA>>::type> a(it_a, it_a_end);
        vector<typename Unwrap<iter_value_t<ItB>>::type> b(it_b, it_b_end);
        return conv_impl<MI>(all(a), all(b), make_index_sequence<N>());
    }
};

[[maybe_unused]] constexpr ArbitraryNtt arbitrary_ntt(StaticMontgomeryInt<167772161, true>(3),
                                                      StaticMontgomeryInt<469762049, true>(3),
                                                      StaticMontgomeryInt<754974721, true>(11));


template <class MI, class F>
vector<MI> chirp_z(vector<MI> a, MI x, int m, F&& conv) {
    int n = sz(a);
    auto x_inv = x.inv();
    auto loop = [](int r, MI z, auto&& f) {
        MI z_pow = 1, z_step = 1;
        rep(i, r)
            f(i, z_pow), z_pow *= z_step, z_step *= z;
    };

    loop(n, x_inv, [&](int i, MI mul) { a[i] *= mul; });
    reverse(all(a));

    vector b(n + m, MI(1));
    loop(n + m, x, [&](int i, MI mul) { b[i] *= mul; });

    auto c = conv(a, b);
    loop(m, x_inv, [&](int i, MI mul) { c[i] = c[i + n - 1] * mul; });
    c.resize(m);
    return c;
}

int main() {
    using MI = StaticMontgomeryInt<490019, true>;
    int n, m; MI c; read(n, m, c);
    vector<MI> a(MI::mod() - 1, 0), b(MI::mod() - 1, 0);
    rep(i, n) {
        MI ai; read(ai);
        a[ll(i) * i % (MI::mod() - 1)] += ai;
    }
    rep(i, m) {
        MI bi; read(bi);
        b[ll(i) * i * i % (MI::mod() - 1)] += bi;
    }

    ArbitraryNtt ntt(StaticMontgomeryInt<469762049, true>(3),
                     StaticMontgomeryInt<754974721, true>(11));
    auto d = chirp_z(b, c, MI::mod() - 1, [&](auto& p1, auto& p2) {
        return ntt.convolution(all(p1), all(p2));
    });

    MI ans = 0;
    rep(i, MI::mod() - 1)
        ans += a[i] * d[i];
    println(ans);
}