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

namespace snippets_geometry {
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

        constexpr Point2D operator-() const { return {-x, -y}; }
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
        // Thus
        //   * a  b < 0: rotating from a to b takes us clockwise
        //   * a  b = 0: a and b are collinear
        //   * a  b > 0: rotating from a to b takes us counterclockwise
        constexpr T cross(const Point2D& o) const { return x * o.y - y * o.x; }
    };
    template <class T> constexpr Point2D<T> operator*(const T& f, const Point2D<T>& p) { return p * f; }

    using Point = Point2D<ld>;
    MAYBE_UNUSED constexpr ld PI = 3.141592653589793238462643383279502884L;
} using namespace snippets_geometry;

using Matrix = array<array<ld, 3>, 3>;

Matrix mul(Matrix m1, Matrix m2) {
    Matrix res{};
    rep(i, 3) rep(j, 3) rep(k, 3)
        res[i][j] += m1[i][k] * m2[k][j];
    return res;
}

Point mul(Matrix m, Point _p) {
    array<ld, 3> p = {_p.x, _p.y, 1}, res{};
    rep(i, 3) rep(j, 3)
        res[i] += m[i][j] * p[j];
    return {res[0], res[1]};
}

Matrix translate(Point p) {
    return {
        array<ld, 3>{1, 0, p.x},
                    {0, 1, p.y},
                    {0, 0, 1},
    };
}

Matrix rotate(ld a) {
    ld c = cos(a), s = sin(a);
    return {
        array<ld, 3>{c, -s, 0},
                    {s, c, 0},
                    {0, 0, 1},
    };
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<Point> p(n), px(n);
    trav(pi, p) cin >> pi.x >> pi.y;
    rep(i, n) px[i] = p[i] - p[0];

    ld area = 0;
    rep(i, n)
        area += px[i].cross(px[(i+1)%n]) / 2;
    Point centroid;
    rep(i, n)
        centroid += (px[i] + px[(i+1)%n]) * px[i].cross(px[(i+1)%n]) / (6 * area);
    centroid += p[0];

    Matrix m{};
    rep(i, 3) m[i][i] = 1;

    int p1 = 0, p2 = 1;
    while (q--) {
        int ty; cin >> ty;
        if (ty == 1) {
            int f, t; cin >> f >> t, --f, --t;
            if (f == p1)
                swap(p1, p2);
            p2 = t;
            Point cur_p = mul(m, p[p1]);
            Point vec = mul(m, centroid) - cur_p;
            ld angle = vec.angle(Point(0, -1));
            if (vec.cross(Point(0, -1)) <= 0)
                angle = 2 * PI - angle;
            m = mul(translate(-cur_p), m);
            m = mul(rotate(angle), m);
            m = mul(translate(cur_p), m);
        } else {
            int v; cin >> v; --v;
            auto [x, y] = mul(m, p[v]);
            cout << fixed << setprecision(20) << x << ' ' << y << '\n';
        }
    }

    return 0;
}