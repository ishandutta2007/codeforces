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

const int N = 1000;
const int S = 11340 + 2;

void update(int &x, int a) { x = ~x ? std::min(x, a) : a; }

char s[N + 1];
int x, trie_sz, trie[S][10], fail[S], go[S][10], dp[2][S];

int main() {
  scanf("%s%d", s, &x);
  memset(trie, -1, sizeof(trie));
  trie_sz = 1;
  {
    std::vector<int> divisors;
    for (int d = 1; d < x; ++d) {
      if (x % d == 0) {
        divisors.push_back(d);
      }
    }
    int sum_len = 0;
    for (int mask = 1 | 1 << x; mask < (1 << (x + 1)); mask += 2) {
      bool ok = true;
      for (int d : divisors) {
        ok &= (mask & (mask >> d)) == 0;
      }
      if (ok) {
        std::vector<int> p;
        for (int i = 1, last = 0; i <= x && ok; ++i) {
          if (mask >> i & 1) {
            int d = i - last;
            if (d > 9) {
              ok = false;
            } else {
              p.push_back(d);
              last = i;
            }
          }
        }
        if (ok) {
          int q = 1;
          for (int i = 0; i < static_cast<int>(p.size()) - 1; ++i) {
            int c = p[i];
            if (!~trie[q][c]) {
              trie[q][c] = ++trie_sz;
              assert(trie_sz < S);
            }
            q = trie[q][c];
          }
          trie[q][p.back()] = 0;
        }
      }
    }
  }
  memset(go, 0, sizeof(go));
  {
    std::queue<int> queue;
    for (int c = 1; c < 10; ++c) {
      int v = trie[1][c];
      if (~v) {
        if (v) {
          fail[v] = 1;
          go[1][c] = v;
          queue.push(v);
        }
      } else {
        go[1][c] = 1;
      }
    }
    while (!queue.empty()) {
      int u = queue.front();
      queue.pop();
      for (int c = 1; c < 10; ++c) {
        int v = trie[u][c];
        if (~v) {
          if (v) {
            fail[v] = go[fail[u]][c];
            go[u][c] = v;
            queue.push(v);
          }
        } else {
          go[u][c] = go[fail[u]][c];
        }
      }
    }
  }
  memset(dp, -1, sizeof(dp));
  dp[0][1] = 0;
  int n = strlen(s);
  for (int i = 0; i < n; ++i) {
    memset(dp[(i + 1) & 1], -1, sizeof(int) * (trie_sz + 1));
    for (int st = 0; st <= trie_sz; ++st) {
      if (~dp[i & 1][st]) {
        update(dp[(i + 1) & 1][st], dp[i & 1][st] + 1);
        update(dp[(i + 1) & 1][go[st][s[i] - '0']], dp[i & 1][st]);
      }
    }
  }
  int result = -1;
  for (int st = 1; st <= trie_sz; ++st) {
    if (~dp[n & 1][st]) {
      update(result, dp[n & 1][st]);
    }
  }
  printf("%d\n", result);
}