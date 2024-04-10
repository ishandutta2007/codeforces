#line 1 "/home/ftiasch/Documents/shoka/debug.h"
#include <iostream>
#include <list>
#include <map>
#include <queue>
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
std::ostream &operator<<(std::ostream &out, const std::deque<T> &v) {
  return out << std::vector<T>(v.begin(), v.end());
}

template <typename T, typename S, typename C>
std::ostream &operator<<(std::ostream &out, std::priority_queue<T, S, C> pq) {
  std::vector<T> v;
  while (!pq.empty()) {
    v.push_back(pq.top());
    pq.pop();
  }
  return out << v;
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
#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

template <typename T = int> T read() {
  T v;
  std::cin >> v;
  return v;
}

template <typename T = int> std::vector<T> read_vector(size_t n) {
  std::vector<T> v(n);
  for (size_t i = 0; i < n; ++i) {
    v[i] = read<T>();
  }
  return v;
}

#define ALL(v) (v).begin(), (v).end()

template <typename T = int>
std::vector<std::vector<T>> vector_2d(int n, int m) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m));
}

template <typename T = int>
std::vector<std::vector<T>> vector_2d(int n, int m, T d) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m, d));
}

using Long = long long;
using u64 = uint64_t;

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 3 "/tmp/tmp-37933JNBlkgye8Sp.cpp"

#line 5 "/tmp/tmp-37933JNBlkgye8Sp.cpp"

using Range = std::pair<Long, Long>;

Range add(int limit, const Range &range, int a) {
  auto [l, r] = range;
  return a == 0 ? Range{l - limit, r + limit} : Range{l + a, r + a};
}

Long solve(int n, int limit, const std::vector<int> &a) {
  std::vector<Range> pre(n + 1), suf(n + 1);
  pre[0] = suf[n] = {0, 0};
  for (int i = 0; i < n; ++i) {
    pre[i + 1] = add(limit, pre[i], a[i]);
  }
  for (int i = n; i--;) {
    suf[i] = add(limit, suf[i + 1], -a[i]);
  }
  if (0 < suf[0].first || suf[0].second < 0) {
    return -1;
  }
  Long result = 1;
  for (int i = 0; i < n; ++i) {
    Long l = 0, r = 0;
    for (int j = i; j < n; ++j) {
      std::tie(l, r) = add(limit, Range{l, r}, a[j]);
      Long ll = std::max(suf[j + 1].first - pre[i].second, l);
      Long rr = std::min(suf[j + 1].second - pre[i].first, r);
      if (ll <= rr) {
        result = std::max(result, std::abs(rr) + 1);
        result = std::max(result, std::abs(ll) + 1);
      }
    }
  }
  return result;
}

int main() {
  std::ios::sync_with_stdio(false);
  int n = read();
  int limit = read();
  auto a = read_vector(n);
  std::cout << solve(n, limit, a) << "\n";
}