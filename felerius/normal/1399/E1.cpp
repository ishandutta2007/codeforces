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

void dfs(int v, int p, vector<vpi>& adj, vi& leafcnt) {
    if (sz(adj[v]) == 1 && adj[v][0].first == p) {
        leafcnt[v] = 1;
        return;
    }
    leafcnt[v] = 0;
    for (auto [v2, _w] : adj[v]) {
        if (v2 == p)
            continue;
        dfs(v2, v, adj, leafcnt);
        leafcnt[v] += leafcnt[v2];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; ll s; cin >> n >> s;
        vector<vpi> adj(n);
        vector<array<int, 3>> e(n-1);
        rep(i, n-1) {
            int u, v, w; cin >> u >> v >> w; --u, --v;
            e[i] = {u, v, w};
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        vi leafcnt(n);
        dfs(0, -1, adj, leafcnt);

        priority_queue<pair<ll, int>> q;
        ll current = 0;
        rep(i, n - 1) {
            auto& [u, v, w] = e[i];
            current += (ll)w * min(leafcnt[u], leafcnt[v]);
            q.emplace((ll)(w + 1) / 2 * min(leafcnt[u], leafcnt[v]), i);
        }

        int cnt = 0;
        while (current > s) {
            ++cnt;
            auto [improv, i] = q.top(); q.pop();
            current -= improv;
            auto& [u, v, w] = e[i];
            w /= 2;
            if (w)
                q.emplace((ll)(w + 1) / 2 * min(leafcnt[v], leafcnt[u]), i);
        }

        cout << cnt << '\n';
    }

    return 0;
}