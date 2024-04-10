// Contest: Codeforces Round #633 (Div. 1) (https://codeforces.com/contest/1338)
// Problem: B: Edge Weight Assignment (https://codeforces.com/contest/1338/problem/B)


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

array<bool, 3> dfs(int v, int p) {
    if (sz(adj[v]) == 1)
        return {false, false, true};
    bool even = false, odd = false, has = false;
    for (auto v2 : adj[v]) {
        if (v2 == p) continue;
        auto [chas, ceven, codd] = dfs(v2, v);
        even |= codd;
        odd |= ceven;
        has |= chas;
    }
    return {has || (odd && even), even, odd};
}

int dfs2(int v, int p) {
    if (sz(adj[v]) == 1)
        return 0;
    int cnt = 0;
    bool leaf = false;
    for (auto v2 : adj[v]) {
        if (v2 == p) continue;
        int c = dfs2(v2, v);
        if (c == 0) {
            if (!leaf)
                ++cnt;
            leaf = true;
        } else
            cnt += c + 1;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    adj.resize(n);
    rep(i, n-1) {
        int u, v; cin >> u >> v; --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int r = 0;
    while (sz(adj[r]) == 1) ++r;
    bool has = dfs(r, -1)[0];
    int mx = dfs2(r, -1);
    cout << (has ? 3 : 1) << ' ' << mx << '\n';

    return 0;
}