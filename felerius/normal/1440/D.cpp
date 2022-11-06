// Graph Subset Problem (https://codeforces.com/contest/1440/problem/D)

#include <bits/stdc++.h>
#if __has_include("dbg.h")
#  include "dbg.h"
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt; cin >> tt;
    while (tt--) {
        int n, m, k; cin >> n >> m >> k;

        vector<unordered_set<int>> adj(n);
        rep(i, m) {
            int u, v; cin >> u >> v; --u, --v;
            adj[u].insert(v);
            adj[v].insert(u);
        }

        if (k == 1) {
            cout << "2\n1\n";
            continue;
        }

        if ((ll)k * (k - 1) / 2 >  m) {
            cout << "-1\n";
            continue;
        }

        priority_queue<pair<int, int>> q;
        rep(i, n)
            q.emplace(-sz(adj[i]), i);

        bool done = false;
        while (sz(q) && -q.top().first < k) {
            auto [d, v] = q.top(); q.pop(); d = -d;
            if (d > sz(adj[v]))
                continue;

            if (d == k - 1) {
                bool all = true;
                trav(v2, adj[v]) {
                    if (!all) break;
                    trav(v3, adj[v]) {
                        all &= v2 == v3 || adj[v2].find(v3) != end(adj[v2]);
                        if (!all) break;
                    }
                }

                if (all) {
                    cout << "2\n" << (v + 1);
                    trav(v2, adj[v]) cout << ' ' << (v2 + 1);
                    cout << '\n';
                    done = true;
                    break;
                }
            }

            trav(v2, adj[v]) {
                adj[v2].erase(v);
                q.emplace(-sz(adj[v2]), v2);
            }
            adj[v].clear();
        }

        if (!done) {
            vector<int> left;
            rep(i, n)
                if (sz(adj[i]))
                    left.push_back(i);
            if (sz(left)) {
                cout << "1 " << sz(left) << '\n';
                trav(v, left)
                    cout << (v + 1) << ' ';
                cout << '\n';
            } else
                cout << "-1\n";
        }
    }

    return 0;
}