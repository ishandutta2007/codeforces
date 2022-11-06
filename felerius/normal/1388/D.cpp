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

    int n; cin >> n;
    vi a(n), b(n);
    trav(ai, a) cin >> ai;
    trav(bi, b) cin >> bi, --bi;

    vi indeg(n);
    rep(i, n)
        if (b[i] >= 0)
            indeg[b[i]]++;

    vi q, topo;
    rep(i, n)
        if (!indeg[i]) q.push_back(i);

    while (sz(q)) {
        int v = q.back(); q.pop_back();
        topo.push_back(v);
        if (b[v] >= 0 && !--indeg[b[v]])
            q.push_back(b[v]);
    }

    vvi adj(n);
    ll sum = 0;
    vl best(n);
    trav(i, topo) {
        sum += best[i] + a[i];
        if (b[i] >= 0) {
            if (best[i] + a[i] >= 0) {
                best[b[i]] += best[i] + a[i];
                adj[i].push_back(b[i]);
            } else
                adj[b[i]].push_back(i);
        }
    }

    indeg.assign(n, 0);
    trav(l, adj) trav(v, l)
        ++indeg[v];

    q.clear();
    rep(i, n)
        if (!indeg[i]) q.push_back(i);

    vi topo2;
    while (sz(q)) {
        int v = q.back(); q.pop_back();
        topo2.push_back(v);
        for (auto v2 : adj[v])
            if (!--indeg[v2])
                q.push_back(v2);
    }

    cout << sum << '\n';
    trav(v, topo2)
        cout << (v + 1) << ' ';
    cout << '\n';

    /* vl a2(n); */
    /* rep(i, n) a2[i] = a[i]; */
    /* ll sum2 = 0; */
    /* trav(i, topo2) { */
    /*     sum2 += a2[i]; */
    /*     if (b[i] >= 0) */
    /*         a2[b[i]] += a2[i]; */
    /* } */
    /* assert(sum2 == sum); */

    return 0;
}