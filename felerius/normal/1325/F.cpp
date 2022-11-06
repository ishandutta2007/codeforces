// Contest: Codeforces Round #628 (Div. 2) (https://codeforces.com/contest/1325)
// Problem: F: Ehab's Last Theorem (https://codeforces.com/contest/1325/problem/F)


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
    rep(i, m) {
        int u, v; cin >> u >> v, --u, --v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    int sq = (int)ceil(sqrt(n));

    vi deg(n);
    vector<bool> del(n);
    set<pi> bydeg;
    rep(i, n)
        deg[i] = sz(adj[i]), bydeg.emplace(deg[i], i);

    vi is;
    while (sz(is) < sq) {
        auto [d, v] = *begin(bydeg);
        bydeg.erase(begin(bydeg));
        if (d < sq - 1) {
            is.push_back(v);
            del[v] = true;
            for (auto u : adj[v]) {
                if (del[u])
                    continue;
                del[u] = true;
                bydeg.erase(pair(deg[u], u));
                for (auto u2 : adj[u])
                    if (!del[u2])
                        bydeg.erase(pair(deg[u2], u2)), --deg[u2], bydeg.emplace(deg[u2], u2);
            }
            continue;
        }

        v = 0;
        while (del[v]) ++v;
        vi pidx(n, -1);
        vi p = {v};
        pidx[v] = 0;

        while (true) {
            int back = INF;
            bool found = false;
            for (auto v2 : adj[p.back()]) {
                if (del[v2]) continue;
                if (pidx[v2] == -1) {
                    pidx[v2] = sz(p), p.push_back(v2), found = true; break;
                }
                back = min(back, pidx[v2]);
            }
            if (!found) {
                cout << "2\n" << (sz(p) - back) << '\n';
                reps(i, back, sz(p))
                    cout << (p[i] + 1) << ' ';
                cout << '\n';
                return 0;
            }
        }
    }

    cout << "1\n";
    trav(i, is) cout << (i + 1) << ' ';
    cout << '\n';

    return 0;
}