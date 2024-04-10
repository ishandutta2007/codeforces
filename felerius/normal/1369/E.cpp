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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vi w(n), deg(n);
    trav(wi, w) cin >> wi;
    vector<vpi> adj(n);
    rep(i, m) {
        int x, y; cin >> x >> y, --x, --y;
        adj[x].emplace_back(y, i);
        adj[y].emplace_back(x, i);
        deg[x]++;
        deg[y]++;
    }

    vi cand;
    vector<bool> done(n), inq(n);
    rep(i, n)
        if (w[i] >= deg[i])
            cand.push_back(i), inq[i] = true;

    vi res;
    while (sz(cand)) {
        int v = cand.back(); cand.pop_back();
        done[v] = true;
        for (auto [v2, ei] : adj[v]) {
            if (done[v2]) continue;
            res.push_back(ei);
            if (--deg[v2] <= w[v2] && !inq[v2])
                cand.push_back(v2), inq[v2] = true;
        }
    }

    if (sz(res) == m) {
        cout << "ALIVE\n";
        reverse(all(res));
        trav(ri, res)
            cout << (ri + 1) << ' ';
        cout << '\n';
    } else
        cout << "DEAD\n";

    return 0;
}