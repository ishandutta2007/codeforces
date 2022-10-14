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

const int N = 5001;
const int MOD = 998'244'353;

int n, a[N], m[N], dp[N], fact[N], inv_fact[N], psum[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  std::sort(a + 1, a + 1 + n);
  for (int i = 1, j = 0; i <= n; ++i) {
    while (j < n && (a[j + 1] << 1) <= a[i]) {
      j++;
    }
    m[i] = j;
  }
  m[0] = -1;
  if (m[n] < n - 1) {
    puts("0");
  } else {
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
      fact[i] = 1LL * i * fact[i - 1] % MOD;
    }
    inv_fact[1] = 1;
    for (int i = 2; i <= n; ++i) {
      inv_fact[i] = 1LL * (MOD - MOD / i) * inv_fact[MOD % i] % MOD;
    }
    for (int i = 1; i <= n; ++i) {
      inv_fact[i] = 1LL * inv_fact[i] * inv_fact[i - 1] % MOD;
    }
    dp[0] = 1;
    // for (int i = 1; i <= n; ++i) {
    //   for (int j = 0; j <= m[i]; ++j) {
    //     int ways = 1LL * fact[n - m[j] - 2] * inv_fact[n - m[i] - 1] % MOD;
    //     add(dp[i], 1LL * ways * dp[j] % MOD);
    //   }
    // }
    psum[0] = fact[n - 1];
    for (int i = 1; i <= n; ++i) {
      dp[i] = 1LL * psum[m[i]] * inv_fact[n - m[i] - 1] % MOD;
      if (i < n) {
        psum[i] = (psum[i - 1] + 1LL * dp[i] * fact[n - m[i] - 2]) % MOD;
      }
    }
    printf("%d\n", dp[n]);
  }
}