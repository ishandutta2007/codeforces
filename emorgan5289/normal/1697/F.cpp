#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

#ifndef ATCODER_TWOSAT_HPP
#define ATCODER_TWOSAT_HPP 1

#include <cassert>
#include <vector>

#ifndef ATCODER_INTERNAL_SCC_HPP
#define ATCODER_INTERNAL_SCC_HPP 1

#include <algorithm>
#include <utility>
#include <vector>

#ifndef ATCODER_INTERNAL_CSR_HPP
#define ATCODER_INTERNAL_CSR_HPP 1

#include <algorithm>
#include <utility>
#include <vector>

namespace atcoder {
namespace internal {

template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    explicit csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};

}  // namespace internal

}  // namespace atcoder

#endif  // ATCODER_INTERNAL_CSR_HPP

namespace atcoder {
namespace internal {

// Reference:
// R. Tarjan,
// Depth-First Search and Linear Graph Algorithms
struct scc_graph {
  public:
    explicit scc_graph(int n) : _n(n) {}

    int num_vertices() { return _n; }

    void add_edge(int from, int to) { edges.push_back({from, {to}}); }

    // @return pair of (# of scc, scc id)
    std::pair<int, std::vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                auto to = g.elist[i].to;
                if (ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };
        for (int i = 0; i < _n; i++) {
            if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }

    std::vector<std::vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        std::vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        std::vector<std::vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++) {
            groups[ids.second[i]].push_back(i);
        }
        return groups;
    }

  private:
    int _n;
    struct edge {
        int to;
    };
    std::vector<std::pair<int, edge>> edges;
};

}  // namespace internal

}  // namespace atcoder

#endif  // ATCODER_INTERNAL_SCC_HPP

namespace atcoder {

// Reference:
// B. Aspvall, M. Plass, and R. Tarjan,
// A Linear-Time Algorithm for Testing the Truth of Certain Quantified Boolean
// Formulas
struct two_sat {
  public:
    two_sat() : _n(0), scc(0) {}
    explicit two_sat(int n) : _n(n), _answer(n), scc(2 * n) {}

    void add_clause(int i, bool f, int j, bool g) {
        assert(0 <= i && i < _n);
        assert(0 <= j && j < _n);
        scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
        scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
    }
    bool satisfiable() {
        auto id = scc.scc_ids().second;
        for (int i = 0; i < _n; i++) {
            if (id[2 * i] == id[2 * i + 1]) return false;
            _answer[i] = id[2 * i] < id[2 * i + 1];
        }
        return true;
    }
    std::vector<bool> answer() { return _answer; }

  private:
    int _n;
    std::vector<bool> _answer;
    internal::scc_graph scc;
};

}  // namespace atcoder

#endif  // ATCODER_TWOSAT_HPP

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        int n, m, k; cin >> n >> m >> k;
        atcoder::two_sat ts(n*(k+1));

        // constraint that a[i] >= x
        auto get = [&](int i, int x) {
            assert(0 <= i && i < n);
            assert(1 <= x && x <= k+1);
            return (k+1)*i+x-1;
        };

        for (int i = 0; i < n; i++)
            for (int x = 1; x <= k; x++)
                debug(i, x, get(i, x));

        // a[i] >= x+1 => a[i] >= x
        for (int i = 0; i < n; i++)
            for (int x = 1; x < k; x++)
                ts.add_clause(get(i, x+1), false, get(i, x), true);

        // a[i] >= x => a[i+1] >= x
        for (int i = 0; i < n-1; i++)
            for (int x = 1; x <= k; x++)
                ts.add_clause(get(i, x), false, get(i+1, x), true);

        // a[i] >= 1
        for (int i = 0; i < n; i++)
            ts.add_clause(get(i, 1), true, get(i, 1), true);

        // !(a[i] >= k+1)
        for (int i = 0; i < n; i++)
            ts.add_clause(get(i, k+1), false, get(i, k+1), false);

        while (m--) {
            int t; cin >> t;
            if (t == 1) {
                int i, x; cin >> i >> x; i--;
                // a[i] >= x => a[i] >= x+1
                ts.add_clause(get(i, x), false, get(i, x+1), true);
            }
            if (t == 2) {
                int i, j, y; cin >> i >> j >> y; i--, j--;
                // a[i] >= x => !(a[j] >= y-x+1)
                for (int x = 1; x <= k; x++) {
                    if (x > y) {
                        ts.add_clause(get(i, x), false, get(i, x), false);
                        ts.add_clause(get(j, x), false, get(j, x), false);
                    } else if (x > y-k) {
                        ts.add_clause(get(i, x), false, get(j, y+1-x), false);
                        ts.add_clause(get(j, x), false, get(i, y+1-x), false);
                    }
                }
            }
            if (t == 3) {
                int i, j, y; cin >> i >> j >> y; i--, j--;
                // !(a[i] >= x) => a[j] >= y-x+1
                for (int x = 1; x <= k; x++) {
                    if (x <= y-k) {
                        ts.add_clause(get(i, x), true, get(i, x), true);
                        ts.add_clause(get(j, x), true, get(j, x), true);
                    } else if (x < y) {
                        ts.add_clause(get(i, x), true, get(j, y+1-x), true);
                        ts.add_clause(get(j, x), true, get(i, y+1-x), true);
                    }
                }
            }
        }

        bool ok = ts.satisfiable();
        if (ok) {
            auto b = ts.answer();
            vector<int> a(n);
            for (int i = 0; i < n; i++)
                for (int x = 1; x <= k; x++)
                    if (b[get(i, x)]) a[i] = x;
            for (int i = 0; i < n; i++)
                cout << a[i] << " \n"[i == n-1];
        } else {
            cout << "-1\n";
        }
    }
}