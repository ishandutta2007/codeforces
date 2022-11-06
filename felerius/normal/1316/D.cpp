// Contest: CodeCraft-20 (Div. 2) (https://codeforces.com/contest/1316)
// Problem: D: Nash Matrix (https://codeforces.com/contest/1316/problem/D)


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

template <class T, class... Is> struct vec_helper;
template <class T>
struct vec_helper<T> {
    static auto f(T val) { return val; }
};
template <class T, class I, class... Is>
struct vec_helper<T, I, Is...> {
    static auto f(T val, I size, Is... sizes) {
        return vector(size, vec_helper<T, Is...>::f(val, sizes...));
    }
};
template <class T, class... Is>
auto vec(T val, Is... sizes) {
    return vec_helper<T, Is...>::f(val, sizes...);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    auto g = vec(Point(0, 0), n, n);
    rep(i, n) rep(j, n)
        cin >> g[i][j].x >> g[i][j].y, g[i][j] -= Point(1, 1);

    const pair<Point, char> DIR[] = {{{-1, 0}, 'U'}, {{1, 0}, 'D'}, {{0, 1}, 'R'}, {{0, -1}, 'L'}};
    auto in = [&](Point p) { return 0 <= p.x && p.x < n && 0 <= p.y && p.y < n; };
    auto inv = [](char c) {
        switch (c) {
            case 'R': return 'L';
            case 'L': return 'R';
            case 'U': return 'D';
            case 'D': return 'U';
        }
    };

    Point cyc{-2, -2};
    queue<Point> q;
    auto r = vec('?', n, n);
    rep(i, n) rep(j, n) {
        Point p{i, j};
        if (g[i][j] == p) {
            r[i][j] = 'X';
            q.push(p);
            continue;
        } else if (g[i][j] != cyc)
            continue;
        for (auto [d, c] : DIR) {
            auto pi = p + d;
            if (in(pi) && g[pi.x][pi.y] == cyc)
                r[i][j] = c;
        }
    }

    while (sz(q)) {
        auto p = q.front(); q.pop();
        for (auto [d, c] : DIR) {
            auto pi = p + d;
            if (in(pi) && g[pi.x][pi.y] == g[p.x][p.y] && r[pi.x][pi.y] == '?')
                r[pi.x][pi.y] = inv(c), q.push(pi);
        }
    }

    rep(i, n) rep(j, n)
        if (r[i][j] == '?')
            cout << "INVALID\n", exit(0);
    cout << "VALID\n";
    rep(i, n) {
        rep(j, n)
            cout << r[i][j];
        cout << '\n';
    }

    return 0;
}