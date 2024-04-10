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

const int N = 1'000'000;

int n, rext[N], ord[N], nxt[N + 1];
char s[N + 1];

int find(int u) {
  if (nxt[u] != u) {
    nxt[u] = find(nxt[u]);
  }
  return nxt[u];
}

int main() {
  scanf("%d%s", &n, s);
  {
    int cnt[]{0, 0};
    for (int i = n, j = n; i--;) {
      if (s[i] != '?') {
        cnt[s[i] - '0']++;
      }
      while (cnt[0] && cnt[1]) {
        j--;
        if (s[j] != '?') {
          cnt[s[j] - '0']--;
        }
      }
      rext[i] = j - i;
    }
  }
  {
    std::vector<int> cnt(n + 1);
    for (int i = 0; i < n; ++i) {
      cnt[rext[i]]++;
    }
    for (int i = 1; i <= n; ++i) {
      cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < n; ++i) {
      ord[--cnt[rext[i]]] = i;
    }
  }
  std::iota(nxt, nxt + (n + 1), 0);
  for (int x = 1, j = 0; x <= n; ++x) {
    int result = 0;
    int i = find(0);
    while (i < n) {
      result++;
      i = find(i + x);
    }
    while (j < n && rext[ord[j]] == x) {
        nxt[ord[j]] = ord[j] + 1;
        j ++;
    }
    printf("%d%c", result, " \n"[x == n]);
  }
}