// Contest: Codeforces Round #617 (Div. 3) (https://codeforces.com/contest/1296)
// Problem: F: Berland Beauty (https://codeforces.com/contest/1296/problem/F)


// region {{{ boilerplate
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
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

#if __cpp_lib_nonmember_container_access >= 201411
#   define sz(x) ((int)size(x))
#else
#   define sz(x) ((int)(x).size())
#endif

#define rep(a, b)      for(int a = 0; a < (b); ++a)
#define reps(a, b, c)  for(int a = (b); a < (c); ++a)
#define all(a)         (a).begin(),(a).end()
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

#if __has_cpp_attribute(maybe_unused) >= 201603
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define MAYBE_UNUSED
#endif

MAYBE_UNUSED static constexpr int INF = (int)1e9;
MAYBE_UNUSED static constexpr ll INFL = (ll)1e18;
//endregion }}}

vector<vpi> adj;
vi b;

bool dfs(int v, int p, int to, int mb, vi& edges) {
    if (v == to)
        return true;
    for (auto [v2, e] : adj[v]) {
        if (v2 == p)
            continue;
        if (dfs(v2, v, to, mb, edges)) {
            b[e] = max(b[e], mb);
            edges.push_back(e);
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    adj.resize(n), b.resize(n-1, 1);
    rep(i, n - 1) {
        int x, y; cin >> x >> y; --x, --y;
        adj[x].emplace_back(y, i);
        adj[y].emplace_back(x, i);
    }

    int q; cin >> q;
    vector<array<int, 3>> qs(q);
    sort(all(qs));
    for (auto& [g, x, y] : qs) cin >> x >> y >> g, --x, --y;

    vvi edges(q);
    rep (i, q) {
        auto [g, x, y] = qs[i];
        dfs(x, -1, y, g, edges[i]);
    }

    vi bb(n - 1, -1);
    rep (i, q) {
        auto [g, x, y] = qs[i];
        auto it = find_if(all(edges[i]), [&, g=g](auto e) { return (b[e] <= g && bb[e] == -1) || bb[e] == g; });
        if (it == end(edges[i]))
            cout << "-1\n", exit(0);
        bb[*it] = g;
    }

    rep(i, n-1)
        cout << max(bb[i], b[i]) << ' ';
    cout << '\n';

    return 0;
}