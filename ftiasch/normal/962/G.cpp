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

struct Set : std::set<int> {
  void flip(int e) {
    auto [iterator, success] = emplace(e);
    if (!success) {
      erase(iterator);
    }
  }
};

int main() {
  int l, low, r, high, n;
  scanf("%d%d%d%d%d", &l, &high, &r, &low, &n);
  std::vector<std::pair<int, int>> polygon(n + 1);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &polygon[i].first, &polygon[i].second);
  }
  polygon[n] = polygon[0];
  std::vector<std::tuple<int, int, int>> segments;
  for (int i = 0; i < n; ++i) {
    auto [x0, y0] = polygon[i];
    auto [x1, y1] = polygon[i + 1];
    if (y0 == y1 && y0 < high) {
      segments.emplace_back(y0, x0, x1);
    }
  }
  std::sort(segments.begin(), segments.end());
  Set set;
  int result = 0;
  for (auto [y, x0_, x1_] : segments) {
    bool close = x0_ > x1_;
    int x0 = x0_;
    int x1 = x1_;
    if (close) {
      std::swap(x0, x1);
    }
    if (l < x1 && x0 < r) {
      x0 = std::max(x0, l);
      x1 = std::min(x1, r);
      int old_sz = set.size();
      set.flip(x0);
      set.flip(x1);
      int delta = set.size() - old_sz;
      if (low < y && close) {
        result -= (delta >> 1);
      }
    }
  }
  result += set.size() >> 1;
  printf("%d\n", result);
}