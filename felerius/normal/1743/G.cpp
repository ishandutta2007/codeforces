// Antifibonacci Cut (https://codeforces.com/contest/1743/problem/G)
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


namespace cp_lib_modint { struct ModIntTag {}; }
template <class T> constexpr bool IsModInt = is_base_of_v<cp_lib_modint::ModIntTag, T>;

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
    template <class Int, Int Mod, bool IsPrime>
    class StaticMontgomery : public Base<StaticMontgomery<Int, Mod, IsPrime>, Int, true> {
        static_assert(Mod % 2 && Mod < (1ull << (sizeof(Int) * 8 - 2)));
        static constexpr Int INV = []{
            Int inv = Mod;
            rep(_, __builtin_ctz(sizeof(Int) * 8) - 1)
                inv *= 2 - Mod * inv;
            return inv;
        }();
        static constexpr Int R2 = Int(-Wide<Int>(Mod) % Mod);
        static constexpr Int reduce(Wide<Int> x) {
            return Int((x - Int(x) * INV * Wide<Int>(Mod)) >> (sizeof(Int) * 8)) + Mod;
        }

     public:
        static constexpr Int mod() { return Mod; }
        static constexpr bool is_prime() { return IsPrime; }

        StaticMontgomery() = default;
        template <class T, enable_if_t<is_unsigned_v<T>, int> = 0>
        constexpr StaticMontgomery(T x) { this->i = reduce(Wide<Int>(uint64_t(x) % Mod) * R2); }
        template <class T, enable_if_t<is_signed_v<T>, int> = 0>
        constexpr StaticMontgomery(T x) { this->i = reduce(Wide<Int>(ll(x) % ll(Mod) + ll(Mod)) * R2); }

        template <class T, enable_if_t<is_integral_v<T>, int> = 0>
        constexpr explicit operator T() const { return T(this->normed(reduce(this->i))); }

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


[[maybe_unused]] static mt19937 rng(uint32_t(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count()));

constexpr int N = int(3e6);
constexpr int K = 32;  // Lowest k s.t. |f_k| > N
constexpr auto F = []{
    array<int, K> f{};
    f[0] = f[1] = 1;
    rep(i, 2, K)
        f[i] = f[i - 1] + f[i - 2];
    return f;
}();

using Hash = StaticMontgomeryInt64<(1ull << 62) - 10565, true>;
static Hash A = []{
    Hash a = 0;
    while (uint64_t(a) < (1ull << 61))
        a = ((uint64_t(rng()) << 29) ^ rng()) | (1ull << 61);
    return a;
}();

bitset<N> bs, keep;
int m = 0;

template <class Callback>
void iterate_with_fib_hashes(Callback&& f) {
    array<Hash, K> h{}, apow{};
    apow.fill(1);
    auto a_inv = A.inv();

    rep(i, m) {
        rep(j, 32) {
            if (i >= F[j])
                h[j] = (h[j] - int(bs[i - F[j]])) * a_inv;
            h[j] += apow[j] * int(bs[i]);
            if (i + 1 < F[j])
                apow[j] *= A;
        }

        f(i, h);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    vector l(n, 0);
    rep(i, n) {
        string s; cin >> s;
        trav(c, s)
            bs[m++] = c == '1';
        l[i] = m;
    }

    array<Hash, K> f_hash{};
    f_hash[1] = 1;
    rep(i, 2, K)
        f_hash[i] = f_hash[i - 1] + f_hash[i - 2] * A.pow(F[i - 1]);

    constexpr int HIST = 100;
    constexpr int NUM_LOW = []{
        int c = 0;
        trav(fi, F)
            c += fi < HIST;
        return c;
    }();

    iterate_with_fib_hashes([&](int i, const auto& h) {
        rep(j, NUM_LOW, K)
            if (i >= F[j])
                keep[i - F[j]] = keep[i - F[j]] || h[j] == f_hash[j];
    });

    using MI = StaticMontgomeryInt<998'244'353, true>;
    int done = 0;
    deque dp_hist(HIST, MI(0));
    MI dp_sum = dp_hist[0] = 1;
    map<int, MI> kept;
    kept[-1] = dp_hist[0];
    iterate_with_fib_hashes([&](int i, const auto& h) {
        dp_hist.pop_back();
        MI& new_dp = dp_hist.emplace_front(dp_sum);
        rep(j, K)
            if (i + 1 >= F[j] && h[j] == f_hash[j])
                new_dp -= j < NUM_LOW ? dp_hist[F[j]] : kept[i - F[j]];

        dp_sum += new_dp;
        if (keep[i])
            kept[i] = new_dp;

        if (i + 1 == l[done])
            cout << new_dp << '\n', ++done;
    });
}