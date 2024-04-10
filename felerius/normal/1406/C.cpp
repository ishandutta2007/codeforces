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

void dfs(int v, int p, vvi& adj, vi& treesize) {
    treesize[v] = 1;
    trav(v2, adj[v])
        if (v2 != p)
            dfs(v2, v, adj, treesize), treesize[v] += treesize[v2];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vvi adj(n);
        rep(i, n-1) {
            int u, v; cin >> u >> v; --v, --u;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vi treesize(n);
        dfs(0, -1, adj, treesize);
        int v = 0, p = -1;
        pi mx;
        while (1) {
            mx = {0, 0};
            trav(v2, adj[v])
                if (v2 != p)
                    mx = max(mx, pi(treesize[v2], v2));
            if (mx.first <= n / 2)
                break;
            p = v;
            v = mx.second;
        }

        if (mx.first < n / 2) {
            cout << "1 " << (adj[0][0] + 1) << "\n1 " << (adj[0][0] + 1) << '\n';
            continue;
        }

        int vl = mx.second, vlp = v;
        while (treesize[vl] > 1) {
            int oldvl = vl;
            vl = adj[vl][adj[vl][0] == vlp];
            vlp = oldvl;
        }

        cout << (vl + 1) << ' ' << (adj[vl][0] + 1) << '\n' << (v + 1) << ' ' << (vl + 1) << '\n';
    }

    return 0;
}