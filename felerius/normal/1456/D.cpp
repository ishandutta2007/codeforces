// Cakes for Clones (https://codeforces.com/contest/1456/problem/D)

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
#   define all(a)      ::begin(a),::end(a)
#   define sz(x)       ((int)::size(x))
#else
#   define all(a)      (a).begin(),(a).end()
#   define sz(x)       ((int)(x).size())
#endif

#define _choose(_1, _2, _3, chosen, ...) chosen
#define _rep0(i, r)       for (int i = 0; i < r; ++i)
#define _repn(i, l, r)    for (int i = l; i < r; ++i)
#define _repr0(i, r)      for (int i = r; i >= 0; --i)
#define _reprn(i, r, l)   for (int i = r; i >= l; --i)
#define rep(...)          _choose(__VA_ARGS__, _repn, _rep0, suppress_warning)(__VA_ARGS__)
#define repr(...)         _choose(__VA_ARGS__, _reprn, _repr0, suppress_warning)(__VA_ARGS__)
#define trav(a, b)        for(auto& a : b)

using ll = long long;
using ld = long double;

#if __cplusplus >= 201703L
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define MAYBE_UNUSED
#endif

MAYBE_UNUSED static constexpr int INF = (int)1e9 + 5;
MAYBE_UNUSED static constexpr ll INFL = (ll)INF * INF;
MAYBE_UNUSED static mt19937 rng((uint32_t)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());

namespace cp_lib {}

using namespace cp_lib;

constexpr int N = 5005;
bool dp1[N][N];     // dp1[i][j] = can you collect cake i w/ my clone at position of cake j?
ll dp2[N][N];       // dp2[i][k] = earliest time to place at cake i after collecting k cakes

void chmin(ll& a, ll b) { a = min(a, b); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<ll> time(n), pos(n);
    rep(i, n)
        cin >> time[i] >> pos[i];

    auto walk = [&](int i, int j) { return abs(pos[i] - pos[j]); };

    rep(i, n) {
        dp2[i][0] = abs(pos[i]);
        dp1[0][i] = abs(pos[i]) + walk(i, 0) <= time[0];
    }

    // dp_1[i][j] = can you collect cake i and your clone is at cake j
    // dp_2[i][k] = earliest time to place clone at cake i after collecting k cakes
    //
    // dp_2[i][k] = min(
    //    dp_2[k-1][k-1] + walk,
    //    time[k - 2] + walk, (if any dp_1[k - 2][k - 1])
    // )
    //
    // dp_1[i][j] = (dp_1[i-1][j] && time[i-1] + walk <= time[i]) || (dp_2[j][k - 1] + walk <= time[i])

    rep(i, 1, n) {
        rep(j, n) {
            dp2[j][i] = INFL;
            if (dp2[i - 1][i - 1] <= time[i - 1])
                chmin(dp2[j][i], max(time[i - 1], dp2[i - 1][i - 1] + walk(i - 1, j)));
            if (i > 1 && dp1[i - 2][i - 1])
                chmin(dp2[j][i], max(time[i - 1], time[i - 2] + walk(i - 2, j)));
        }

        rep(j, n) {
            dp1[i][j] = dp1[i - 1][j] && time[i - 1] + walk(i - 1, i) <= time[i];
            dp1[i][j] |= dp2[j][i] + walk(j, i) <= time[i];
        }
    }

    bool can = false;
    rep(i, n)
        can |= dp1[n-1][i];
    if (n > 1)
        can |= dp1[n-2][n-1];

    cout << (can ? "YES\n" : "NO\n");
    return 0;
}