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

const int N = 205;
ll dp[N][N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, G, B; cin >> R >> G >> B;
    vi r(R), g(G), b(B);
    trav(ri, r) cin >> ri;
    trav(gi, g) cin >> gi;
    trav(bi, b) cin >> bi;
    sort(all(r));
    sort(all(g));
    sort(all(b));

    reps(i, 0, R + 1) reps(j, 0, G + 1) reps(k, 0, B + 1) {
        if (i && j)
            dp[i][j][k] = max(dp[i][j][k], r[i-1] * g[j-1] + dp[i-1][j-1][k]);
        if (i && k)
            dp[i][j][k] = max(dp[i][j][k], r[i-1] * b[k-1] + dp[i-1][j][k-1]);
        if (j && k)
            dp[i][j][k] = max(dp[i][j][k], g[j-1] * b[k-1] + dp[i][j-1][k-1]);
    }

    cout << dp[R][G][B] << '\n';

    return 0;
}