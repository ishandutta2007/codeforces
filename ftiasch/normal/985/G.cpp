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

using Long = uint64_t;

Long binom2(Long n) { return n * (n - 1) / 2; }

int main() {
  int n, m, a, b, c;
  scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
  std::vector<std::pair<int, int>> edges(m);
  std::vector<int> deg(n), left_deg(n), right_deg(n), cover(n + 1);
  std::vector<std::vector<int>> graph(n);
  for (int i = 0, u, v; i < m; ++i) {
    scanf("%d%d", &u, &v);
    if (u > v) {
      std::swap(u, v);
    }
    edges[i] = {u, v};
    deg[u]++;
    deg[v]++;
    left_deg[v]++;
    right_deg[u]++;
    cover[u]--;
    cover[v - 1]++;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  for (int u = n; u--;) {
    cover[u] += cover[u + 1];
    std::sort(graph[u].begin(), graph[u].end());
  }
  std::vector<std::vector<Long>> count(3, std::vector<Long>(n));
  std::vector<Long> tmp(n);
  {
    int sum_right_deg = 0;
    for (int u = n; u--;) {
      int right = n - u - 1;
      count[0][u] += binom2(right);
      count[0][u] -= (right - 1ULL) * right_deg[u];
      count[0][u] -= sum_right_deg;
      count[0][u] += binom2(right_deg[u]);
      count[0][u] += tmp[u];
      sum_right_deg += right_deg[u];
      for (int i = 0; i < deg[u]; ++i) {
        int v = graph[u][i];
        if (v < u) {
          tmp[v] += deg[u] - i - 1;
        }
      }
    }
  }
  {
    std::fill(tmp.begin(), tmp.end(), 0);
    for (int u = 0; u < n; ++u) {
      int left = u;
      int right = n - u - 1;
      count[1][u] += 1ULL * left * right;
      count[1][u] -= 1ULL * left_deg[u] * right;
      count[1][u] -= 1ULL * left * right_deg[u];
      count[1][u] -= cover[u];
      count[1][u] += 1ULL * left_deg[u] * right_deg[u];
      count[1][u] += tmp[u];
      for (int i = 0; i < deg[u]; ++i) {
        int v = graph[u][i];
        if (u < v) {
          tmp[v] += deg[u] - i - 1;
        }
      }
    }
    std::fill(tmp.begin(), tmp.end(), 0);
    for (int u = n; u--;) {
      count[1][u] += tmp[u];
      for (int i = 0; i < deg[u]; ++i) {
        int v = graph[u][i];
        if (v < u) {
          tmp[v] += i;
        }
      }
    }
  }
  {
    int sum_left_deg = 0;
    std::fill(tmp.begin(), tmp.end(), 0);
    for (int u = 0; u < n; ++u) {
      int left = u;
      count[2][u] += binom2(left);
      count[2][u] -= (left - 1ULL) * left_deg[u];
      count[2][u] -= sum_left_deg;
      count[2][u] += binom2(left_deg[u]);
      count[2][u] += tmp[u];
      sum_left_deg += left_deg[u];
      for (int i = 0; i < deg[u]; ++i) {
        int v = graph[u][i];
        if (u < v) {
          tmp[v] += i;
        }
      }
    }
  }
  for (int u = 0; u < n; ++u) {
    graph[u].clear();
  }
  for (auto [u, v] : edges) {
    if (deg[u] < deg[v]) {
      graph[v].push_back(u);
    } else {
      graph[u].push_back(v);
    }
  }
  std::fill(tmp.begin(), tmp.end(), -1);
  for (int u = 0; u < n; ++u) {
    for (int v : graph[u]) {
      tmp[v] = u;
    }
    for (int v : graph[u]) {
      for (int w : graph[v]) {
        if (tmp[w] == u) {
          std::array<int, 3> t{u, v, w};
          std::sort(t.begin(), t.end());
          count[0][t[0]]--;
          count[1][t[1]]--;
          count[2][t[2]]--;
        }
      }
    }
  }
  // std::cout << count << std::endl;
  Long result = 0;
  for (int u = 0; u < n; ++u) {
    result += count[0][u] * a * u;
    result += count[1][u] * b * u;
    result += count[2][u] * c * u;
  }
  printf("%llu\n", static_cast<unsigned long long>(result));
}