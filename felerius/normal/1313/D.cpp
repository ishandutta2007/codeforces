// Contest: Codeforces Round #622 (Div. 2) (https://codeforces.com/contest/1313)
// Problem: D: Happy New Year (https://codeforces.com/contest/1313/problem/D)


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
MAYBE_UNUSED static constexpr ll INFL = (ll)1e18 + 5;
MAYBE_UNUSED static mt19937 rng((u32)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
//endregion }}}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, l, r; cin >> n >> m >> k;
    vector<tuple<int, bool, int>> evt;
    rep(i, n)
        cin >> l >> r, --l, evt.emplace_back(l, true, i), evt.emplace_back(r, false, i);
    sort(all(evt));

    vector<int> dp(1u << k, -INF), dpp(1u << k, -INF);
    dpp[0] = 0;
    vector<int> w(k, -1);
    int prev = 0;
    for (auto [x, start, i] : evt) {
        fill(all(dp), -INF);
        if (start) {
            int j = find(all(w), -1) - begin(w);
            w[j] = i;
            for (u32 b = 0; b < (1u << k); ++b)
                dp[b] = dpp[b & ~(1u << j)] + (__builtin_popcount(b & ~(1u << j)) % 2) * (x - prev);
        } else {
            int j = find(all(w), i) - begin(w);
            w[j] = -1;
            for (u32 b = 0; b < (1u << k); ++b)
                if (!((b >> j) & 1))
                    dp[b] = max(dpp[b] + (__builtin_popcount(b) % 2) * (x - prev),
                                dpp[b | (1u << j)] + (__builtin_popcount(b) + 1) % 2 * (x - prev));
        }
        swap(dp, dpp);
        prev = x;
    }

    cout << *max_element(all(dpp)) << '\n';
    return 0;
}