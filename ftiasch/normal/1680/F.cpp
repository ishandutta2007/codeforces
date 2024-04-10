#line 1 "/home/ftiasch/Documents/shoka/debug.h"
#include <iostream>
#include <list>
#include <map>
#include <queue>
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
std::ostream &operator<<(std::ostream &out, const std::deque<T> &v) {
  return out << std::vector<T>(v.begin(), v.end());
}

template <typename T, typename S, typename C>
std::ostream &operator<<(std::ostream &out, std::priority_queue<T, S, C> pq) {
  std::vector<T> v;
  while (!pq.empty()) {
    v.push_back(pq.top());
    pq.pop();
  }
  return out << v;
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
#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

template <typename T = int> T read() {
  T v;
  std::cin >> v;
  return v;
}

template <typename T = int> std::vector<T> read_vector(size_t n) {
  std::vector<T> v(n);
  for (size_t i = 0; i < n; ++i) {
    v[i] = read<T>();
  }
  return v;
}

#define ALL(v) (v).begin(), (v).end()

template <typename T = int>
std::vector<std::vector<T>> vector_2d(int n, int m) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m));
}

template <typename T = int>
std::vector<std::vector<T>> vector_2d(int n, int m, T d) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m, d));
}

using Long = long long;
using u64 = uint64_t;

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 3 "/tmp/tmp-3793DJpDQL1dNhUA.cpp"

#line 5 "/tmp/tmp-3793DJpDQL1dNhUA.cpp"

struct Solver {
  Solver(int n_, int m_)
      : n{n_}, m{m_}, head(n, -1), to(m << 1), next(m << 1), color(n, -1),
        used(m), tree_sum(n) {
    for (int i = 0; i < m << 1; ++i) {
      to[i] = read() - 1;
    }
    for (int i = 0; i < m << 1; ++i) {
      int u = to[i ^ 1];
      next[i] = head[u];
      head[u] = i;
    }
    bool pick0 = true;
    int pick1 = -1;
    for (int u = 0; u < n; ++u) {
      if (!~color[u]) {
        std::vector<int> tree_edges, mono_edges;
        dfs(tree_edges, mono_edges, u, 0);
        // std::cerr << KV(cut_edge) << KV(mono_edges) << KV(color) <<
        // std::endl;
        int new_pick0 = false;
        int new_pick1 = -1;
        if (mono_edges.empty()) {
          new_pick0 |= pick0;
          if (~pick1) {
            new_pick1 = pick1;
          }
        }
        int cut_edge = -1;
        if (mono_edges.size() == 1) {
          cut_edge = mono_edges[0] >> 1;
        }
        for (auto &&te : tree_edges) {
          int u = to[te ^ 1];
          int v = to[te];
          if (tree_sum[v][0] == 0 && tree_sum[v][1] == mono_edges.size()) {
            cut_edge = te >> 1;
          }
        }
        if (~cut_edge && pick0) {
          new_pick1 = cut_edge;
        }
        pick0 = new_pick0;
        pick1 = new_pick1;
      }
    }
    if (pick0) {
      result = 0;
    } else if (~pick1) {
      result = pick1;
    }
  }

  void dfs(std::vector<int> &tree_edges, std::vector<int> &mono_edges, int u,
           int c) {
    color[u] = c;
    for (int iterator = head[u]; ~iterator; iterator = next[iterator]) {
      if (!used[iterator >> 1]) {
        used[iterator >> 1] = true;
        int v = to[iterator];
        if (~color[v]) {
          // back
          bool mono = color[u] == color[v];
          if (mono) {
            mono_edges.push_back(iterator);
          }
          tree_sum[u][mono]++;
          tree_sum[v][mono]--;
        } else {
          tree_edges.push_back(iterator);
          dfs(tree_edges, mono_edges, v, c ^ 1);
          tree_sum[u][0] += tree_sum[v][0];
          tree_sum[u][1] += tree_sum[v][1];
        }
      }
    }
  }

  void dfs2(int cut, int u, int c) {
    color[u] = c;
    for (int iterator = head[u]; ~iterator; iterator = next[iterator]) {
      int v = to[iterator];
      if ((iterator >> 1) != cut && !~color[v]) {
        dfs2(cut, v, c ^ 1);
      }
    }
  }

  void output() {
    std::ranges::fill(color, -1);
    dfs2(result, to[result << 1], 1);
    for (int u = 0; u < n; ++u) {
      if (!~color[u]) {
        dfs2(result, u, 1);
      }
    }
    for (int u = 0; u < n; ++u) {
      std::cout << "01"[color[u]];
    }
    std::cout << "\n";
  }

  int n, m, result = -1;
  std::vector<int> head, to, next, color;
  std::vector<bool> used;
  std::vector<std::array<int, 2>> tree_sum;
};

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int n = read();
    int m = read();
    Solver solver{n, m};
    if (~solver.result) {
      std::cout << "YES\n";
      solver.output();
    } else {
      std::cout << "NO\n";
    }
  }
}