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
#   define all(a)      ::begin(a),::end(a)
#   define sz(x)       ((int)::size(x))
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
MAYBE_UNUSED static constexpr ll INFL = (ll)INF * INF;
MAYBE_UNUSED static mt19937 rng((u32)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
// endregion

namespace snippets_rmq {
    template <class C> struct SparseTable : private C {
        using typename C::T; using C::combine;
        vector<vector<T>> d;

        explicit SparseTable(const vector<T>& v) {
            int k = 1, l = 1, n = sz(v);
            while (k < n) k *= 2, ++l;
            d.assign(l, v);
            rep(i, l-1) rep(j, n)
                d[i+1][j] = combine(d[i][j], d[i][min(j+(1<<i), n-1)]);
        }

        T query(int l, int r) {  // [l, r)
            assert(l < r);
            int k = 31 - __builtin_clz(r - l);
            return combine(d[k][l], d[k][r-(1<<k)]);
        }
    };

    struct RmqConf {
        using T = pi;
        static T combine(const T& a, const T& b) { return min(a, b); }
    };

    using RMQ = SparseTable<RmqConf>;
} using namespace snippets_rmq;

const int N = 100'005, LOGN = 17;
int n;
vi adj[N];
int enter[N], tsz[N], up[N][LOGN], d[N];
vpi euler;

void dfs(int v, int p) {
    up[v][0] = p;
    reps(i, 1, LOGN)
        up[v][i] = up[v][i-1] == -1 ? -1 : up[up[v][i-1]][i-1];

    enter[v] = sz(euler);
    euler.emplace_back(d[v], v);
    tsz[v] = 1;
    trav(v2, adj[v])
        if (v2 != p)
            d[v2] = d[v] + 1, dfs(v2, v), euler.emplace_back(d[v], v), tsz[v] += tsz[v2];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    rep(i, n-1) {
        int a, b; cin >> a >> b; --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1);
    RMQ lca(euler);

    auto go_up = [&](int v, int l) {
        rep(i, LOGN)
            v = l & 1 ? up[v][i] : v, l >>= 1;
        return v;
    };

    int m; cin >> m;
    while (m--) {
        int a, b; cin >> a >> b;--a, --b;
        if (a == b) {
            cout << n << '\n';
            continue;
        }

        int l = lca.query(min(enter[a], enter[b]), max(enter[a], enter[b]) + 1).second;
        int dist = d[a] + d[b] - 2 * d[l];
        if (dist % 2) {
            cout << "0\n";
            continue;
        }

        bool aside = dist / 2 <= d[a] - d[l];
        int mi = go_up(aside ? a : b, dist / 2);
        int res;
        if (mi == l) {
            int da = go_up(a, dist / 2 - 1);
            int db = go_up(b, dist / 2 - 1);
            res = n - tsz[da] - tsz[db];
        } else {
            int down = go_up(aside ? a : b, dist / 2 - 1);
            res = tsz[mi] - tsz[down];
        }

        cout << res << '\n';
    }

    return 0;
}