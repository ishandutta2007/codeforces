// Contest: Codeforces Round #610 (Div. 2) (https://codeforces.com/contest/1282)
// Problem: E: The Cake Is a Lie (https://codeforces.com/contest/1282/problem/E)


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

#if __cplusplus >= 201703L
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

#if __cplusplus >= 201703L
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define MAYBE_UNUSED
#endif

MAYBE_UNUSED static constexpr int INF = (int)1e9;
MAYBE_UNUSED static constexpr ll INFL = (ll)1e18;
//endregion }}}

vector<array<int, 3>> p;
vector<vector<pair<int, pi>>> adj;

using ListIter = list<int>::iterator;

void dfs(int v, list<int>& l, ListIter it) {
    auto [a, b, c] = p[v];
    int up_a = *prev(it), up_b = *it;
    int other = (a != up_a && a != up_b) ? a : (b != up_a && b != up_b) ? b : c;
    pi up_edge = minmax(up_a, up_b);
    if (sz(adj[v]) == 1)
        l.emplace(it, other);
    else if (sz(adj[v]) == 2) {
        auto [v2, down_edge] = adj[v][adj[v][0].second == up_edge];
        if (down_edge == minmax({up_a, other}))
            it = l.emplace(it, other);
        else
            l.emplace(it, other);
        dfs(v2, l, it);
    } else {
        pair<int, pi> e1, e2;
        if (adj[v][0].second == up_edge)
            e1 = adj[v][1], e2 = adj[v][2];
        else if (adj[v][1].second == up_edge)
            e1 = adj[v][0], e2 = adj[v][2];
        else
            e1 = adj[v][0], e2 = adj[v][1];
        if (e1.second == minmax({up_b, other}))
            swap(e1, e2);
        auto it2 = l.emplace(it, other);
        dfs(e1.first, l, it2);
        dfs(e2.first, l, it);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        p.resize(n - 2);
        for (auto& [a, b, c] : p) cin >> a >> b >> c;
        if (n == 3) {
            cout << "1 2 3\n1\n";
            continue;
        }

        trav(pi, p) sort(all(pi));
        adj.clear();
        adj.resize(n - 2);
        map<pi, int> m;
        rep(i, n - 2) {
            auto [a, b, c] = p[i];
            for (auto e : {pair(a, b), {a, c}, {b, c}}) {
                auto it = m.lower_bound(e);
                if (it != end(m) && it->first == e)
                    adj[i].emplace_back(it->second, e), adj[it->second].emplace_back(i, e), m.erase(it);
                else
                    m.emplace_hint(it, e, i);
            }
        }

        int v = 0;
        while (sz(adj[v]) != 1)
            ++v;
        auto [to, e] = adj[v][0];
        auto [a, b, c] = p[v];
        int other = (a != e.first && a != e.second) ? a : (b != e.first && b != e.second) ? b : c;
        list<int> l = {other, e.first, e.second};
        dfs(to, l, prev(end(l)));

        for (auto vi : l)
            cout << vi << ' ';
        cout << '\n';

        vector<int> indeg(n - 2);
        vector<bool> done(n - 2);
        vector<int> deg1;
        rep(i, n - 2)
            if ((indeg[i] = sz(adj[i])) == 1)
                deg1.push_back(i);

        while (sz(deg1)) {
            auto vi = deg1.back(); deg1.pop_back();
            cout << (vi + 1) << ' ';
            done[vi] = true;
            for (auto [v2, _] : adj[vi])
                if (!done[v2] && --indeg[v2] == 1)
                    deg1.push_back(v2);
        }
        cout << '\n';
    }

    return 0;
}