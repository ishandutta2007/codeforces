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

using Point = Point2D<ll>;
MAYBE_UNUSED constexpr ld PI = 3.141592653589793238462643383279502884L;
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
using CHTLower = ConvexHullTrick<ld, false, false>;
using CHTUpper = ConvexHullTrick<ld, true, false>;
// endregion

Point angle_vec(Point p1, Point p2) {
    if (p1.y < p2.y)
        swap(p1, p2);
    return p2 - p1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<array<int, 3>> p(n);
    for (auto& [xl, xr, y] : p) cin >> xl >> xr >> y;

    CHTUpper cht_mx;
    CHTLower cht_mn;
    vector<pi> funcs;
    for (auto& [xl, xr, y] : p)
        funcs.emplace_back(y, xl), funcs.emplace_back(y, xr);
    sort(all(funcs));
    for (auto [y, x] : funcs)
        cht_mx.add(y, x), cht_mn.add(y, x);

    vector<pair<Point, bool>> evt;
    rep(i, n) {
        auto [xl1, xr1, y1] = p[i];
        reps(j, i + 1, n) {
            auto [xl2, xr2, y2] = p[j];
            if (y1 == y2)
                continue;
            auto ang1 = angle_vec(Point(xl1, y1), Point(xr2, y2));
            auto ang2 = angle_vec(Point(xr1, y1), Point(xl2, y2));
            if (ang1.cross(ang2) < 0)
                swap(ang1, ang2);
            evt.emplace_back(ang1, true);
            evt.emplace_back(ang2, false);
        }
    }

    if (!sz(evt)) {
        int mn = INF, mx = -INF;
        for (auto& [xl, xr, y] : p)
            mn = min(mn, xl), mx = max(mx, xr);
        cout << (mx - mn) << '\n';
        return 0;
    }

    sort(all(evt), [](auto& e1, auto& e2) {
        auto c = e1.first.cross(e2.first);
        if (!c) return e1.second < e2.second;
        return c > 0;
    });

    ld mn = INFL;
    int cnt = 0;
    for (auto [v, t] : evt) {
        if (t ? !cnt++ : !--cnt) {
            ld x = (ld)v.x / abs(v.y);
            mn = min(mn, cht_mx.get(x) - cht_mn.get(x));
        }
    }

    cout.precision(30);
    cout << mn << '\n';

    return 0;
}