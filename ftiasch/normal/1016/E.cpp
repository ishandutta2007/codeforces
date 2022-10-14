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

const int N = 200'000;

int sy, a, b, n, ends[N << 1], sum_len[N + 1];

double count(double x) {
  int low = 0;
  int high = n << 1;
  // [low, high)
  while (low < high) {
    int middle = (low + high) >> 1;
    if (x <= ends[middle]) {
      high = middle;
    } else {
      low = middle + 1;
    }
  }
  if (high & 1) {
    return (ends[high] - x) + sum_len[(high + 1) >> 1];
  }
  return sum_len[high >> 1];
}

int main() {
  scanf("%d%d%d%d", &sy, &a, &b, &n);
  for (int i = 0; i < n << 1; ++i) {
    scanf("%d", ends + i);
  }
  for (int i = n; i--;) {
    sum_len[i] = (ends[i << 1 | 1] - ends[i << 1]) + sum_len[i + 1];
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    double xx = 1.0 * (1LL * a * y - 1LL * x * sy) / (y - sy);
    double yy = 1.0 * (1LL * b * y - 1LL * x * sy) / (y - sy);
    double result = (count(xx) - count(yy)) / (yy - xx) * (b - a);
    printf("%.12f\n", result);
  }
}