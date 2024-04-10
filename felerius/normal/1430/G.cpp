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

int dp[18][19][1 << 18];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vi weight(n), indeg(n);
    vvi adj(n);
    rep(_, m) {
        int x, y, w; cin >> x >> y >> w; --x, --y;
        adj[x].push_back(y);
        ++indeg[y];
        weight[x] += w;
        weight[y] -= w;
    }

    // topo sort
    vi q, topo;
    rep(i, n)
        if (!indeg[i])
            q.push_back(i);
    while (sz(q)) {
        topo.push_back(q.back()); q.pop_back();
        trav(v, adj[topo.back()])
            if (!--indeg[v])
                q.push_back(v);
    }

    // transitively reachable nodes
    vi reach(n);
    for (auto it = rbegin(topo); it != rend(topo); ++it) {
        reach[*it] = 1 << *it;
        trav(v, adj[*it])
            reach[*it] |= reach[v];
    }

    // dp[i][j][ma] = min. cost of assigning values in [0, i] to nodes in ma,
    //                with only nodes in topo[0..j] having value i
    rep(i, n) {
        // j = 0
        if (i)
            rep(ma, 1 << n)
                dp[i][0][ma] = dp[i-1][n][ma];
        else
            reps(ma, 1, 1 << n)
                dp[0][0][ma] = INF;

        // j > 0
        reps(j, 1, n + 1) {
            int v = topo[j - 1];

            rep(ma, 1 << n) {
                dp[i][j][ma] = dp[i][j-1][ma];
                if ((ma & reach[v]) == reach[v])
                    dp[i][j][ma] = min(dp[i][j][ma], dp[i][j-1][ma ^ (1 << v)] + weight[v] * i);
            }
        }
    }

    // restore answer
    vi ans(n);
    int ma = (1 << n) - 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n; j > 0; --j) {
            int v = topo[j-1];
            if (dp[i][j][ma] == dp[i][j-1][ma ^ (1 << v)] + weight[v] * i)
                ans[v] = i, ma ^= 1 << v;
        }
    }

    rep(i, n)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}