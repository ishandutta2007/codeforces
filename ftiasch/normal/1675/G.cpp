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
#line 3 "/tmp/tmp-330131Fes2L195DmTD.cpp"

#line 5 "/tmp/tmp-330131Fes2L195DmTD.cpp"

void update(int &x, int a) { x = ~x ? std::min(x, a) : a; }

int main() {
  std::ios::sync_with_stdio(false);
  int n = read();
  int m = read();
  auto a = read_vector(n);
  std::vector<int> prefix_sum(n);
  std::inclusive_scan(a.begin(), a.end(), prefix_sum.begin());
  std::cerr << KV(a) << KV(prefix_sum) << std::endl;
  auto dp = vector_2d(m + 1, m + 1, -1);
  for (int x = 0; x <= m; ++x) {
    dp[x][x] = std::abs(x - prefix_sum[0]);
  }
  for (int i = 1; i < n; ++i) {
    int bound0 = m / i;
    int bound1 = m / (i + 1);
    auto new_dp = vector_2d(m + 1, bound1 + 1, -1);
    // new_dp[s][x] = (min_{x <= y} dp[s - x][y]) + abs
    std::cerr << KV(bound0) << KV(bound1) << std::endl;
    std::vector<int> suffix_min(m + 1, -1);
    for (int x = bound0; x >= 0; --x) {
      for (int s = x * i; s <= m; ++s) {
        if (~dp[s][x]) {
          update(suffix_min[s], dp[s][x]);
        }
      }
      if (x <= bound1) {
        for (int s = x * (i + 1); s <= m; ++s) {
          new_dp[s][x] = suffix_min[s - x] + std::abs(prefix_sum[i] - s);
        }
      }
    }
    dp.swap(new_dp);
  }
  int result = -1;
  for (int x = 0; x * n <= m; ++x) {
    if (~dp[m][x]) {
      update(result, dp[m][x]);
    }
  }
  std::cout << result << "\n";
}