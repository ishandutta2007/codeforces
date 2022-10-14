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

using Point = std::pair<int, int>;
using Sofa = std::pair<Point, Point>;

std::vector<int> count(int n, const std::vector<Sofa> &sofas,
                       const std::function<int(Point)> &key) {
  std::vector<int> values(n);
  for (int i = 0; i < n; ++i) {
    values[i] = std::min(key(sofas[i].first), key(sofas[i].second));
  }
  std::sort(values.begin(), values.end());
  std::vector<int> result(n);
  for (int i = 0; i < n; ++i) {
    int kmin = std::min(key(sofas[i].first), key(sofas[i].second));
    int kmax = std::max(key(sofas[i].first), key(sofas[i].second));
    result[i] =
        static_cast<int>(std::lower_bound(values.begin(), values.end(), kmax) - values.begin()) - (kmin < kmax);
  }
  return result;
}

int main() {
  int n;
  scanf("%d%*d%*d", &n);
  std::vector<Sofa> sofas(n);
  for (int i = 0, x1, y1, x2, y2; i < n; ++i) {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    sofas[i] = {{x1, y1}, {x2, y2}};
  }
  auto cnt_l = count(n, sofas, [](const Point &p) { return p.first; });
  auto cnt_r = count(n, sofas, [](const Point &p) { return -p.first; });
  auto cnt_t = count(n, sofas, [](const Point &p) { return p.second; });
  auto cnt_d = count(n, sofas, [](const Point &p) { return -p.second; });
  int l, r, t, d;
  scanf("%d%d%d%d", &l, &r, &t, &d);
  for (int i = 0; i < n; ++i) {
    if (cnt_l[i] == l && cnt_r[i] == r && cnt_t[i] == t && cnt_d[i] == d) {
      printf("%d\n", i + 1);
      return 0;
    }
  }
  puts("-1");
}