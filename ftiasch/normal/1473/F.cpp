#include <bits/stdc++.h>

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

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    int m = *std::max_element(a.begin(), a.end());
    NetworkDinic<> net(n + n + 2);
    int infinity = n * 100000 + 1;
    {
      std::vector<int> last(m + 1, -1);
      for (int i = n; i--;) {
        for (int j = a[i]; j <= m; j += a[i]) {
          if (~last[j]) {
            net.add(last[j], i, infinity);
          }
        }
        if (~last[a[i]]) {
          net.add(last[a[i]], n + i, infinity);
        }
        net.add(i, last[a[i]] = n + i, infinity);
      }
    }
    int source = n + n;
    int target = source + 1;
    int sum = 0;
    for (int i = 0, b; i < n; ++i) {
      scanf("%d", &b);
      if (b > 0) {
        sum += b;
        net.add(source, i, b);
      } else {
        net.add(i, target, -b);
      }
    }
    printf("%d\n", sum - net.max_flow(source, target));
  }
}