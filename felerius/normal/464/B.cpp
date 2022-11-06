// Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
// Problem: (38) Restore Cube  (Difficulty: 5) (http://codeforces.com/problemset/problem/464/B)


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

using Point = array<int, 3>;

array<Point, 6> combinations(Point p) {
    auto [x, y, z] = p;
    return {Point{x, y, z}, Point{x, z, y}, Point{y, x, z}, Point{y, z, x}, Point{z, x, y}, Point{z, y, x}};
}

ll dist(Point p1, Point p2) {
    ll dx = p1[0] - p2[0], dy = p1[1] - p2[1], dz = p1[2] - p2[2];
    return dx * dx + dy * dy + dz * dz;
}

bool is_cube(array<Point, 8> p) {
    array<ll, 7> dists;
    reps(i, 1, 8) dists[i-1] = dist(p[0], p[i]);
    sort(all(dists));
    if (dists[0] == 0)
        return false;

    reps(i, 1, 8) {
        array<ll, 7> dists2;
        rep(j, 8) {
            if (i == j)
                continue;
            dists2[j - (j > i)] = dist(p[i], p[j]);
        }
        sort(all(dists2));
        if (dists != dists2)
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<Point, 8> p;
    rep(i, 8) rep(j, 3) cin >> p[i][j];

    trav(p1, combinations(p[0]))
    trav(p2, combinations(p[1]))
    trav(p3, combinations(p[2]))
    trav(p4, combinations(p[3]))
    trav(p5, combinations(p[4]))
    trav(p6, combinations(p[5]))
    trav(p7, combinations(p[6]))
    trav(p8, combinations(p[7])) {
        array<Point, 8> ps{p1, p2, p3, p4, p5, p6, p7, p8};
        if (is_cube(ps)) {
            cout << "YES\n";
            trav(pi, ps)
                cout << pi[0] << ' ' << pi[1] << ' ' << pi[2] << '\n';
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}