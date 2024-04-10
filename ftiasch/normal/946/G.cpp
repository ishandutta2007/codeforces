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

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    a[i] -= i;
  }
  std::vector<int> fwd(n);
  int max_keep = 0;
  {
    std::vector<int> g(n + 1, INT_MAX);
    g[0] = INT_MIN;
    for (int i = n; i --; ) {
      int v = -(a[i] + 1);
      fwd[i] = std::upper_bound(g.begin(), g.end(), v) - g.begin();
      g[fwd[i]] = std::min(g[fwd[i]], v);
    }
    max_keep = std::min(*std::max_element(fwd.begin(), fwd.end()) + 1, n);
    std::fill(g.begin(), g.end(), INT_MAX);
    g[0] = INT_MIN;
    for (int i = 0; i < n; ++i) {
      if (i + 1 < n) {
        int len =
            std::upper_bound(g.begin(), g.end(), a[i + 1] + 1) - g.begin();
        max_keep = std::max(max_keep, len + fwd[i + 1]);
      }
      int bwd = std::upper_bound(g.begin(), g.end(), a[i]) - g.begin();
      g[bwd] = std::min(g[bwd], a[i]);
      // std::cerr << KV(i) << KV(bwd) << std::endl;
    }
  }
  printf("%d\n", n - max_keep);
}