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

const int N = 1'000'000;

using Dp = std::pair<long long, int>;

int n, lim, len;
char s[N + 1];
Dp dp[N + 1];

Dp solve(int type, int lambda) {
  dp[n] = {0, 0};
  for (int i = n; i--;) {
    bool a = type ? std::isupper(s[i]) : std::islower(s[i]);
    dp[i] = {dp[i + 1].first + a, dp[i + 1].second};
    if (i + len <= n) {
      dp[i] =
          std::min(dp[i], {dp[i + len].first + lambda, dp[i + len].second + 1});
    } else {
      dp[i] = std::min(dp[i], {lambda, 1});
    }
  }
  return dp[0];
}

int work() {
  if (1LL * lim * len >= n) {
    return 0;
  }
  int result = n;
  for (int type = 0; type < 2; ++type) {
    // std::cout << KV(type) << std::endl;
    // for (int lambda = 0; lambda <= n; ++lambda) {
    //   solve(type, lambda);
    //   std::cout << KV(lambda) << std::vector<Dp>(dp, dp + (n + 1)) << std::endl;
    // }
    int low = 0;
    int high = n;
    while (low < high) {
      int middle = (low + high) >> 1;
      Dp dp0 = solve(type, middle);
      if (dp0.second <= lim) {
        high = middle;
      } else {
        low = middle + 1;
      }
    }
    // max k where dp0.second > lim
    // std::cout << KV(high) << std::endl;
    Dp dp0 = solve(type, high);
    result = std::min(result, static_cast<int>(dp0.first - 1LL * high * lim));
  }
  return result;
}

int main() {
  scanf("%d%d%d%s", &n, &lim, &len, s);
  printf("%d\n", work());
}