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

void dfs(int v, int pa, vvi& adj, vi& psum) {
    for (auto v2 : adj[v])
        if (v2 != pa)
            dfs(v2, v, adj, psum), psum[v] += psum[v2];
}

bool dfs_check(int v, int pa, vvi& adj, vi& bad, vi& p) {
    int sum_bad = 0;
    for (auto v2 : adj[v]) {
        if (v2 == pa)
            continue;
        sum_bad += bad[v2];
        if (!dfs_check(v2, v, adj, bad, p))
            return false;
    }
    return sum_bad + p[v] >= bad[v];
}

void solve() {
    int n, m; cin >> n >> m;
    vvi adj(n);
    vi p(n), h(n);
    trav(pi, p) cin >> pi;
    trav(hi, h) cin >> hi;
    rep(_, n-1) {
        int u, v; cin >> u >> v; --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto psum = p;
    dfs(0, -1, adj, psum);

    rep(i, n) {
        if (h[i] < -psum[i] || psum[i] < h[i]) {
            cout << "NO\n";
            return;
        }
    }

    vi bad(n);
    rep(i, n) {
        if ((psum[i] + h[i]) % 2) {
            cout << "NO\n";
            return;
        }
        bad[i] = psum[i] - (psum[i] + h[i]) / 2;
    }

    cout << (dfs_check(0, -1, adj, bad, p) ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--)
        solve();

    return 0;
}