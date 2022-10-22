#include <bits/stdc++.h>
using namespace std;

//%:include "utility/fast_input.h"
//%:include "utility/output.h"

// START %:include "graph/dinic.h"

#include <cassert>
#include <limits>
#include <queue>
#include <vector>

template <typename T>
struct dinic {
  struct edge {
    int to, rev;
    T cap, flow;
    edge(int t, int r, const T& c, const T& f): to(t), rev(r), cap(c), flow(f) {}
  };
  std::vector<std::vector<edge>> adj;
  std::vector<int> layer, cur_edge;
  dinic(int n): adj(n), layer(n), cur_edge(n) {}

  int size() const { return (int)adj.size(); }

  void add_edge(int a, int b, const T& c = 1, bool bidirectional = false) {
    adj[a].emplace_back(b, (int)adj[b].size(), c, 0);
    adj[b].emplace_back(a, (int)adj[a].size() - 1, bidirectional ? c : 0, 0);
  }
  bool left_of_min_cut(int u) const { return layer[u] != -1; }
  void clear_flow() {
    for (std::vector<edge>& adjacency : adj) {
      for (edge& e : adjacency) {
        e.flow = 0;
      }
    }
  }

  bool bfs(int s, int t) {
    fill(begin(layer), end(layer), -1);
    fill(begin(cur_edge), end(cur_edge), 0);
    std::queue<int> todo;
    layer[s] = 0;
    todo.push(s);
    while (!empty(todo) && layer[t] == -1) {
      int u = todo.front();
      todo.pop();
      for (const edge& e : adj[u]) {
        if (layer[e.to] == -1 && e.flow < e.cap) {
          layer[e.to] = layer[u] + 1;
          todo.push(e.to);
        }
      }
    }
    return layer[t] != -1;
  }

  T dfs(int u, int t, T f) {
    if (u == t || f == 0) return f;
    T res = 0;
    for (int i = cur_edge[u]; i < (int)adj[u].size() && f != 0; i++) {
      cur_edge[u] = i; // save current edge
      if (layer[u] + 1 != layer[adj[u][i].to]) continue;
      if (T cur_flow = dfs(adj[u][i].to, t, min(f, adj[u][i].cap - adj[u][i].flow))) {
        adj[u][i].flow += cur_flow;
        adj[adj[u][i].to][adj[u][i].rev].flow -= cur_flow;
        res += cur_flow;
        f -= cur_flow;
      }
    }
    return res;
  }

  T flow(int source, int sink, int max_iters = std::numeric_limits<int>::max()) {
    if constexpr (!std::is_integral_v<T>) {
      assert(max_iters < std::numeric_limits<int>::max());
    }
    T inf = std::numeric_limits<T>::max();
    T res = 0;
    for (int i = 0; i < max_iters && bfs(source, sink); i++) {
      while (T cur_flow = dfs(source, sink, inf)) {
        res += cur_flow;
      }
    }
    return res;
  }
};

// END %:include "graph/dinic.h"

using ll = long long;
using ld = long double;

constexpr char nl = '\n';
constexpr int MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());


int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
#ifdef USING_FAST_INPUT
  fast_input cin;
#endif

  int n1, n2, m, q;
  cin >> n1 >> n2 >> m >> q;

  map<pair<int, int>, int> edges;
  dinic<int> graph(n1 + n2 + 2);
  const int source = 0;
  const int sink = n1 + n2 + 1;

  for(int i=1; i<=n1; i++) {
    graph.add_edge(source, i);
  }
  for(int i=1; i<=n2; i++) {
    graph.add_edge(i + n1, sink);
  }

  for(int i=0; i<m; i++) {
    int a, b;
    cin >> a >> b;
    edges[pair(a, b)] = i + 1;
    graph.add_edge(a, b + n1);
  }
  graph.flow(source, sink);

  ll sum = 0;

  vector<int> cut;
  set<pair<int, int>> have;
  for(int i=1; i<=n1; i++) {
    if(!graph.left_of_min_cut(i)) {
      cut.push_back(i);
      for(const auto& e : graph.adj[i]) {
        if(e.flow && e.to > i) {
          have.emplace(i, e.to - n1);
          sum += edges[pair(i, e.to - n1)];
        }
      }
    }
  }
  for(int i=1; i<=n2; i++) {
    if(graph.left_of_min_cut(i + n1)) {
      cut.push_back(i + n1);
      for(const auto& e : graph.adj[i + n1]) {
        if(e.flow && e.to < i + n1) {
          have.emplace(e.to, i);
          sum += edges[pair(e.to, i)];
        }
      }
    }
  }

  while(q--) {
    int t;
    cin >> t;
    if(t == 1) {
      cout << 1 << nl;
      if (cut.back() <= n1) {
        cout << cut.back() << nl;
      } else {
        cout << -(cut.back() - n1) << nl;
      }
      for(const auto& e : graph.adj[cut.back()]) {
        if(e.flow && (e.to < cut.back()) == (cut.back() > n1)) {
          int l = min(cut.back(), e.to);
          int r = max(cut.back(), e.to);
          assert(have.erase(pair(l, r - n1)));
          sum -= edges[pair(l, r - n1)];
        }
      }
      cut.pop_back();
      cout << sum << nl;
    } else {
      cout << size(have) << nl;
      for(auto it : have) {
        cout << edges[it] << " ";
      }
      cout << nl;
    }
    cout.flush();
  }

  return 0;
}