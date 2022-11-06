// Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
// Problem: (45) Gargari and Bishops (Difficulty: 5) (http://codeforces.com/problemset/problem/463/C)


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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    auto g = vector(n, vector(n, 0ll));
    rep(i, n) rep(j, n)
        cin >> g[i][j];

    auto tl = g, tr = g;
    reps(i, 1, n)
        rep(j, n)
            tl[i][j] += (j ? tl[i-1][j-1] : 0), tr[i][j] += (j + 1 < n ? tr[i-1][j+1] : 0);

    pair<ll, pi> mx[2] = {{0ll, pi()}, {0ll, pi()}};
    rep(i, n) rep(j, n) {
        int dl = min(j, n - 1 - i), dr = n - 1 - max(i, j);
        ll diag1 = tr[i+dl][j-dl], diag2 = tl[i+dr][j+dr];
        int p = (i + j) % 2;
        mx[p] = max(mx[p], pair(diag1 + diag2 - g[i][j], pi(i, j)));
    }

    cout << (mx[0].first + mx[1].first) << '\n';
    auto [x1, y1] = mx[0].second; auto [x2, y2] = mx[1].second;
    cout << ++x1 << ' ' << ++y1 << ' ' << ++x2 << ' ' << ++y2 << '\n';
    return 0;
}