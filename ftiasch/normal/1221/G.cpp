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

using Long = long long;

const int N = 40;
const int HALF = N >> 1;

int n, m, color[N], sum[1 << HALF];
Long graph[N];

bool dfs(int u, int c) {
  color[u] = c;
  bool ok = true;
  for (int v = 0; v < n; ++v) {
    if (graph[u] >> v & 1) {
      if (color[v] == c) {
        ok = false;
      } else {
        if (color[v] == -1) {
          if (!dfs(v, c ^ 1)) {
            ok = false;
          }
        }
      }
    }
  }
  return ok;
}

void gen(int half, int u, int ones) {
  if (u < half) {
    gen(half, u + 1, ones);
    if (!(ones & graph[u])) {
      gen(half, u + 1, ones | 1 << u);
    }
  } else {
    sum[ones]++;
  }
}

Long count(int half, int u, Long hones, int lzeros) {
  if (u < n) {
    Long result = count(half, u + 1, hones, lzeros);
    if (!(hones & graph[u])) {
      result += count(half, u + 1, hones | 1LL << u,
                      lzeros | (graph[u] & ((1 << half) - 1)));
    }
    return result;
  } else {
    return sum[((1 << half) - 1) ^ lzeros];
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0, a, b; i < m; ++i) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    graph[a] |= 1LL << b;
    graph[b] |= 1LL << a;
  }
  Long result = 1LL << n;
  // 2^n - (no 0 | no 1 | no 2)
  // 2^n - no 0 - no 1 - no 2 + no 01 + no 12 + no 02 - no 012
  {
    Long no_12 = 1;
    for (int u = 0; u < n; ++u) {
      if (!graph[u]) {
        no_12 <<= 1;
      }
    }
    result += no_12;
    Long no_01 = no_12;
    result += no_01;
  }
  {
    Long no_02 = 1;
    Long no_1 = 1;
    memset(color, -1, sizeof(int) * n);
    for (int u = 0; u < n; ++u) {
      if (color[u] == -1) {
        no_02 <<= 1;
        no_1 <<= 1;
        if (!dfs(u, 0)) {
          no_02 = 0;
        }
      }
    }
    result += no_02;
    result -= no_1;
  }
  // only_02
  {
    int half = n >> 1;
    gen(half, 0, 0);
    for (int i = 0; i < half; ++i) {
      for (int mask = 0; mask < 1 << half; ++mask) {
        if (mask >> i & 1) {
          sum[mask] += sum[mask ^ (1 << i)];
        }
      }
    }
    Long no_2 = count(half, half, 0, 0);
    // for (int mask = 0; mask < 1 << n; ++mask) {
    //   bool ok = true;
    //   for (int u = 0; u < n; ++u) {
    //     if (mask >> u & 1) {
    //       ok &= (mask & graph[u]) == 0;
    //     }
    //   }
    //   no_2 += ok;
    // }
    result -= no_2;
    Long no_0 = no_2;
    result -= no_0;
  }
  if (m == 0) {
    // no 012
    result -= 1LL << n;
  }
  printf("%lld\n", result);
}