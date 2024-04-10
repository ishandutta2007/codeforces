// Strange Beauty (https://codeforces.com/contest/1475/problem/G)

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <chrono>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#if __cplusplus >= 201703L
#   include <optional>
#   include <string_view>
#   define all(a)      ::begin(a),::end(a)
#   define sz(x)       ((int)::size(x))
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define all(a)      (a).begin(),(a).end()
#   define sz(x)       ((int)(x).size())
#   define MAYBE_UNUSED
#endif

#define _choose(_1, _2, _3, chosen, ...) chosen
#define _rep0(i, r)       for (int i = 0; i < r; ++i)
#define _repn(i, l, r)    for (int i = l; i < r; ++i)
#define _repr0(i, r)      for (int i = r; i >= 0; --i)
#define _reprn(i, r, l)   for (int i = r; i >= l; --i)
#define rep(...)          _choose(__VA_ARGS__, _repn, _rep0, suppress_warning)(__VA_ARGS__)
#define repr(...)         _choose(__VA_ARGS__, _reprn, _repr0, suppress_warning)(__VA_ARGS__)
#define trav(a, b)        for(auto& a : b)

using namespace std;

using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using u64 = uint64_t;
using u32 = uint32_t;

MAYBE_UNUSED static constexpr int INF = (int)1e9 + 5;
MAYBE_UNUSED static constexpr ll INFL = (ll)INF * INF;
MAYBE_UNUSED static mt19937 rng((u32)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());

namespace cp_lib {}

using namespace cp_lib;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, ai; cin >> n;
        map<int, int> m;
        rep(_, n)
            cin >> ai, m[ai]++;
        vector<pair<int, int>> a(all(m));
        sort(all(a));

        int k = sz(a);
        vector idx(200'005, -1);
        rep(i, k)
            idx[a[i].first] = i;

        vector pref(k, 0);
        rep(i, k)
            pref[i] = a[i].second;
        partial_sum(all(pref), begin(pref));

        vector dp(k, 0);
        repr(i, k - 1) {
            dp[i] = pref.back() - pref[i];
            for (int x = 2 * a[i].first; x <= 200'005; x += a[i].first) {
                if (idx[x] == -1)
                    continue;
                dp[i] = min(dp[i], dp[idx[x]] + pref[idx[x] - 1] - pref[i]);
            }
        }

        int mn = dp[0];
        rep(i, 1, k)
            mn = min(mn, dp[i] + pref[i - 1]);

        cout << mn << '\n';
    }

    return 0;
}