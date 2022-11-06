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

void bfs(int v0, vector<vpi>& adj, vpi& prev, vl& dist) {
    queue<int> q; q.emplace(v0);
    fill(all(prev), pi(-1, 0));
    fill(all(dist), INFL);
    dist[v0] = 0;
    while (sz(q)) {
        int v = q.front(); q.pop();
        for (auto [v2, w] : adj[v])
            if (dist[v2] == INFL)
                dist[v2] = dist[v] + w, prev[v2] = {v, w}, q.emplace(v2);
    }
}

tuple<bool, ll, int> dfs(int v, int p, int pdist, ll k, vector<vpi>& adj) {
    ll mxdist = 0; int nodes = 0;
    for (auto [v2, w] : adj[v]) {
        if (v2 == p)
            continue;
        auto [pos, mxdist2, nodes2] = dfs(v2, v, w, k, adj);
        if (!pos || (nodes2 && nodes))
            return {false, 0, 0};
        if (nodes2)
            nodes = nodes2 + 1;
        else
            mxdist = max(mxdist, mxdist2);
    }
    if (nodes)
        return {true, 0, nodes};
    if (mxdist + pdist > k)
        return {true, 0, 1};
    return {true, mxdist + pdist, 0};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    if (n == 1)
        cout << "0\n", exit(0);

    vector<vpi> adj(n);
    rep(i, n - 1) {
        int u, v, d; cin >> u >> v >> d; --u, --v;
        adj[u].emplace_back(v, d);
        adj[v].emplace_back(u, d);
    }

    vl dist(n); vpi prev(n);
    bfs(0, adj, prev, dist);
    int vmx = (int)(max_element(all(dist)) - begin(dist));
    bfs(vmx, adj, prev, dist);
    vmx = (int)(max_element(all(dist)) - begin(dist));
    pair<ll, int> cent = {dist[vmx], vmx};
    ll remdist = dist[vmx];
    int vc = vmx;
    while (prev[vc].first != -1)
        remdist -= prev[vc].second, vc = prev[vc].first, cent = min(cent, pair(max(remdist, dist[vmx] - remdist), vc));
    vc = cent.second;

    ll l = -1, r = INFL;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        bool pos = true;
        vi nodecnts;
        for (auto [v, w] : adj[vc]) {
            auto [pos2, _, nodes2] = dfs(v, vc, w, m, adj);
            pos &= pos2;
            if (nodes2)
                nodecnts.push_back(nodes2);
        }
        pos &= sz(nodecnts) <= 2 && accumulate(all(nodecnts), 0) + 1 <= k;
        (pos ? r : l) = m;
    }

    cout << r << '\n';
    return 0;
}