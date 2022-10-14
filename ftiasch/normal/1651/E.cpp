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
#line 2 "sol.cpp"

#include <bits/stdc++.h>

int solve(int n, int l, int r, const std::vector<int> &excludes) {
  int result = 0;
  for (int mask = 0; mask < 1 << excludes.size(); ++mask) {
    int ll = l;
    int rr = r;
    for (int i = 0; i < excludes.size(); ++i) {
      if (mask >> i & 1) {
        ll = std::min(ll, excludes[i]);
        rr = std::max(rr, excludes[i]);
      }
    }
    int subtotal = 0;
    if (ll <= rr) {
      subtotal = (ll + 1) * (n - rr);
    } else {
      subtotal = (n + 1) * n / 2;
    }
    if (__builtin_parity(mask)) {
      result += subtotal;
    } else {
      result -= subtotal;
    }
  }
  return result;
}

int main() {
  int n;
  scanf("%d", &n);
  std::vector<std::vector<int>> graph(n << 1);
  for (int i = 0, a, b; i < n << 1; ++i) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  std::vector<bool> visited(n << 1);
  long long result = 0;
  std::vector<int> a_excludes, b_excludes;
  auto exclude = [&](int u) {
    if (u < n) {
      a_excludes.push_back(u);
    } else {
      b_excludes.push_back(u - n);
    }
  };
  for (int s = 0; s < n; ++s) {
    if (!visited[s]) {
      std::vector<int> cycles;
      {
        int t = graph[s][0];
        int u = s, v = t;
        do {
          visited[u] = true;
          cycles.push_back(u);
          int w = graph[v][graph[v][0] == u];
          u = v;
          v = w;
        } while (u != s);
      }
      int length = cycles.size();
      cycles.resize(length << 1);
      for (int i = 0; i < length; ++i) {
        cycles[i + length] = cycles[i];
      }
      for (int i = 1; i <= length; ++i) {
        int a_min = INT_MAX, a_max = INT_MIN, b_min = INT_MAX, b_max = INT_MIN;
        for (int count = 1; count <= length; ++count) {
          int u = cycles[i + count - 1];
          if (u < n) {
            a_min = std::min(a_min, u);
            a_max = std::max(a_max, u);
          } else {
            b_min = std::min(b_min, u - n);
            b_max = std::max(b_max, u - n);
          }
          if (count < length) {
            a_excludes.clear();
            b_excludes.clear();
            exclude(cycles[i - 1]);
            exclude(cycles[i + count]);
            result += 1LL * (count >> 1) * solve(n, a_min, a_max, a_excludes) *
                      solve(n, b_min, b_max, b_excludes);
          } else if (i == 1) {
            result += 1LL * (count >> 1) * solve(n, a_min, a_max, {}) *
                      solve(n, b_min, b_max, {});
          }
        }
      }
    }
  }
  printf("%lld\n", result);
}