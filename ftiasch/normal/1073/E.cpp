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

const int MOD = 998'244'353;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

using Long = long long;

const int L = 18;

int ones[1 << 10], limit, digits[L], power_of_ten[L], cache[L][2][1 << 10];

int recur(bool less, int len, bool taken, int mask) {
  if (len == 0) {
    return taken && ones[mask] <= limit;
  }
  len--;
  int &loc = cache[len][taken][mask];
  if (less && ~loc) {
    return loc;
  }
  int result = 0;
  bool backup = less;
  for (int d = less ? 9 : digits[len]; d >= 0; --d) {
    add(result, recur(less, len, taken, mask | 1 << d));
    if (!taken) {
      add(result, 1LL * recur(less, len, true, mask | 1 << d) * d % MOD *
                      power_of_ten[len] % MOD);
    }
    less = true;
  }
  if (backup) {
    loc = result;
  }
  return result;
}

int solve(long long n) {
  if (n == 0) {
    return 0;
  }
  int len = 0;
  while (n) {
    digits[len++] = n % 10;
    n /= 10;
  }
  int result = 0;
  for (int i = 0; i < len; ++i) {
    for (int d = i + 1 < len ? 9 : digits[i]; d >= 1; --d) {
      bool less = i + 1 < len || d < digits[i];
      add(result, recur(less, i, false, 1 << d));
      add(result,
          1LL * recur(less, i, true, 1 << d) * d % MOD * power_of_ten[i] % MOD);
    }
  }
  //   std::cout << std::vector<int>(digits, digits + len) << std::endl;
  return result;
}

int main() {
  for (int mask = 0; mask < 1 << 10; ++mask) {
    ones[mask] = __builtin_popcount(mask);
  }
  power_of_ten[0] = 1;
  for (int i = 1; i < L; ++i) {
    power_of_ten[i] = power_of_ten[i - 1] * 10LL % MOD;
  }
  Long l, r;
  scanf("%lld%lld%d", &l, &r, &limit);
  memset(cache, -1, sizeof(cache));
  int result = solve(r);
  add(result, MOD - solve(l - 1));
  printf("%d\n", result);
}