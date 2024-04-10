#line 1 "/home/ftiasch/Documents/shoka/debug.h"
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <vector>

namespace {

template <typename Tuple, size_t... Index>
std::ostream &serialize_tuple(std::ostream &out, const Tuple &t,
                              std::index_sequence<Index...>) {
  out << "(";
  (..., (out << (Index == 0 ? "" : ", ") << std::get<Index>(t)));
  return out << ")";
}

} // namespace

template <typename A, typename B>
std::ostream &operator<<(std::ostream &out, const std::pair<A, B> &v) {
  return out << "(" << v.first << ", " << v.second << ")";
}

template <typename... T>
std::ostream &operator<<(std::ostream &out, const std::tuple<T...> &t) {
  return serialize_tuple(out, t, std::make_index_sequence<sizeof...(T)>());
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
  out << "[";
  bool first = true;
  for (auto &&e : v) {
    if (first) {
      first = false;
    } else {
      out << ", ";
    }
    out << e;
  }
  return out << "]";
}

template <typename T, size_t N>
std::ostream &operator<<(std::ostream &out, const std::array<T, N> &v) {
  return out << std::vector<T>(v.begin(), v.end());
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::list<T> &v) {
  out << "[";
  bool first = true;
  for (auto &&e : v) {
    if (first) {
      first = false;
    } else {
      out << ", ";
    }
    out << e;
  }
  return out << "]";
}

template <typename K>
std::ostream &operator<<(std::ostream &out, const std::set<K> &s) {
  out << "{";
  bool first = true;
  for (auto &&k : s) {
    if (first) {
      first = false;
    } else {
      out << ", ";
    }
    out << k;
  }
  return out << "}";
}

template <typename K, typename V>
std::ostream &operator<<(std::ostream &out, const std::map<K, V> &m) {
  out << "{";
  bool first = true;
  for (auto &&[k, v] : m) {
    if (first) {
      first = false;
    } else {
      out << ", ";
    }
    out << k << ": " << v;
  }
  return out << "}";
}

#define KV(x) #x << "=" << x << ";"
#line 2 "sol.cpp"

#include <bits/stdc++.h>

template <typename CostT> class SparsePrimalDual {
public:
  struct Result {
    int flow;
    CostT cost;
  };

  SparsePrimalDual(int n_, int m = 0)
      : n(n_), head(n, -1), pred(n), phi(n), dist(n) {
    edges.reserve(m << 1);
  }

  void add_edge(int u, int v, int capacity, CostT cost) {
    internal_add_edge(u, v, capacity, cost);
    internal_add_edge(v, u, 0, -cost);
  }

  Result augment(int source, int target,
                 int maxflow = std::numeric_limits<int>::max()) {
    const CostT MAX_COST = std::numeric_limits<CostT>::max();
    std::fill(dist.begin(), dist.end(), MAX_COST);
    PQ<std::pair<CostT, int>> pq;
    pq.emplace(dist[source] = 0, source);
    while (!pq.empty()) {
      auto [dist_u, u] = pq.top();
      pq.pop();
      if (dist_u == dist[u]) {
        for (int iterator = head[u]; ~iterator;
             iterator = edges[iterator].next) {
          auto &e = edges[iterator];
          int v = e.v;
          CostT cost = e.cost;
          // assert(e.rest == 0 || phi[u] + cost - phi[v] >= 0);
          if (e.rest > 0 && dist[v] > dist[u] + (phi[u] + cost - phi[v])) {
            dist[v] = dist[u] + (phi[u] + cost - phi[v]);
            pred[v] = iterator;
            pq.emplace(dist[v], v);
          }
        }
      }
    }
    if (dist[target] == MAX_COST) {
      return {0, 0};
    }
    int flow = maxflow;
    for (int v = target; v != source;) {
      flow = std::min(flow, edges[pred[v]].rest);
      v = edges[pred[v] ^ 1].v;
    }
    for (int v = target; v != source;) {
      edges[pred[v]].rest -= flow;
      edges[pred[v] ^ 1].rest += flow;
      v = edges[pred[v] ^ 1].v;
    }
    CostT cost = dist[target] + phi[target] - phi[source];
    for (int u = 0; u < n; ++u) {
      if (dist[u] < dist[target]) {
        phi[u] += dist[u];
      }
    }
    phi[target] += dist[target];
    return {flow, cost};
  }

  template <typename T>
  using PQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;

  struct Edge {
    int v, next, rest;
    CostT cost;
  };

  void internal_add_edge(int u, int v, int capacity, CostT cost) {
    edges.push_back(Edge{v, head[u], capacity, cost});
    head[u] = edges.size() - 1;
  }

  int n;
  std::vector<int> head, pred;
  std::vector<CostT> phi, dist;
  std::vector<Edge> edges;
};

const int M = 7;

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int source = (M + 2) * n;
  int target = source + 1;
  SparsePrimalDual<int> net(target + 1);
  auto add_edge = [&](int u, int v, int cap, int cost) {
    net.phi[u] = std::max(net.phi[u], net.phi[v] - cost);
    net.add_edge(u, v, cap, cost);
  };
  std::map<int, int> nxt;
  for (int i = n; i--;) {
    add_edge(n + i, target, 1, 0);
    if (nxt.count(a[i] - 1)) {
      add_edge(n + i, nxt[a[i] - 1], 1, 0);
    }
    if (nxt.count(a[i] + 1)) {
      add_edge(n + i, nxt[a[i] + 1], 1, 0);
    }
    if (i + 1 < n) {
      for (int r = 0; r < M; ++r) {
        add_edge((2 + r) * n + i, (2 + r) * n + (i + 1), 2, 0);
      }
      add_edge(n + i, (2 + a[i] % M) * n + (i + 1), 1, 0);
    }
    if (nxt.count(a[i])) {
      add_edge(i, nxt[a[i]], 2, 0);
    }
    add_edge(i, n + i, 1, -1);
    add_edge((2 + a[i] % M) * n + i, i, 1, 0);
    add_edge(source, i, 1, 0);
    nxt[a[i]] = i;
  }
  int result = 0;
  for (int _ = 0; _ < 2; ++_) {
    result -= net.augment(source, target, 1).cost;
  }
  printf("%d\n", result);
}