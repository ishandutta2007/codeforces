#line 1 "/home/ftiasch/Documents/shoka/network.h"
#include <cmath>
#include <queue>
#include <vector>
#include <limits>
#include <algorithm>

namespace network {

template <typename IntType> class IntValue {
public:
  using ValueType = IntType;

  static bool greater_than_zero(ValueType x) { return x > 0; }
};

template <int PRECISION> class DoubleValue {
public:
  using ValueType = double;
  constexpr static double EPSILON = pow(10, -PRECISION);

  static bool greater_than_zero(ValueType x) { return x > EPSILON; }
};

} // namespace network

template <typename Derived = network::IntValue<int>> class NetworkDinic {
public:
  using ValueType = typename Derived::ValueType;

  NetworkDinic(int n, int m = 0) : n(n), head(n, -1), level(n), current(n) {
    edges.reserve(m);
  }

  void add(int f, int t, ValueType c, bool back = true) {
    add_edge(f, t, c);
    if (back) {
      add_edge(t, f, static_cast<ValueType>(0));
    }
  }

  ValueType max_flow(int source, int target) {
    ValueType result = 0;
    while (bfs(source, target)) {
      std::copy(head.begin(), head.end(), current.begin());
      result += dfs(source, target, std::numeric_limits<ValueType>::max());
    }
    return result;
  }

private:
  struct Edge {
    int t;
    int next;
    ValueType c;
  };

  void add_edge(int f, int t, ValueType c) {
    edges.push_back(Edge{t, head[f], c});
    head[f] = static_cast<int>(edges.size()) - 1;
  }

  bool bfs(int source, int target) {
    std::fill(level.begin(), level.end(), -1);
    level[target] = 0;
    std::vector<int> queue{target};
    for (int h = 0; h < static_cast<int>(queue.size()) && !~level[source];
         ++h) {
      int u = queue[h];
      for (int iterator = head[u]; ~iterator; iterator = edges[iterator].next) {
        int v = edges[iterator].t;
        if (greater_than_zero(edges[iterator ^ 1].c) && !~level[v]) {
          level[v] = level[u] + 1;
          queue.push_back(v);
        }
      }
    }
    return ~level[source];
  }

  ValueType dfs(int u, int target, ValueType remain) {
    if (u == target) {
      return remain;
    }
    auto argumented = static_cast<ValueType>(0);
    for (auto &iterator = current[u]; ~iterator && greater_than_zero(remain);) {
      auto &e = edges[iterator];
      if (greater_than_zero(e.c) && level[u] == level[e.t] + 1) {
        auto tmp = dfs(e.t, target, std::min(e.c, remain));
        e.c -= tmp;
        edges[iterator ^ 1].c += tmp;
        remain -= tmp;
        argumented += tmp;
        if (!greater_than_zero(remain)) {
          return argumented;
        }
      }
      iterator = e.next;
    }
    level[u] = -1;
    return argumented;
  }

  static bool greater_than_zero(ValueType x) {
    return Derived::greater_than_zero(x);
  }

  int n;
  std::vector<int> head, level, current;
  std::vector<Edge> edges;
};
#line 2 "sol.cpp"

#include <bits/stdc++.h>

int main() {
  int n, b, q;
  scanf("%d%d%d", &n, &b, &q);
  std::vector<std::pair<int, int>> cons{{0, 0}, {b, n}};
  for (int i = 0, up, qty; i < q; ++i) {
    scanf("%d%d", &up, &qty);
    cons.emplace_back(up, qty);
  }
  std::sort(cons.begin(), cons.end());
  auto check = [&]() -> bool {
    int m = cons.size() - 1;
    NetworkDinic net(7 + b + m);
    // source - 0
    // target - 1
    for (int i = 0; i < 5; ++i) {
      net.add(0, 2 + i, n / 5);
    }
    for (int i = 0; i < b; ++i) {
      net.add(2 + (i % 5), 7 + i, 1);
    }
    int offset = 7 + b;
    for (int i = 0; i < m; ++i) {
      auto [l, q] = cons[i];
      auto [r, qq] = cons[i + 1];
      if (qq < q || qq - q > r - l) {
        return false;
      }
      for (int j = l; j < r; ++j) {
        net.add(7 + j, offset + i, 1);
      }
      net.add(offset + i, 1, qq - q);
    }
    return net.max_flow(0, 1) == n;
  };
  puts(check() ? "fair" : "unfair");
}