// region boilerplate
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
#   define all(a)      begin(a),end(a)
#   define sz(x)       ((int)size(x))
#else
#   define all(a)      (a).begin(),(a).end()
#   define sz(x)       ((int)(x).size())
#endif

#define rep(a, b)      for(int a = 0; a < (b); ++a)
#define reps(a, b, c)  for(int a = (b); a < (c); ++a)
#define trav(a, b)     for(auto& a : b)

using ll = long long;
using ld = long double;
using u64 = uint64_t;
using u32 = uint32_t;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vpi = vector<pi>;

#if __cplusplus >= 201703L
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define MAYBE_UNUSED
#endif

MAYBE_UNUSED static constexpr int INF = (int)1e9 + 5;
MAYBE_UNUSED static constexpr ll INFL = (ll)1e18 + 5;
MAYBE_UNUSED static mt19937 rng((u32)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
//endregion

namespace snippets_modular {
    template <class C>
    struct Modular {
        using I = decltype(C::m());
        I val = 0;

    private:
#ifdef __SIZEOF_INT128__
        using Mul = conditional_t<sizeof(I) >= 5, unsigned __int128, uint64_t>;
#else
        static_assert(sizeof(I) <= 4, "cannot multiply larger than 64-bit");
        using Mul = uint64_t;
#endif

        struct Unchecked {};
        constexpr Modular(I _val, Unchecked) : val(_val) {}
        static constexpr array<I, 3> ext_gcd(I a, I b) {
            if (!a) return {b,0,1};
            auto ar = ext_gcd(b % a, a);
            return {ar[0], ar[2] - (b / a) * ar[1], ar[1]};
        }
    public:

        constexpr Modular() = default;
        template <class T>
        constexpr Modular(T _val) { _val %= C::m(); if (_val < 0) _val += C::m(); val = static_cast<I>(_val); }

        template <class T>
        constexpr explicit operator T() const { return static_cast<T>(val); }

#define DEFINE_CMP(op) constexpr bool operator op (Modular r) const { return val op r.val; }
        DEFINE_CMP(==) DEFINE_CMP(!=) DEFINE_CMP(<) DEFINE_CMP(<=) DEFINE_CMP(>) DEFINE_CMP(>=)
#undef DEFINE_CMP

        constexpr Modular& operator+=(Modular r) { if ((val += r.val) >= C::m()) val -= C::m(); return *this; }
        constexpr Modular& operator-=(Modular r) { if (r.val > val) val += C::m(); val -= r.val; return *this; }
        template <class T> constexpr enable_if_t<is_integral<T>::value, Modular&> operator+=(T r) { return *this += Modular(r); }
        template <class T> constexpr enable_if_t<is_integral<T>::value, Modular&> operator-=(T r) { return *this -= Modular(r); }
        constexpr Modular operator+(Modular r) const { return Modular(*this) += r; }
        constexpr Modular operator-(Modular r) const { return Modular(*this) -= r; }

        constexpr Modular operator*(Modular r) const { return Modular(static_cast<Mul>(val) * static_cast<Mul>(r.val)); }
        constexpr Modular& operator*=(Modular r) { return *this = *this * r; }
        template <class T> constexpr enable_if_t<is_integral<T>::value, Modular&> operator*=(T r) { return *this *= Modular(r); }

        template <class T> constexpr Modular pow(T e) const {
            Modular a = 1, b = *this;
            for (; e > 0; b *= b, e /= 2)
                if (e % 2) a *= b;
            return a;
        }
        constexpr Modular inv() const { I x = ext_gcd(val, C::m())[1]; return Modular(x < 0 ? x + C::m() : x, Unchecked{}); }

        constexpr Modular& operator/=(Modular r) { return *this *= r.inv(); }
        template <class T> constexpr enable_if_t<is_integral<T>::value, Modular&> operator/=(T r) { return *this /= Modular(r); }
        constexpr Modular operator/(Modular r) const { return Modular(*this) /= r; }

        constexpr Modular operator+() const { return *this; }
        constexpr Modular operator-() const { return Modular(val ? -val + C::m() : val, Unchecked{}); }
        constexpr Modular& operator++() { return *this += 1; }
        constexpr Modular& operator--() { return *this -= 1; }
        constexpr Modular operator++(int) { auto r = *this; *this += 1; return r; }
        constexpr Modular operator--(int) { auto r = *this; *this -= 1; return r; }
    };

#define DEFINE_OPS(op) \
        template <class C, class T, class = enable_if_t<is_integral<T>::value>> \
        constexpr auto operator op (Modular<C> l, T r) { return Modular<C>(l) op Modular<C>(r); } \
        template <class C, class T, class = enable_if_t<is_integral<T>::value>> \
        constexpr auto operator op (T l, Modular<C> r) { return Modular<C>(l) op Modular<C>(r); }
    DEFINE_OPS(==) DEFINE_OPS(!=) DEFINE_OPS(<) DEFINE_OPS(<=) DEFINE_OPS(>) DEFINE_OPS(>=)
    DEFINE_OPS(+) DEFINE_OPS(-) DEFINE_OPS(*) DEFINE_OPS(/)
#undef DEFINE_OPS

    template<class C> std::ostream& operator<<(std::ostream& out, Modular<C> m) { return out << m.val; }
    template <class C> std::istream& operator>>(std::istream& in, Modular<C>& m) {
        // Avoid reading character types
        using I = typename Modular<C>::I;
        using T = conditional_t<is_same<I, signed char>::value || is_same<I, unsigned char>::value || is_same<I, char>::value, int, I>;

        T val{};
        in >> val;
        m = Modular<C>(val);
        return in;
    }
    template<class C> string to_string(Modular<C> m) { return ::to_string(m.val); }

    template <class I, I M> struct ConstMod { static constexpr I m() { return M; } };
    using MI = Modular<ConstMod<int, 998244353>>;
    using vMI = vector<MI>;
} using namespace snippets_modular;
namespace std {
    template <class C> struct hash<Modular<C>> {
        size_t operator()(Modular<C> m) const { return hash<typename Modular<C>::I>()(m.val); }
    };
}

namespace snippets_dsu {
    struct DSU {
        vi p;
        explicit DSU(int n) : p(n, -1) {}

        int find(int i) { return p[i] < 0 ? i : p[i] = find(p[i]); }
        bool same(int i, int j) { return find(i) == find(j); }
        int size(int i) { return -p[find(i)]; }
        bool join(int i, int j) {
            i = find(i), j = find(j);
            if (i == j) return false;
            if (p[i] > p[j]) swap(i, j);
            p[i] += p[j], p[j] = i;
            return true;
        }
    };
} using namespace snippets_dsu;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vi l(n), r(n);
    rep(i, n) cin >> l[i] >> r[i];
    vpi h(m);
    DSU dsu(n);
    for (auto& [a, b] : h)
        cin >> a >> b, --a, --b, dsu.join(a, b);

    vi comp(n, -1);
    int compcnt = 0;
    rep(i, n) {
        if (dsu.size(i) == 1)
            continue;
        int repr = dsu.find(i);
        if (comp[repr] == -1)
            comp[repr] = compcnt++;
        comp[i] = comp[repr];
    }

    vvi compnodes(compcnt);
    rep(i, n)
        if (comp[i] != -1)
            compnodes[comp[i]].push_back(i);

    vector<vvi> compdp(compcnt);
    rep(i, compcnt) {
        auto& nod = compnodes[i];
        auto& dp = compdp[i];
        int s = sz(nod);

        vpi hc;
        for (auto& [a, b] : h) {
            auto ita = lower_bound(all(nod), a), itb = lower_bound(all(nod), b);
            if (ita == end(nod) || itb == end(nod) || *ita != a || *itb != b)
                continue;
            hc.emplace_back((int)(ita - begin(nod)), (int)(itb - begin(nod)));
        }

        dp.assign(1 << s, vi(s + 1));
        rep(ma, 1 << s) {
            bool is = true;
            for (auto& [a, b] : hc)
                is &= !((ma >> a) & 1) || !((ma >> b) & 1);
            dp[ma][__builtin_popcount(ma)] = is;
        }

        rep(j, s)
            rep(ma, 1 << s)
                if (!((ma >> j) & 1))
                    rep(k, s + 1)
                        dp[ma | (1 << j)][k] += dp[ma][k];
    }

    vi cnt(n + 2);
    rep(i, n)
        if (comp[i] == -1)
            cnt[l[i]]++, cnt[r[i]+1]--;
    partial_sum(all(cnt), begin(cnt));

    int comptotal = 0;
    rep(i, compcnt)
        comptotal += sz(compnodes[i]);

    vMI f(n + 1, 1), fi(n + 1, 1);
    reps(i, 1, n + 1)
        f[i] = i * f[i-1], fi[i] = fi[i-1] / i;
    auto cnk = [&](int n, int k) { return (0 <= k && k <= n ? f[n] * fi[n-k] * fi[k] : 0); };

    MI sum = 0;
    reps(k, 1, n + 1) {
        vMI knapsack(comptotal + 1);
        knapsack[0] = 1;
        rep(i, compcnt) {
            int ma = 0;
            rep(j, sz(compnodes[i])) {
                int v = compnodes[i][j];
                if (l[v] <= k && k <= r[v])
                    ma |= 1 << j;
            }

            for (int j = comptotal; j; --j)
                reps(x, 1, min(sz(compnodes[i]), j) + 1)
                    knapsack[j] += knapsack[j - x] * compdp[i][ma][x];
        }

        rep(i, comptotal + 1)
            sum += knapsack[i] * cnk(cnt[k], k - i);
    }

    cout << sum << '\n';
    return 0;
}