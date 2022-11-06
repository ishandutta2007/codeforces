// Contest: Codeforces Round #625 (Div. 1, based on Technocup 2020 Final Round) (https://codeforces.com/contest/1320)
// Problem: B: Navigation System (https://codeforces.com/contest/1320/problem/B)


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

    int n, m; cin >> n >> m;
    vvi adj(n);
    rep(_, m) {
        int u, v; cin >> u >> v; --u, --v;
        adj[v].push_back(u);
    }
    int k; cin >> k;
    vi p(k);
    trav(pi, p) cin >> pi, --pi;

    vi d(n, INF);
    queue<int> q;
    d[p.back()] = 0;
    q.push(p.back());
    while (sz(q)) {
        int v = q.front(); q.pop();
        for (auto v2 : adj[v])
            if (d[v2] == INF)
                d[v2] = d[v] + 1, q.push(v2);
    }

    vpi neigh(n, pi(INF, 0));
    rep(i, n) {
        trav(j, adj[i]) {
            if (d[i] < neigh[j].first)
                neigh[j] = {d[i], 1};
            else if (d[i] == neigh[j].first)
                neigh[j].second++;
        }
    }

    int mn = 0, mx = 0;
    rep(i, k - 1) {
        int u = p[i], v = p[i + 1];
        if (neigh[u].first < d[v])
            ++mn, ++mx;
        else if (neigh[u].first == d[v] && neigh[u].second > 1)
            ++mx;
    }

    cout << mn << ' ' << mx << '\n';
    return 0;
}