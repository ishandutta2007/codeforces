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

const int N = 5000;

int n, m, n1, n2, n3, color[N];
std::vector<int> graph[N], comps[N << 1];
std::bitset<N + 1> dp[N + 1];

bool dfs(int u, int c) {
  color[u] = c;
  for (int v : graph[u]) {
    if (~color[v]) {
      if (color[v] == c) {
        return false;
      }
    } else {
      if (!dfs(v, c ^ 1)) {
        return false;
      }
    }
  }
  return true;
}

bool work() {
  memset(color, -1, sizeof(color));
  int count = 0;
  for (int u = 0; u < n; ++u) {
    if (!~color[u]) {
      if (!dfs(u, count)) {
        return false;
      }
      count += 2;
    }
  }
//   std::cout << std::vector<int>(color, color + n) << std::endl;
  for (int u = 0; u < n; ++u) {
    comps[color[u]].push_back(u);
  }
//   std::cout << std::vector<std::vector<int>>(comps, comps + count) << std::endl;
  dp[0].set(0);
  for (int i = 0; i < (count >> 1); ++i) {
    dp[i + 1] = dp[i] << comps[i << 1].size() | dp[i]
                                                    << comps[i << 1 | 1].size();
  }
  if (!dp[count >> 1].test(n2)) {
    return false;
  }
  for (int i = (count >> 1), j = n2; i--;) {
    for (int c = 0; c < 2; ++c) {
      auto &comp = comps[i << 1 | c];
      if (j >= comp.size() && dp[i].test(j - comp.size())) {
        for (int u : comp) {
          color[u] = 2;
        }
        for (int u : comps[i << 1 | c ^ 1]) {
          if (n1) {
            color[u] = 1;
            n1--;
          } else {
            color[u] = 3;
          }
        }
        j -= comp.size();
        break;
      }
    }
  }
  return true;
}

int main() {
  scanf("%d%d%d%d%d", &n, &m, &n1, &n2, &n3);
  for (int i = 0, a, b; i < m; ++i) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  if (work()) {
    puts("YES");
    for (int u = 0; u < n; ++u) {
      putchar('0' + color[u]);
    }
    puts("");
  } else {
    puts("NO");
  }
}