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

    int a, n, m; cin >> a >> n >> m;
    vector<bool> rain(a);
    rep(_, n) {
        int l, r; cin >> l >> r;
        fill(begin(rain) + l, begin(rain) + r, true);
    }

    vector<int> x(m), p(m);
    rep(i, m)
        cin >> x[i] >> p[i];

    auto dp = vector(a + 1, vector(m + 1, INF));
    dp[0][m] = 0;
    rep(i, m)
        if (x[i] == 0)
            dp[0][i] = 0;

    reps(i, 1, a + 1) {
        rep(j, m)
            dp[i][m] = min(dp[i][m], dp[i-1][j] + p[j]);
        if (!rain[i-1])
            dp[i][m] = min(dp[i][m], dp[i-1][m]);
        rep(j, m) {
            if (x[j] == i)
                dp[i][j] = dp[i][m];
            else
                dp[i][j] = dp[i-1][j] + p[j];
        }
    }

    int mn = *min_element(all(dp[a]));
    cout << (mn >= INF ? -1 : mn) << '\n';
    return 0;
}