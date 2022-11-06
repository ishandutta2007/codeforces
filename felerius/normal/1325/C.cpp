// Contest: Codeforces Round #628 (Div. 2) (https://codeforces.com/contest/1325)
// Problem: C: Ehab and Path-etic MEXs (https://codeforces.com/contest/1325/problem/C)


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

vpi bfs(vvi& adj, int n, int v) {
    vpi d(n, pair(INF, INF));
    queue<int> q;
    q.push(v);
    d[v] = {0, -1};
    while (sz(q)) {
        int v2 = q.front(); q.pop();
        for (auto v3 : adj[v2])
            if (d[v3].first == INF)
                d[v3] = {d[v2].first + 1, v2}, q.push(v3);
    }
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    if (n == 2)
        cout << "0\n", exit(0);

    vvi adj(n);
    map<pi, int> m;
    rep(i, n -1) {
        int u, v; cin >> u >> v; --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        m[pair(u, v)] = m[pair(v, u)] = i;
    }

    int l1 = 0, l2 = 0;
    while (sz(adj[l1]) > 1) ++l1;
    l2 = l1 + 1;
    while (sz(adj[l2]) > 1) ++l2;

    auto d = bfs(adj, n, l1);
    if (d[l2].first == n - 1) {
        rep(i, n-1) cout << i << '\n';
        return 0;
    }

    vi p = {l2};
    while (p.back() != l1)
        p.push_back(d[p.back()].second);
    vi res(n-1, -1);
    res[m[pair(p[0], p[1])]] = 0;
    res[m[pair(p.back(), p[sz(p) - 2])]] = 1;
    int num = n - 2;
    reps(i, 1, sz(p) - 2)
        res[m[pair(p[i], p[i+1])]] = num--;
    trav(i, res)
        if (i == -1)
            i = num--;

    trav(i, res)
        cout << i << '\n';

    return 0;
}