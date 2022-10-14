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

using Segment = std::tuple<char, int, int, int>;

char type(const Segment &s) { return std::get<0>(s); }

int key(const Segment &s) {
  if (type(s) == 'V') {
    return std::get<1>(s); // x
  }
  return std::get<2>(s); // x1
}

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> yvalues;
  std::vector<Segment> segments;
  for (int i = 0, x1, y1, x2, y2; i < n; ++i) {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if (x1 == x2) {
      // vertical
      if (y1 > y2) {
        std::swap(y1, y2);
      }
      segments.emplace_back('V', x1, y1, y2);
    } else {
      if (x1 > x2) {
        std::swap(x1, x2);
      }
      yvalues.push_back(y1);
      segments.emplace_back('H', y1, x1, x2);
    }
  }
  std::sort(yvalues.begin(), yvalues.end());
  yvalues.erase(std::unique(yvalues.begin(), yvalues.end()), yvalues.end());
  //   std::cout << KV(yvalues) << std::endl;
  for (auto &s : segments) {
    if (type(s) == 'V') {
      auto [_, x, y1, y2] = s;
      y1 = std::lower_bound(yvalues.begin(), yvalues.end(), y1) -
           yvalues.begin();
      y2 = std::upper_bound(yvalues.begin(), yvalues.end(), y2) -
           yvalues.begin();
      s = {_, x, y1, y2};
    } else {
      auto [_, y, x1, x2] = s;
      y = std::lower_bound(yvalues.begin(), yvalues.end(), y) - yvalues.begin();
      s = {_, y, x1, x2};
    }
  }
  std::sort(segments.begin(), segments.end(),
            [&](const Segment &u, const Segment &v) {
              // HV
              return key(u) != key(v) ? key(u) < key(v) : type(u) < type(v);
            });
  //   std::cout << KV(segments) << std::endl;
  int m = yvalues.size();
  std::vector<int> fenwick(m);
  long long result = 0;
  for (auto &&v : segments) {
    if (type(v) == 'V') {
      auto [_, vx, vy1, vy2] = v;
      std::fill(fenwick.begin(), fenwick.end(), 0);
      for (auto &&s : segments) {
        if (s == v) {
          break;
        }
        if (type(s) == 'V') {
          int count = 0;
          auto [_, x, y1, y2] = s;
          for (int k = y1; k < m; k += ~k & k + 1) {
            count += fenwick[k];
          }
          for (int k = y2; k < m; k += ~k & k + 1) {
            count -= fenwick[k];
          }
          result += 1LL * count * (count - 1) / 2;
        } else {
          auto [_, y, x1, x2] = s;
          if (vy1 <= y && y < vy2 && vx <= x2) {
            for (; ~y; y -= ~y & y + 1) {
              fenwick[y]++;
            }
          }
        }
      }
    }
  }
  printf("%lld\n", result);
}