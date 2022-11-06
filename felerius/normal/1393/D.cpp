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

#define repr(a, b) for (int a = (b) - 1; a >= 0; --a)

MAYBE_UNUSED static constexpr int INF = (int)1e9 + 5;
MAYBE_UNUSED static constexpr ll INFL = (ll)1e18 + 5;
MAYBE_UNUSED static mt19937 rng((u32)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
//endregion

array<array<short, 2000>, 2000> ul, ur, dl, dr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<string> g(n);
    trav(si, g) cin >> si;

    rep(i, n) rep(j, m) {
        if (i == 0 || j == 0)
            ul[i][j] = 1;
        else
            ul[i][j] = 1 + min(
                g[i-1][j] == g[i][j] ? ul[i-1][j] : 0,
                g[i][j-1] == g[i][j] ? ul[i][j-1] : 0
            );
    }

    rep(i, n) repr(j, m) {
        if (i == 0 || j + 1 == m)
            ur[i][j] = 1;
        else
            ur[i][j] = 1 + min(
                g[i-1][j] == g[i][j] ? ur[i-1][j] : 0,
                g[i][j+1] == g[i][j] ? ur[i][j+1] : 0
            );
    }

    repr(i, n) rep(j, m) {
        if (i + 1 == n || j == 0)
            dl[i][j] = 1;
        else
            dl[i][j] = 1 + min(
                g[i+1][j] == g[i][j] ? dl[i+1][j] : 0,
                g[i][j-1] == g[i][j] ? dl[i][j-1] : 0
            );
    }

    repr(i, n) repr(j, m) {
        if (i + 1 == n || j + 1 == m)
            dr[i][j] = 1;
        else
            dr[i][j] = 1 + min(
                g[i+1][j] == g[i][j] ? dr[i+1][j] : 0,
                g[i][j+1] == g[i][j] ? dr[i][j+1] : 0
            );
    }

    int cnt = 0;
    rep(i, n) rep(j, m)
        cnt += min({ul[i][j], ur[i][j], dl[i][j], dr[i][j]});

    cout << cnt << '\n';
    return 0;
}