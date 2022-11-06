// Contest: Codeforces Round #621 (Div. 1 + Div. 2) (https://codeforces.com/contest/1307)
// Problem: E (https://codeforces.com/contest/1307/problem/E)


// region {{{ boilerplate
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
//endregion }}}

template <class C>
struct Modular {
    using I = decltype(C::m());
    I val = 0;

private:
    struct _Unchecked {};
//    using _Mul = conditional_t<sizeof(I) == sizeof(uint64_t), unsigned __int128, uint64_t>;
    using _Mul = uint64_t;
    constexpr Modular(I _val, _Unchecked) : val(_val) {}
    static constexpr array<I, 3> ext_gcd(I a, I b) {
        if (!a) return {b,0,1};
        auto ar = ext_gcd(b % a, a);
        return {ar[0], ar[2] - (b / a) * ar[1], ar[1]};
    }
public:

    constexpr Modular() = default;
    template <class T>
    constexpr Modular(T _val) { val = _val % C::m(); if (val < 0) val += C::m(); }

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

    constexpr Modular operator*(Modular r) const { return Modular(static_cast<_Mul>(val) * static_cast<_Mul>(r.val)); }
    constexpr Modular& operator*=(Modular r) { return *this = *this * r; }
    template <class T> constexpr enable_if_t<is_integral<T>::value, Modular&> operator*=(T r) { return *this *= Modular(r); }

    template <class T> constexpr Modular pow(T e) const {
        Modular a = 1, b = *this;
        for (; e > 0; b *= b, e /= 2)
            if (e % 2) a *= b;
        return a;
    }
    constexpr Modular inv() const { I x = ext_gcd(val, C::m())[1]; return Modular(x < 0 ? x + C::m() : x, _Unchecked{}); }

    constexpr Modular& operator/=(Modular r) { return *this *= r.inv(); }
    template <class T> constexpr enable_if_t<is_integral<T>::value, Modular&> operator/=(T r) { return *this *= Modular(r); }
    constexpr Modular operator/(Modular r) const { return Modular(*this) /= r; }

    constexpr Modular operator+() const { return *this; }
    constexpr Modular operator-() const { return Modular(-val + C::m(), _Unchecked{}); }
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
    using T = conditional_t<is_same<I, signed char>::value, int,
            conditional_t<is_same<I, unsigned char>::value, unsigned int,
                    conditional_t<is_same<I, char>::value, conditional_t<is_signed<char>::value, int, unsigned int>,
                            I>>>;
    T val{};
    in >> val;
    m = Modular<C>(val);
    return in;
}
template<class C> string to_string(Modular<C> m) { return to_string(m.val); }

namespace std {
    template <class C> struct hash<Modular<C>> {
        size_t operator()(Modular<C> m) const { return hash<typename Modular<C>::I>()(m.val); }
    };
}

template <class I, I M> struct ConstMod { static constexpr I m() { return M; } };
using MI = Modular<ConstMod<int, (int)1e9 + 7>>;
using vMI = vector<MI>;

MI operator ""_mi(unsigned long long i) { return MI(i); }

template <class T, size_t... Is> struct arr_helper;
template <class T> struct arr_helper<T> { using type = T; };
template <class T, size_t I, size_t... Is>
struct arr_helper<T, I, Is...> { using type = array<typename arr_helper<T, Is...>::type, I>; };
template <class T, size_t... Is> using arr = typename arr_helper<T, Is...>::type;

arr<int, 5000, 5001> cows;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vi s(n);
    array<int, 5000> l{}, r{};
    trav(si, s) cin >> si, --si, r[si]++;
    int fi, hi;
    rep(i, m)
        cin >> fi >> hi, cows[fi-1][hi] = 1;
    rep(i, 5000) reps(j, 1, 5001) cows[i][j] += cows[i][j-1];

    auto exists = [&](int s, int h) { return cows[s][h] > cows[s][h-1]; };
    int mx = 0;
    MI pos = 1;

    // No cow from the left
    rep(i, 5000)
        if (cows[i][r[i]])
            ++mx, pos *= cows[i][r[i]];

    rep(i, n) {
        int si = s[i];
        l[si]++;
        r[si]--;
        if (!exists(si, l[si]))
            continue;

        int cr = cows[si][r[si]] - (r[si] >= l[si]);
        MI p = max(1, cr);
        int c = 1 + (cr > 0);

        rep(j, 5000) {
            if (j == si) continue;
            int hmn = min(l[j], r[j]), hmx = max(l[j], r[j]);
            if (cows[j][hmx] == 0)
                continue;
            else if (cows[j][hmn] == 0)
                ++c, p *= cows[j][hmx];
            else {
                if (cows[j][hmx] == 1)
                    ++c, p *= 2;
                else {
                    c += 2;
                    int cmn = cows[j][hmn], cmx = cows[j][hmx];
                    p *= (cmx - cmn) * cmn + cmn * (cmn - 1);
                }
            }
        }

        if (c > mx)
            mx = c, pos = p;
        else if (c == mx)
            pos += p;
    }

    cout << mx << ' ' << pos << '\n';
    return 0;
}