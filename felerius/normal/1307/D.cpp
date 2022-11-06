// Contest: Codeforces Round #621 (Div. 1 + Div. 2) (https://codeforces.com/contest/1307)
// Problem: D (https://codeforces.com/contest/1307/problem/D)


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

    int n, m, k; cin >> n >> m >> k;
    vi a(k);
    trav(ai, a) cin >> ai, --ai;
    vvi adj(n);
    rep(i, m) {
        int x, y; cin >> x >> y; --x, --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    auto bfs = [&](int v0) {
        vi d(n, INF); d[v0] = 0;
        for (queue<int> q{{v0}}; sz(q); q.pop())
            for (auto v2 : adj[q.front()])
                if (d[v2] == INF)
                    d[v2] = d[q.front()] + 1, q.push(v2);
        return d;
    };
    auto ds = bfs(0), dt = bfs(n - 1);
    sort(all(a), [&](int i, int j) { return ds[i] > ds[j]; });
    int mx = 0, mxdt = dt[a[0]];
    reps(i, 1, k) {
        mx = max(mx, ds[a[i]] + 1 + mxdt);
        mxdt = max(mxdt, dt[a[i]]);
    }

    cout << min(mx, ds[n - 1]) << '\n';
    return 0;
}