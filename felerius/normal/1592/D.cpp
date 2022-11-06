// Hemose in ICPC ? (https://codeforces.com/contest/1592/problem/D)
#pragma GCC optimize("fast-math")
// begin "cp-lib/prelude.hpp"
#include <bits/stdc++.h>
#ifdef LOCAL
#  include <dbg.h>
#else
#  define dbg(...) do {} while (0)
#endif

#define cp_lib_4th(_1, _2, _3, x, ...)  x
#define cp_lib_rep(i, l, r)             for (int i = (l); (i) < (r); ++(i))
#define cp_lib_rep0(i, r)               cp_lib_rep(i, 0, r)
#define rep(...)                        cp_lib_4th(__VA_ARGS__, cp_lib_rep, cp_lib_rep0, _)(__VA_ARGS__)
#define cp_lib_repr(i, r, l, ...)       for (int i = (r); (i) >= (l); --(i))
#define repr(...)                       cp_lib_repr(__VA_ARGS__, 0)
#define all(a)                          ::begin(a),::end(a)
#define trav(a, b)                      for (auto&& a : (b))

using namespace std;
using ll = long long;
using ld = long double;
[[maybe_unused]] static constexpr int INF = int(1e9 + 5);
[[maybe_unused]] static constexpr ll INFL = ll(INF) * INF;
template <class C> int sz(const C& c) { return int(::size(c)); }
// end "cp-lib/prelude.hpp"

int main() {
    cin.sync_with_stdio(false);

    int n; cin >> n;
    vector adj(n, vector<int>());
    rep(_, n - 1) {
        int u, v; cin >> u >> v; --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto ask = [&](auto& nodes) {
        cout << "? " << sz(nodes);
        trav(v, nodes)
            cout << ' ' << (v + 1);
        cout << '\n' << flush;
        int ans; cin >> ans;
        return ans;
    };

    vector nodes(n, 0);
    iota(all(nodes), 0);
    auto mx = ask(nodes);

    int rem_e = n - 1;
    while (rem_e > 1) {
        vector seen(n, false);
        nodes.clear();
        int rem = rem_e / 2;
        rep(v0, n) {
            if (!sz(adj[v0]) || seen[v0])
                continue;
            auto dfs = [&](int v, int p, auto&& self) -> void {
                if (rem) {
                    nodes.push_back(v);
                    rem -= (p != -1);
                }
                seen[v] = true;

                trav(v2, adj[v]) {
                    if (v2 == p)
                        continue;
                    self(v2, v, self);
                }
            };
            dfs(v0, -1, dfs);
        }

        set nodes_set(all(nodes));
        if (ask(nodes) == mx) {
            rep(v, n) {
                if (!nodes_set.count(v))
                    adj[v].clear();
                else {
                    auto it = remove_if(all(adj[v]), [&](int v2) { return !nodes_set.count(v2); });
                    adj[v].erase(it, end(adj[v]));
                }
            }
            rem_e /= 2;
        } else {
            rep(v, n) {
                if (!nodes_set.count(v))
                    continue;
                auto it = remove_if(all(adj[v]), [&](int v2) { return nodes_set.count(v2); });
                adj[v].erase(it, end(adj[v]));
            }
            rem_e = (rem_e + 1) / 2;
        }
    }

    int u = 0;
    while (!sz(adj[u]))
        ++u;
    cout << "! " << (u + 1) << ' ' << (adj[u][0] + 1) << '\n';
}