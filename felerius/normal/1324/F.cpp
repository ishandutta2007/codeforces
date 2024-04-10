// Contest: Codeforces Round #627 (Div. 3) (https://codeforces.com/contest/1324)
// Problem: F: Maximum White Subtree (https://codeforces.com/contest/1324/problem/F)


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

vvi adj;
vi a;
vi dpdown, res;

void dfs1(int v, int p) {
    dpdown[v] = a[v] == 1 ? 1 : -1;
    for (auto v2 : adj[v])
        if (v2 != p)
            dfs1(v2, v), dpdown[v] += max(0, dpdown[v2]);
}

void dfs2(int v, int p, int up) {
    assert(up >= 0);
    res[v] = dpdown[v] + up;
    for (auto v2 : adj[v])
        if (v2 != p)
            up += max(0, dpdown[v2]);
    up += a[v] == 1 ? 1 : -1;
    for (auto v2 : adj[v])
        if (v2 != p)
            dfs2(v2, v, max(0, up - max(0, dpdown[v2])));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    adj.resize(n), a.resize(n);
    trav(ai, a) cin >> ai;
    rep(i, n - 1) {
        int u, v; cin >> u >> v; --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dpdown.resize(n), res.resize(n);
    dfs1(0, -1);
    dfs2(0, -1, 0);
    rep(i, n)
        cout << res[i] << ' ';
    cout << '\n';

    return 0;
}