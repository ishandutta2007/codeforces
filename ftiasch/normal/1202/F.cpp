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

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  int n = a + b;
  int result = 0;
  // for (int p = 1; p <= n; ++p) {
  //   int k0 = n / p;
  //   int k1 = (n + p - 1) / p;
  //   int x1 = a / k0;
  //   int x0 = (a + k1 - 1) / k1;
  //   int y1 = b / k0;
  //   int y0 = (b + k1 - 1) / k1;
  //   // x * k0 <= a && a <= x * k1
  //   // y * k1 <= b && b <= y * k2
  //   // a + b == p
  //   if (x0 <= x1 && y0 <= y1 && x0 + y0 <= p && p <= x1 + y1) {
  //     std::cerr << KV(p) << std::endl;
  //     result++;
  //   }
  // }
  for (int p = 1; p <= n;) {
    int k0 = n / p;
    // [n / p] == k0
    // k <= n / p < k + 1
    // n / (k + 1) < p <= n / k
    int q = n / k0;
    if (p < q && n % k0 == 0) {
      q--;
    }
    int k1 = (n - 1LL + p) / p;
    int x1 = a / k0;
    int x0 = (a - 1LL + k1) / k1;
    int y1 = b / k0;
    int y0 = (b - 1LL + k1) / k1;
    // x * k0 <= a && a <= x * k1
    // y * k1 <= b && b <= y * k2
    // a + b == p
    if (x0 <= x1 && y0 <= y1) {
      result += std::max(std::min(q, x1 + y1) - std::max(p, x0 + y0) + 1, 0);
    }
    p = q + 1;
  }
  printf("%d\n", result);
}