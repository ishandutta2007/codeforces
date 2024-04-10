// Plan of Lectures (https://codeforces.com/contest/1463/problem/E)

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

#define _choose(_1, _2, _3, chosen, ...) chosen
#define _rep0(i, r)       for (int i = 0; i < r; ++i)
#define _repn(i, l, r)    for (int i = l; i < r; ++i)
#define _repr0(i, r)      for (int i = r; i >= 0; --i)
#define _reprn(i, r, l)   for (int i = r; i >= l; --i)
#define rep(...)          _choose(__VA_ARGS__, _repn, _rep0, suppress_warning)(__VA_ARGS__)
#define repr(...)         _choose(__VA_ARGS__, _reprn, _repr0, suppress_warning)(__VA_ARGS__)
#define trav(a, b)        for(auto& a : b)

using ll = long long;
using ld = long double;

#if __cplusplus >= 201703L
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define MAYBE_UNUSED
#endif

MAYBE_UNUSED static constexpr int INF = (int)1e9 + 5;
MAYBE_UNUSED static constexpr ll INFL = (ll)INF * INF;
MAYBE_UNUSED static mt19937 rng((uint32_t)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());

namespace cp_lib {}


namespace cp_lib {
    struct Dsu {
        vector<int> p;

        explicit Dsu(int n) : p(n, -1) {}

        int find(int i) { return p[i] < 0 ? i : p[i] = find(p[i]); }
        bool same(int i, int j) { return find(i) == find(j); }
        int size(int i) { return -p[find(i)]; }
        bool join(int i, int j) {
            i = find(i), j = find(j);
            if (i == j) return false;
            if (p[i] > p[j]) swap(i, j);
            p[i] += p[j], p[j] = i;
            return true;
        }
    };
}

using namespace cp_lib;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, vr = -1; cin >> n >> k;
    vector<vector<int>> adj(n);
    vector<int> p(n);
    vector<pair<int, int>> dir(k);
    vector<int> next(n, -1);
    vector<bool> is_prev(n, false);

    rep(i, n) {
        cin >> p[i], --p[i];
        if (p[i] < 0)
            vr = i;
        else
            adj[p[i]].push_back(i);
    }

    for (auto& [x, y] : dir) {
        cin >> x >> y, --x, --y;
        adj[x].push_back(y);
        next[x] = y;
        is_prev[y] = true;
    }

    vector<int> indeg(n);
    trav(row, adj) trav(v, row) ++indeg[v];
    if (indeg[vr]) cout << "0\n", exit(0);

    vector<int> q = {vr};
    int done = 0;
    while (sz(q)) {
        int v = q.back(); q.pop_back();
        ++done;
        trav(v2, adj[v])
            if (!--indeg[v2])
                q.push_back(v2);
    }
    if (done != n) cout << "0\n", exit(0);

    Dsu dsu(n);
    int m = n;
    for (auto& [x, y] : dir)
        m -= dsu.join(x, y);

    fill(all(indeg), 0);
    vector<vector<int>> adj2(n);
    rep(i, n)
        if (p[i] >= 0 && !dsu.same(i, p[i]))
            adj2[dsu.find(p[i])].push_back(dsu.find(i)), ++indeg[dsu.find(i)];

    vector<int> topo;
    q.clear();
    rep(i, n)
        if (!indeg[i])
            q.push_back(i);

    while (sz(q)) {
        int v = q.back(); q.pop_back();
        topo.push_back(v);
        trav(v2, adj2[v])
            if (!--indeg[v2])
                q.push_back(v2);
    }

    if (sz(topo) < m)
        cout << "0\n", exit(0);

    vector<int> first(n, -1);
    rep(i, n)
        if (!is_prev[i])
            first[dsu.find(i)] = i;

    trav(rep, topo) {
        int v = first[rep];
        while (v != -1)
            cout << (v + 1) << ' ', v = next[v];
    }

    cout << '\n';
    return 0;
}