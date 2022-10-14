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

const int N = 150'000;

int main() {
  int n;
  scanf("%d", &n);
  std::map<long long, std::vector<int>> indmap;
  for (int i = 0, a; i < n; ++i) {
    scanf("%d", &a);
    indmap[a].push_back(i);
  }
  std::vector<std::pair<int, long long>> result;
  auto cur = indmap.begin();
  while (cur != indmap.end()) {
    auto [a, indices] = *cur;
    std::sort(indices.begin(), indices.end());
    // std::cout << KV(a) << indices << std::endl;
    for (size_t i = 1; i < indices.size(); i += 2) {
      indmap[a * 2].push_back(indices[i]);
    }
    if (indices.size() & 1) {
      result.emplace_back(indices.back(), a);
    }
    auto backup = cur;
    cur++;
    indmap.erase(backup);
  }
  std::sort(result.begin(), result.end());
  printf("%d\n", static_cast<int>(result.size()));
  for (size_t i = 0; i < result.size(); ++i) {
    printf("%lld%c", result[i].second, " \n"[i + 1 == result.size()]);
  }
}