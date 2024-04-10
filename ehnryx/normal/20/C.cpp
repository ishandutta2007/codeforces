#include <bits/stdc++.h>
using namespace std;

// START #include "../../../lca/graph/graph.h"

// AJDACENCY LIST

template <typename weight_t>  // weighted
struct graph_list {
  static constexpr bool weighted = true;
  vector<vector<pair<int, weight_t>>> adj;
  graph_list(int n): adj(n) {}
  int size() const { return (int)adj.size(); }
  void add_edge(int a, int b, weight_t c) {
    adj[a].emplace_back(b, c);
  }
  const vector<pair<int, weight_t>>& operator [] (int u) const {
    return adj[u];
  }
};

template <>  // unweighted
struct graph_list<void> {
  static constexpr bool weighted = false;
  vector<vector<int>> adj;
  graph_list(int n): adj(n) {}
  int size() const { return (int)adj.size(); }
  void add_edge(int a, int b) {
    adj[a].emplace_back(b);
  }
  const vector<int>& operator [] (int u) const {
    return adj[u];
  }
};

// AJDACENCY MATRIX

template <typename> struct graph_matrix;

template <typename weight_t>
class adj_list_view {
  static constexpr bool _weighted = graph_matrix<weight_t>::weighted;
  const graph_matrix<weight_t>* _graph;
  int _from;
  struct iterator {
    using out_t = conditional_t<_weighted, pair<int, weight_t>, int>;
    const graph_matrix<weight_t>* graph;
    int from, to;
    iterator(): graph(nullptr), from(-1), to(-1) {}
    iterator(const graph_matrix<weight_t>* g, int f, int t): graph(g), from(f), to(t) {}
    out_t operator * () const {
      if constexpr (_weighted) {
        return pair(to, graph->adj[from][to]);
      } else {
        return to;
      }
    }
    iterator& operator ++ () {
      while (++to < (int)graph->adj[from].size()) {
        if constexpr (_weighted) {
          if (graph->adj[from][to] != graph->inf) {
            break;
          }
        } else {
          if (graph->adj[from][to]) {
            break;
          }
        }
      }
      return *this;
    }
    bool operator == (const iterator& o) const { return to == o.to; }
    bool operator != (const iterator& o) const { return to != o.to; }
  };
public:
  adj_list_view(const graph_matrix<weight_t>* g, int u):
    _graph(g), _from(u) {}
  iterator begin() const {
    return ++iterator(_graph, _from, -1);
  }
  iterator end() const {
    return iterator(_graph, _from, (int)_graph->adj[_from].size());
  }
};

template <typename weight_t>  // weighted
struct graph_matrix {
  static constexpr bool weighted = true;
  vector<vector<weight_t>> adj;
  weight_t inf;
  graph_matrix(int n, weight_t _inf):
    adj(n, vector<weight_t>(n, _inf)), inf(_inf) {}
  int size() const { return (int)adj.size(); }
  void add_edge(int a, int b, weight_t c) {
    adj[a][b] = c;
  }
  adj_list_view<weight_t> operator [] (int u) const {
    return adj_list_view(this, u);
  }
};

template <>  // unweighted
struct graph_matrix<void> {
  static constexpr bool weighted = false;
  vector<vector<bool>> adj;
  graph_matrix(int n): adj(n, vector<bool>(n)) {}
  int size() const { return (int)adj.size(); }
  void add_edge(int a, int b) {
    adj[a][b] = true;
  }
  adj_list_view<void> operator [] (int u) const {
    return adj_list_view(this, u);
  }
};

// MISC

template <typename G> struct is_graph_checker {};
template <template <typename> typename G, typename T>
struct is_graph_checker<G<T>> {
  static constexpr bool is_graph_list = is_same_v<G<T>, graph_list<T>>;
  static constexpr bool is_graph_matrix = is_same_v<G<T>, graph_matrix<T>>;
  static constexpr bool value = is_graph_list || is_graph_matrix;
  using weight_t = T;
};
template <typename G>
constexpr bool is_graph_v = is_graph_checker<G>::value;
template <typename G>
constexpr bool is_graph_list_v = is_graph_checker<G>::is_graph_list;
template <typename G>
constexpr bool is_graph_matrix_v = is_graph_checker<G>::is_graph_matrix;
template <typename G>
using get_graph_weight_t = is_graph_checker<G>::weight_t;

template <template <typename> typename graph_t, typename T,
         enable_if_t<is_graph_v<graph_t<T>>, bool> = true>
ostream& operator << (ostream& os, const graph_t<T>& g) {
  for (int u = 0; u < g.size(); u++) {
    os << u << " -> [";
    if constexpr (is_void_v<T>) {
      for (int v : g[u]) {
        os << " " << v << ", ";
      }
    } else {
      for (auto [v, c] : g[u]) {
        os << " " << v << ":" << c << ", ";
      }
    }
    os << "]\n";
  }
  return os;
}
// END #include "../../../lca/graph/graph.h"
// START #include "../../../lca/graph/dijkstra.h"

template <typename graph_t>
struct dijkstra {
  using weight_t = get_graph_weight_t<graph_t>;
  vector<weight_t> dist;
  vector<int> parent;
  dijkstra(const graph_t& graph, int source, weight_t inf):
    dist(graph.size(), inf), parent(graph.size(), -1) {
    priority_queue<Item> to_visit;
    to_visit.emplace(source, -1, weight_t());
    //dist[source] = weight_t();
    // parent[source] = source;
    while (!to_visit.empty()) {
      auto [u, f, d] = to_visit.top();
      to_visit.pop();
      //if (d != dist[u]) continue;
      if (dist[u] != inf) continue;
      dist[u] = d;
      parent[u] = f;
      for (const auto& [v, c] : graph[u]) {
        if (dist[v] != inf) continue;
        to_visit.emplace(v, u, d + c);
      }
    }
  }
  const vector<weight_t>& get_dists() const { return dist; }
  const vector<int>& get_parents() const { return parent; }
  vector<int> get_path(int to) const {
    vector<int> path;
    for ( ; to != -1; to = parent[to]) {
      path.push_back(to);
    }
    reverse(path.begin(), path.end());
    return path;
  }
  struct Item {
    int u, from;
    weight_t d;
    bool operator < (const Item& o) const { return d > o.d; }
  };
};

// END #include "../../../lca/graph/dijkstra.h"

using ll = long long;
using ld = long double;
using pt = complex<ld>;

constexpr char nl = '\n';
constexpr int MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());


int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);

  int n, m;
  cin >> n >> m;

  graph_list<ll> g(n + 1);

  for(int i=0; i<m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    g.add_edge(a, b, c);
    g.add_edge(b, a, c);
  }

  dijkstra bfs(g, 1, -1);
  if(bfs.get_dists()[n] == -1) {
    cout << -1 << nl;
  } else {
    for (int v : bfs.get_path(n)) {
      cout << v << " ";
    }
    cout << nl;
  }

  return 0;
}