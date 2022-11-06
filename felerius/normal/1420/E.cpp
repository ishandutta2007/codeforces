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

const int N = 82;
const int SWAPS = 41 * 41 + 1;

int dp[N][N][SWAPS];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vi a(n);
    trav(ai, a) cin >> ai;
    ++n;
    a.push_back(1);

    int ones = accumulate(all(a), 0);
    vi pos;
    rep(i, n)
        if(a[i])
            pos.push_back(i);

    rep(i, N) rep(j, N) rep(k, SWAPS)
        dp[i][j][k] = -INF;

    rep(i, SWAPS)
        dp[0][0][i] = 0;

    reps(l, 1, n + 1) {
        int mx_ones = min(ones, l);
        reps(c, 1, mx_ones + 1) {
            int mx_zeros = l - c;
            rep(s, SWAPS) {
                rep(x, mx_zeros + 1) {
                    int d = abs(l - 1 - pos[c-1]);
                    if (d <= s)
                        dp[l][c][s] = max(dp[l][c][s], dp[l-x-1][c-1][s - d] + (l - x - 1 - (c - 1)) * x);
                }
            }
        }
    }

    int mx_orders = (n - 1) * (n - 2) / 2;
    rep(i, mx_orders + 1)
        cout << dp[n][ones][min(i, SWAPS - 1)] << ' ';
    cout << '\n';

    return 0;
}