#line 1 "/home/ftiasch/Documents/shoka/dsu.h"
#include <vector>

class DSU {
public:
  DSU(int n) : parent(n, -1) {}

  int find(int u) {
    if (!~parent[u]) {
      return u;
    }
    if (parent[u] != u) {
      parent[u] = find(parent[u]);
    }
    return parent[u];
  }

  bool merge(int a, int b) {
    if (find(a) == find(b)) {
      return false;
    }
    parent[find(a)] = find(b);
    return true;
  }

private:
  std::vector<int> parent;
};
#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <iostream>
#line 3 "/home/ftiasch/Documents/shoka/util.h"
#include <queue>

#define ALL(v) (v).begin(), (v).end()

using Long = long long;
using u64 = uint64_t;

struct IO {
  IO() { std::cin.sync_with_stdio(false); }

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
};

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 3 "/tmp/tmp-531441943luZZc42G1.cpp"

#line 2 "/home/ftiasch/Documents/shoka/debug.h"
#include <list>
#include <map>
#line 5 "/home/ftiasch/Documents/shoka/debug.h"
#include <set>
#include <utility>
#line 8 "/home/ftiasch/Documents/shoka/debug.h"

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
#line 5 "/tmp/tmp-531441943luZZc42G1.cpp"

#include <bits/stdc++.h>

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    int m = io.read();
    std::vector<Long> sum(n + 1);
    for (int t = 0; t < 2; ++t) {
      for (int i = 0; i < n; ++i) {
        int a = io.read();
        if (t) {
          sum[i] -= a;
        } else {
          sum[i] += a;
        }
      }
    }
    for (int i = n; i--;) {
      sum[i] += sum[i + 1];
    }
    std::vector<std::vector<int>> intervals(n + 1);
    for (int i = 0; i < m; ++i) {
      int l = io.read() - 1;
      int r = io.read();
      intervals[l].push_back(r);
      intervals[r].push_back(l);
    }
    DSU dsu(n + 2);
    std::queue<std::pair<int, int>> candidates;
    auto add = [&](int i) {
      sum[i] = 0;
      dsu.merge(i, i + 1);
      for (int j : intervals[i]) {
        if (sum[j] == 0) {
          int l = i;
          int r = j;
          if (l > r) {
            std::swap(l, r);
          }
          candidates.emplace(l, r);
        }
      }
    };
    for (int i = 0; i <= n; ++i) {
      if (sum[i] == 0) {
        add(i);
      }
    }
    while (!candidates.empty()) {
      auto [l, r] = candidates.front();
      candidates.pop();
      for (int i = dsu.find(l); i <= r; i = dsu.find(i)) {
        add(i);
      }
    }
    std::cout << (dsu.find(0) == n + 1 ? "YES" : "NO") << "\n";
  }
}