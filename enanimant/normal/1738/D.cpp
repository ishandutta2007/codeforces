/*
 * author:  ADMathNoob
 * created: 09/30/22 10:35:12
 * problem: https://codeforces.com/contest/1738/problem/D
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

#ifdef _DEBUG
#include "../.cp/algorithms/debug/debug.h"
#else
#define debug(...) 42
#endif

template <typename T>
class Graph {
 public:
  struct Edge {
    int from;
    int to;
    T cost;
  };

  int n;
  vector<vector<int>> g;
  vector<Edge> edges;

  function<bool(int)> ignore;

  Graph(int n_) : n(n_), g(n), ignore(nullptr) {}

  virtual int add(int from, int to, T cost) = 0;

  virtual void set_ignore_edge_rule(const function<bool(int)>& f) {
    ignore = f;
  }

  virtual void reset_ignore_edge_rule() {
    ignore = nullptr;
  }
};

template <typename T>
class Digraph : public Graph<T> {
 public:
  using Graph<T>::n;
  using Graph<T>::g;
  using Graph<T>::edges;
  using Graph<T>::ignore;

  Digraph(int n_) : Graph<T>(n_) {}

  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    const int id = edges.size();
    g[from].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }

  Digraph<T> reverse() const {
    Digraph<T> rev(n);
    for (const auto& e : edges) {
      rev.add(e.to, e.from, e.cost);
    }
    if (ignore != nullptr) {
      rev.set_ignore_edge_rule([&](int id) {
        return ignore(id);
      });
    }
    return rev;
  }
};

/**
 * @brief Finds the topsort of the given digraph.
 *
 * @tparam T graph template parameter
 * @param g the graph
 * @return a topsort, or an empty vector if the digraph is not a DAG
 */
template <typename T>
vector<int> FindTopsort(const Digraph<T>& g) {
  vector<int> indeg(g.n, 0);
  for (int id = 0; id < (int)g.edges.size(); id++) {
    if (g.ignore != nullptr && g.ignore(id)) {
      continue;
    }
    ++indeg[g.edges[id].to];
  }
  vector<int> x;
  for (int i = 0; i < g.n; i++) {
    if (indeg[i] == 0) {
      x.push_back(i);
    }
  }
  for (int ptr = 0; ptr < (int)x.size(); ptr++) {
    int i = x[ptr];
    for (int id : g.g[i]) {
      if (g.ignore != nullptr && g.ignore(id)) {
        continue;
      }
      int to = g.edges[id].to;
      if (--indeg[to] == 0) {
        x.push_back(to);
      }
    }
  }
  if ((int)x.size() != g.n) {
    return vector<int>();
  }
  return x;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int x = 0; x < n; x++) {
      cin >> b[x];
      --b[x];
    }
    int minK = -1, maxK = n;
    for (int x = 0; x < n; x++) {
      assert(x != b[x]);
      const auto [low, high] = minmax(x, b[x]);
      // low <= k < high
      minK = max(minK, low);
      maxK = min(maxK, high - 1);
    }
    // debug(minK, maxK);
    assert(minK == maxK);
    const int k = minK; // -1 <= k < n
    
    vector<vector<int>> out(n);
    vector<int> group;
    for (int x = 0; x < n; x++) {
      if (0 <= b[x] && b[x] < n) {
        out[b[x]].push_back(x);
      } else {
        group.push_back(x);
      }
    }
    vector<int> a;
    while (true) {
      int last = -1;
      for (int x : group) {
        if (!out[x].empty()) {
          assert(last == -1);
          last = x;
        } else {
          a.push_back(x);
        }
      }
      if (last == -1) {
        break;
      }
      a.push_back(last);
      group = out[last];
    }
    assert((int)a.size() == n);
    
    cout << k + 1 << '\n';
    for (int i = 0; i < n; i++) {
      cout << a[i] + 1 << " \n"[i == n - 1];
    }
  }
  return 0;
}