// Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
// Problem: (56) Hill Climbing (Difficulty: 6) (http://codeforces.com/problemset/problem/406/D)


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

    using Point = Point2D<ll>;
    MAYBE_UNUSED constexpr ld PI = 3.141592653589793238462643383279502884L;
} using namespace snippets_geometry;

namespace snippets_rmq {
    template <class C> struct SparseTable : private C {
        using typename C::T; using C::combine;
        vector<vector<T>> d;

        explicit SparseTable(const vector<T>& v) {
            int k = 1, l = 1, n = sz(v);
            while (k < n) k *= 2, ++l;
            d.assign(l, v);
            rep(i, l-1) rep(j, n)
                d[i+1][j] = combine(d[i][j], d[i][min(j+(1<<i), n-1)]);
        }

        T query(int l, int r) {  // [l, r)
            assert(l < r);
            int k = 31 - __builtin_clz(r - l);
            return combine(d[k][l], d[k][r-(1<<k)]);
        }
    };

    struct RmqConf {
        using T = pi;
        static T combine(const T& a, const T& b) { return min(a, b); }
    };

    using RMQ = SparseTable<RmqConf>;
} using namespace snippets_rmq;

void dfs(int v, int d, vvi& adj, vpi& euler, vi& enter) {
    enter[v] = sz(euler);
    euler.emplace_back(d, v);
    trav(v2, adj[v])
        dfs(v2, d + 1, adj, euler, enter), euler.emplace_back(d, v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<Point> p(n);
    trav(pi, p) cin >> pi.x >> pi.y;

    vvi adj(n);
    vector<pair<Point, int>> stack = {{p.back(), n - 1}};
    for (int i = n - 2; i >= 0; --i) {
        while (sz(stack) > 1 && (stack[sz(stack)-2].first - p[i]).cross(stack.back().first - p[i]) < 0)
            stack.pop_back();
        adj[stack.back().second].push_back(i);
        stack.emplace_back(p[i], i);
    }

    vpi euler; vi enter(n);
    dfs(n - 1, 0, adj, euler, enter);
    RMQ lca(euler);

    int q; cin >> q;
    while (q--) {
        int a, b; cin >> a >> b; --a, --b;
        int l = lca.query(min(enter[a], enter[b]), max(enter[a], enter[b]) + 1).second;
        cout << (l + 1) << ' ';
    }
    cout << '\n';

    return 0;
}