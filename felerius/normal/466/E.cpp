// Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
// Problem: (53) Information Graph (Difficulty: 6) (http://codeforces.com/problemset/problem/466/E)


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

namespace snippets_dsu {
    struct DSU {
        vi p;
        explicit DSU(int n) : p(n, -1) {}

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
using namespace snippets_dsu;

const int N = 100'000;
vi adj[N];
int time_ = 0;
int enter[N], exit_[N];

void dfs(int v, int d) {
    enter[v] = time_++;
    for (auto v2 : adj[v])
        dfs(v2, d + 1);
    exit_[v] = time_ + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    vector<array<int, 3>> evt(m);
    for (auto& [t, a, b] : evt) {
        cin >> t >> a; --a;
        if (t != 2)
            cin >> b, --b;
    }

    vector<vpi> q(m);
    int qi = 0;
    for (auto [t, a, b] : evt)
        if (t == 3)
            q[b].emplace_back(a, qi++);

    vector<bool> root(n, true);
    for (auto [t, a, b] : evt)
        if (t == 1)
            adj[b].push_back(a), root[a] = false;
    rep(i, n)
        if (root[i])
            dfs(i, 0);

    DSU dsu(n);
    vector<bool> ans(qi);
    int pi = 0;
    for (auto [t, a, b] : evt) {
        if (t == 1)
            dsu.join(a, b);
        if (t != 2)
            continue;
        for (auto [v, i] : q[pi++])
            ans[i] = dsu.same(a, v) && enter[v] <= enter[a] && exit_[a] <= exit_[v];
    }

    for (bool ai : ans)
        cout << (ai ? "YES\n" : "NO\n");

    return 0;
}