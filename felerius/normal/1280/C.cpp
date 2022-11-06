// Contest: Codeforces Round #607 (Div. 1) (https://codeforces.com/contest/1280)
// Problem: C: Jeremy Bearimy (https://codeforces.com/contest/1280/problem/C)


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

struct Res {
    int size = 1;
    ll mn = 0, mx = 0;
    int mn_open = 1, mx_open = 1;
};

Res dfs(int v, int p, int n, vector<vpi>& adj) {
    Res res{};
    for (auto [v2, c] : adj[v]) {
        if (v2 == p)
            continue;
        auto cres = dfs(v2, v, n, adj);
        res.size += cres.size;
        res.mn_open += cres.mn_open;
        res.mx_open += cres.mx_open;
        res.mn += cres.mn + (ll)cres.mn_open * c;
        res.mx += cres.mx + (ll)cres.mx_open * c;
    }
    res.mn_open %= 2;
    res.mx_open = min(res.mx_open, n - res.size);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int k; cin >> k;
        vector<vpi> adj(2 * k);
        rep(i, 2 * k - 1) {
            int u, v, t; cin >> u >> v >> t; --u, --v;
            adj[u].emplace_back(v, t);
            adj[v].emplace_back(u, t);
        }
        auto res = dfs(0, -1, 2 * k, adj);
        cout << res.mn << ' ' << res.mx << '\n';
    }


    return 0;
}