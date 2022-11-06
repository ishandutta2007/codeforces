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

void dfs(int v, vvi& adj, vi& out) {
    out[v] = v;
    for (int v2 : adj[v]) {
        if (out[v2] == INF)
            dfs(v2, adj, out);
        out[v] = min(out[v], out[v2]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vvi adj(n), adjrev(n);
    vi in(n);
    rep(_, m) {
        int u, v; cin >> u >> v; --u, --v;
        adj[u].push_back(v);
        adjrev[v].push_back(u);
        in[v]++;
    }

    vi q;
    rep(i, n) if (!in[i]) q.push_back(i);

    int done = 0;
    while (sz(q)) {
        int v = q.back(); q.pop_back();
        ++done;
        for (int v2 : adj[v])
            if (!--in[v2])
                q.push_back(v2);
    }

    if (done != n)
        cout << "-1\n", exit(0);

    vi mn_fw(n, INF), mn_rev(n, INF);
    rep(i, n) {
        if (mn_fw[i] == INF)
            dfs(i, adj, mn_fw);
        if (mn_rev[i] == INF)
            dfs(i, adjrev, mn_rev);
    }

    string s;
    rep(i, n)
        s.push_back(min(mn_fw[i], mn_rev[i]) < i ? 'E' : 'A');
    cout << count(all(s), 'A') << '\n' << s << '\n';

    return 0;
}