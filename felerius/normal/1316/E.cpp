// Contest: CodeCraft-20 (Div. 2) (https://codeforces.com/contest/1316)
// Problem: E: Team Building (https://codeforces.com/contest/1316/problem/E)


// region {{{ boilerplate
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
MAYBE_UNUSED static constexpr ll INFL = (ll)INF * INF;
MAYBE_UNUSED static mt19937 rng((u32)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
//endregion }}}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p, k; cin >> n >> p >> k;
    vi a(n);
    trav(ai, a) cin >> ai;
    vector<array<int, 7>> s(n);
    trav(si, s) rep(j, p) cin >> si[j];
    vi idx(n);
    iota(all(idx), 0);
    sort(all(idx), [&](int i, int j) { return a[i] > a[j]; });

    vl dp(1u << p), dpp(1u << p, -INFL);
    dpp[0] = 0;
    rep(i, n) {
        int ii = idx[i];
        for (u32 m = 0; m < (1u << p); ++m) {
            int aud = i - __builtin_popcount(m);
            dp[m] = dpp[m] + (aud < k ? a[ii] : 0);
            u32 m2 = m;
            while (m2) {
                int j = __builtin_ctz(m2); m2 &= m2 - 1;
                dp[m] = max(dp[m], dpp[m & ~(1u << j)] + s[ii][j]);
            }
        }
        swap(dp, dpp);
    }

    cout << dpp[(1u << p) - 1] << '\n';
    return 0;
}