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

using Vec = std::vector<int>;

int main() {
  int n, mod;
  scanf("%d%d", &n, &mod);
  Vec primes, bound;
  for (int p = 2; p * p <= mod; ++p) {
    if (mod % p == 0) {
      int e = 0;
      while (mod % p == 0) {
        mod /= p;
        e++;
      }
      primes.push_back(p);
      bound.push_back(e);
    }
  }
  if (mod > 1) {
    primes.push_back(mod);
    bound.push_back(1);
  }

  int m = primes.size();

  auto factor = [&](int a) -> Vec {
    Vec e(m);
    for (int k = 0; k < m; ++k) {
      while (a % primes[k] == 0) {
        a /= primes[k];
        e[k]++;
      }
    }
    return e;
  };

  auto ok = [&](const Vec &v) -> bool {
    for (int k = 0; k < m; ++k) {
      if (v[k] < bound[k]) {
        return false;
      }
    }
    return true;
  };

  auto sub = [&](const Vec &a, const Vec &b) -> Vec {
    Vec result(m);
    for (int k = 0; k < m; ++k) {
      result[k] = a[k] - b[k];
    }
    return result;
  };

  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  std::vector<int> count(m);
  long long result = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    auto e = factor(a[i]);
    for (int k = 0; k < m; ++k) {
      count[k] += e[k];
    }
    while (j < i) {
      auto new_count = sub(count, factor(a[j]));
      if (!ok(new_count)) {
        break;
      }
      count = new_count;
      j++;
    }
    if (ok(count)) {
      result += j + 1;
    }
  }
  printf("%lld\n", result);
}