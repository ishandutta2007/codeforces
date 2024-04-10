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

#line 1 "/home/ftiasch/Documents/shoka/network.h"
#include <cmath>
#include <queue>
#line 4 "/home/ftiasch/Documents/shoka/network.h"
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
#line 4 "sol.cpp"

#include <bits/stdc++.h>

const int N = 100;
const int M = 200000;

int n, target, w[N], magic[N], level[N];
bool is_prime[M + 1];

int solve(int max_level) {
  NetworkDinic net(n + 2);
  int source = n;
  int target = n + 1;
  std::pair<int, int> max_one{0, -1};
  for (int i = 0; i < n; ++i) {
    if (magic[i] == 1 && level[i] <= max_level) {
      max_one = std::max(max_one, {w[i], i});
    }
  }
  auto valid = [&](int i) {
    return (level[i] <= max_level && (magic[i] > 1 || i == max_one.second));
  };
  int sum_w = 0;
  for (int i = 0; i < n; ++i) {
    if (valid(i)) {
      sum_w += w[i];
      if (magic[i] & 1) {
        net.add(source, i, w[i]);
        for (int j = 0; j < n; ++j) {
          if (valid(j) && (~magic[j] & 1) && is_prime[magic[i] + magic[j]]) {
            net.add(i, j, 100000);
          }
        }
      } else {
        net.add(i, target, w[i]);
      }
    }
  }
  return sum_w - net.max_flow(source, target);
}

int main() {
  std::fill(is_prime, is_prime + (M + 1), true);
  for (int p = 2; p <= M; ++p) {
    if (is_prime[p]) {
      for (int d = p + p; d <= M; d += p) {
        is_prime[d] = false;
      }
    }
  }
  scanf("%d%d", &n, &target);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", w + i, magic + i, level + i);
  }
  int low = 1;
  int high = n + 1;
  while (low < high) {
    int middle = (low + high) >> 1;
    if (solve(middle) >= target) {
      high = middle;
    } else {
      low = middle + 1;
    }
  }
  printf("%d\n", high <= n ? high : -1);
}