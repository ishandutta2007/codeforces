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

using Long = long long;

const int N = 100'000;
const int M = 60;
const Long INF = 1'000'000'000'000'000'001LL;

int mu[M];
std::pair<Long, int> cache[M];
Long result[N];

Long safe_sqrt(Long n) {
  Long r = std::sqrt(n) + 2;
  while (r * r > n) {
    r--;
  }
  return r;
}

Long safe_mul(Long a, Long b) { return a <= INF / b ? a * b : INF; }

Long safe_pow(Long a, int n) {
  Long result = 1;
  for (int i = 0; i < n; ++i) {
    result = safe_mul(result, a);
  }
  return result;
}

int main() {
  mu[1] = 1;
  for (int d = 1; d < M; ++d) {
    for (int i = d + d; i < M; i += d) {
      mu[i] -= mu[d];
    }
    cache[d] = {1, 0};
  }
  //   std::cout << std::vector<int>(mu, mu + M) << std::endl;
  int T;
  scanf("%d", &T);
  std::vector<std::pair<Long, int>> order(T);
  for (int i = 0; i < T; ++i) {
    scanf("%lld", &order[i].first);
    order[i].second = i;
  }
  std::sort(order.begin(), order.end());
  for (auto [n, id] : order) {
    result[id] = n - safe_sqrt(n);
    for (int d = 3; d < M; ++d) {
      if (mu[d]) {
        auto [nxt_pow, base] = cache[d];
        while (nxt_pow <= n) {
          base++;
          nxt_pow = safe_pow(base, d);
        }
        cache[d] = {nxt_pow, base};
        result[id] += mu[d] * (base - 1LL);
      }
    }
  }
  for (int i = 0; i < T; ++ i) {
      printf("%lld\n", result[i] + 1);
  }
}