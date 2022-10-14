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
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, target, a1, b1, a2, b2;
    scanf("%d%d%d%d%d%d", &n, &target, &a1, &b1, &a2, &b2);
    if (a1 > a2) {
      std::swap(a1, a2);
      std::swap(b1, b2);
    }
    int startup = std::max(a2 - b1, 0);                     // 1e9
    int phase1 = std::min(b1, a2) - a1 + std::abs(b1 - b2); // 2e9
    long long current = 1LL * std::max(std::min(b1, b2) - a2, 0) * n;
    if (current >= target) {
      puts("0");
    } else {
      long long result = 1e18;
      for (int s = 1; s <= n; ++s) {
        long long startup_cost = 1LL * startup * s;
        if (current + 1LL * phase1 * s >= target) {
          result = std::min(result, startup_cost + (target - current));
        } else {
          long long p1 = 1LL * phase1 * s;
          result = std::min(result, startup_cost + p1 + (target - (current + p1)) * 2);
        }
      }
      printf("%d\n", static_cast<int>(result));
    }
  }
}