// Contest: Educational Codeforces Round 89 (Rated for Div. 2) (https://codeforces.com/contest/1366)
// Problem: F: Jog Around The Graph (https://codeforces.com/contest/1366/problem/F)


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

// region dimvec
template <class T, class... Is> struct vec_helper;
template <class T> struct vec_helper<T> { static auto f(T val) { return val; } };
template <class T, class I, class... Is> struct vec_helper<T, I, Is...> {
    static auto f(T val, I size, Is... sizes) {
        return vector(size, vec_helper<T, Is...>::f(val, sizes...));
    }
};
template <class T, class... Is> auto vec(T val, Is... sizes) { return vec_helper<T, Is...>::f(val, sizes...); }
// endregion

// region modular
template <class C>
struct Modular {
    using I = decltype(C::m());
    I val = 0;

private:
    struct _Unchecked {};
    using _Mul = conditional_t<sizeof(I) == sizeof(uint64_t), unsigned __int128, uint64_t>;
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
    template <class T> constexpr enable_if_t<is_integral<T>::value, Modular&> operator/=(T r) { return *this /= Modular(r); }
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
// endregion

// region geometry
template <class T>
struct Point2D {
    T x = 0, y = 0;
    constexpr Point2D() = default;
    constexpr Point2D(T x, T y) : x(x), y(y) {}

#define DEFINE_CMP(op) constexpr bool operator op(const Point2D& o) const { return tie(x, y) op tie(o.x, o.y); }
    DEFINE_CMP(==) DEFINE_CMP(!=) DEFINE_CMP(<) DEFINE_CMP(<=) DEFINE_CMP(>) DEFINE_CMP(>=)
#undef DEFINE_CMP

    constexpr Point2D& operator+=(const Point2D& r) { x += r.x; y += r.y; return *this; }
    constexpr Point2D& operator-=(const Point2D& r) { x -= r.x; y -= r.y; return *this; }
    constexpr Point2D& operator*=(const T& f) { x *= f; y *= f; return *this; }
    constexpr Point2D& operator/=(const T& f) { x /= f; y /= f; return *this; }

    constexpr Point2D operator+(const Point2D& r) const { return Point2D(*this) += r; }
    constexpr Point2D operator-(const Point2D& r) const { return Point2D(*this) -= r; }
    constexpr Point2D operator*(const T& f) const { return Point2D(*this) *= f; }
    constexpr Point2D operator/(const T& f) const { return Point2D(*this) /= f; }

#define REQUIRE_FLOAT template <class U = T> constexpr enable_if_t<is_floating_point<U>::value, T>
    constexpr T dot(const Point2D& o) const { return x * o.x + y * o.y; }
    constexpr T norm() const { return dot(*this); }
    REQUIRE_FLOAT len() const { return sqrt(norm()); }
    // Project onto another line (result is distance across onto vector)
    REQUIRE_FLOAT proj(const Point2D& onto) const { return dot(onto) / onto.len(); }
    REQUIRE_FLOAT angle(const Point2D& o) const { return acos(dot(o) / len() / o.len()); }
#undef REQUIRE_FLOAT

    // |a  b| is area of parallelogram spanned up by a and b
    // a  b = |a| * |b| * sin(angle)
    // Thus, rotating from a to b takes us clockwise, if a  b is negative, or counterclockwise,
    // if a  b is positive. If a  b = 0, the vectors are collinear.
    constexpr T cross(const Point2D& o) const { return x * o.y - y * o.x; }
};
template <class T> constexpr Point2D<T> operator*(const T& f, const Point2D<T>& p) { return p * f; }

using Point = Point2D<int>;
constexpr ld PI = 3.141592653589793238462643383279502884L;
// endregion

// region CHT
template <class T, bool Upper, bool Rev>
class ConvexHullTrick {
    constexpr static T invert_if_upper(T val) { return Upper ? -val : val; }
    constexpr static T invert_if_rev(T val) { return Rev ? -val : val; }
    using P = Point2D<T>;

public:
    vector<P> hull, vecs;

    // Add points in order of increasing k (or decreasing, if Rev = true)
    void add(T k, T b) {  // f(x) = k * x + b
        P f = {invert_if_upper(k), invert_if_upper(b)};
        while (sz(vecs) && invert_if_rev(invert_if_upper(vecs.back().dot(f - hull.back()))) < 0)
            hull.pop_back(), vecs.pop_back();
        if (sz(hull)) {
            auto d = f - hull.back();
            if (d == P(0, 0))
                return;
            vecs.emplace_back(-d.y, d.x);
        }
        hull.push_back(f);
    }

    T get(T x) {
        P q = {x, 1};
        auto it = partition_point(all(vecs), [&](auto& v) { return v.cross(q) > 0; });
        return invert_if_upper(q.dot(hull[it - begin(vecs)]));
    }
};
using CHT = ConvexHullTrick<ll, true, false>;
// endregion

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q; cin >> n >> m >> q;
    vector<tuple<int, int, int>> e(m);
    for (auto& [u, v, w] : e)
        cin >> u >> v >> w, --u, --v;

    auto dp = vec(-INFL, n, n);
    dp[0][0] = 0;
    reps(i, 1, n) {
        for (auto [u, v, w] : e) {
            if (dp[i-1][u] != -INFL)
                dp[i][v] = max(dp[i][v], dp[i-1][u] + w);
            if (dp[i-1][v] != -INFL)
                dp[i][u] = max(dp[i][u], dp[i-1][v] + w);
        }
    }

    MI res = 0;
    reps(i, 1, n)
        res += *max_element(all(dp[i]));

    map<ll, ll> f;
    for (auto [u, v, w] : e)
        f[w] = -INFL;
    for (auto [u, v, w] : e)
        rep(i, n)
            f[w] = max(f[w], max(dp[i][u], dp[i][v]) - (ll)i * w);

    CHT cht;
    for (auto [k, b] : f)
        cht.add(k, b);

    ll l = n;
    auto tria = [](ll x) { return x * (x + 1) / 2; };
    rep(i, sz(cht.hull) - 1) {
        ll k1 = -cht.hull[i].x, b1 = -cht.hull[i].y;
        ll k2 = -cht.hull[i+1].x, b2 = -cht.hull[i+1].y;
        ll x = min((ll)q, (b2 - b1) / (k1 - k2));
        if (x < l)
            continue;
        res += (tria(x) - tria(l - 1)) * MI(k1) + (x - l + 1) * MI(b1);
        l = x + 1;
    }

    ll kl = -cht.hull.back().x, bl = -cht.hull.back().y;
    res += (tria(q) - tria(l - 1)) * MI(kl) + (q - l + 1) * MI(bl);
    cout << res << '\n';

    return 0;
}