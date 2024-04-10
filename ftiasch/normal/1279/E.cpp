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

const Long INF = static_cast<Long>(1e18) + 1;

Long add(Long a, Long b) { return std::min(a + b, INF); }

Long mul(Long a, Long b) {
  // a <= INF / b
  return a <= INF / b ? a * b : INF;
}

const int N = 50;

int plan[N], parent[N];
bool used[N];
Long fact[N + 1], ways[N + 1];

int find(int u) {
  if (parent[u] != u) {
    parent[u] = find(parent[u]);
  }
  return parent[u];
}

int main() {
  fact[0] = 1;
  for (int i = 1; i <= N; ++i) {
    fact[i] = mul(fact[i - 1], i);
  }
  ways[0] = 1;
  for (int i = 1; i <= N; ++i) {
    ways[i] = ways[i - 1];
    for (int j = 2; j <= i; ++j) {
      ways[i] = add(ways[i], mul(ways[i - j], fact[j - 2]));
    }
  }
  std::ios::sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    int n;
    Long rank;
    std::cin >> n >> rank;
    Long rank0 = rank;
    if (rank <= ways[n]) {
      memset(plan, -1, sizeof(int) * n);
      memset(used, 0, sizeof(bool) * n);
      int i = 0;
      while (i < n) {
        if (rank <= ways[n - i - 1]) {
          used[plan[i] = i] = true;
          i++;
        } else {
          rank -= ways[n - i - 1];
          int s = i + 1;
          while (true) {
            assert(s < n);
            Long t = mul(fact[s - i - 1], ways[n - s - 1]);
            if (rank <= t) {
              break;
            }
            rank -= t;
            s++;
          }
          used[plan[i] = s] = true;
          std::iota(parent + i, parent + (s + 1), i);
          parent[i] = s;
          for (int j = i + 1; j < s; ++j) {
            int x = i;
            // V = s - i + 1
            // E = j - i + 1
            // C = s - j
            Long t = mul(fact[s - j - 1], ways[n - s - 1]);
            while (true) {
              assert(x < s);
              if (used[x] || find(j) == find(x)) {
                x++;
              } else if (rank > t) {
                rank -= t;
                x++;
              } else {
                break;
              }
            }
            used[plan[j] = x] = true;
            parent[find(j)] = find(x);
          }
          int x = i;
          while (used[x]) {
            x++;
          }
          used[plan[s] = x] = true;
          i = s + 1;
        }
      }
      // std::cerr << KV(n) << KV(rank0) << std::endl;
      for (int i = 0; i < n; ++i) {
        std::cout << (plan[i] + 1) << " \n"[i + 1 == n];
      }
    } else {
      std::cout << -1 << "\n";
    }
  }
}