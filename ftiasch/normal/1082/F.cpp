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

const int N = 501;
const int M = 10;

int n, m, trie[N][10], depth[N], weight[N], dp[N][N + 1][M + 1];
char s[N];

void dfs(int u) {
  for (int t = 0; t < 10; ++t) {
    int v = trie[u][t];
    if (~v) {
      dfs(v);
      for (int sp = 0; sp <= depth[u]; ++sp) {
        for (int k = m; k >= 0; --k) {
          int new_dp = INT_MAX;
          for (int kk = 0; kk <= k; ++kk) {
            new_dp = std::min(new_dp, dp[u][sp][k - kk] + dp[v][sp][kk]);
          }
          dp[u][sp][k] = new_dp;
        }
      }
    }
  }
  for (int sp = 0; sp < depth[u]; ++sp) {
    for (int k = m; k >= 0; --k) {
      int new_dp = INT_MAX;
      if (u == 0) {
        new_dp = std::min(new_dp, dp[u][1][k]);
      }
      if (k > 0) {
        new_dp = std::min(new_dp, dp[u][depth[u]][k - 1]);
      }
      new_dp = std::min(new_dp, dp[u][sp][k] + (weight[u] * (depth[u] - sp)));
      dp[u][sp][k] = new_dp;
    }
  }
}

int main() {
  int nn;
  scanf("%d%d", &nn, &m);
  n = 1;
  depth[0] = 1;
  memset(trie, -1, sizeof(trie));
  while (nn--) {
    int w;
    scanf("%s%d", s, &w);
    int p = 0;
    for (int i = 0; s[i]; ++i) {
      int c = s[i] - '0';
      if (!~trie[p][c]) {
        depth[n] = depth[p] + 1;
        trie[p][c] = n++;
      }
      p = trie[p][c];
    }
    weight[p] += w;
  }
//   for (int i = 0; i < n; ++i) {
//     std::cout << KV(i) << KV(depth[i]) << KV(weight[i]) << std::endl;
//   }
  //   std::cout << KV(n) << std::endl;
  dfs(0);
  printf("%d\n", dp[0][0][m]);
}