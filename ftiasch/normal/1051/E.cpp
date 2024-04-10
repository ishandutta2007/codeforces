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
#line 1 "/home/ftiasch/Documents/shoka/prefix_table.h"
#include <algorithm>

std::vector<int> prefix_table(int n, const char *s) {
  std::vector<int> z(n);
  z[0] = 0;
  for (int i = 1, j = 0; i < n; ++i) {
    z[i] = i < j + z[j] ? std::min(z[i - j], j + z[j] - i) : 0;
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] > j + z[j]) {
      j = i;
    }
  }
  z[0] = n;
  return z;
}
#line 3 "sol.cpp"

#include <bits/stdc++.h>

const int N = 1'000'001;
const int MOD = 998'244'353;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

int n, lower_len, upper_len, dp[N + 1], nz_sum[N + 1];
bool lower_ok[N], upper_ok[N];
char s[N + 1], lower[N + 1], upper[N + 1], buffer[N + 1 + N];

template <bool is_upper_bound>
void precalc(bool *out, const char *bound, int m) {
  memcpy(buffer, bound, sizeof(char) * m);
  buffer[m] = '$';
  memcpy(buffer + m + 1, s, sizeof(char) * n);
  auto z = prefix_table(m + 1 + n, buffer);
  for (int i = 0; i + m <= n; ++i) {
    int lcp = z[m + 1 + i];
    if (lcp >= m) {
      out[i] = true;
    } else {
      out[i] = is_upper_bound ^ (bound[lcp] < s[i + lcp]);
    }
  }
}

int main() {
  scanf("%s%s%s", s, lower, upper);
  n = strlen(s);
  lower_len = strlen(lower);
  upper_len = strlen(upper);
  bool can_be_zero = lower_len == 1 && lower[0] == '0';
  // std::cout << KV(can_be_zero) << std::endl;
  precalc<false>(lower_ok, lower, lower_len);
  precalc<true>(upper_ok, upper, upper_len);
  dp[0] = 1;
  nz_sum[0] = 0;
  for (int i = 1; i <= n; ++i) {
    nz_sum[i] = nz_sum[i - 1];
    if (s[i - 1] != '0') {
      add(nz_sum[i], dp[i - 1]);
    }
    if (s[i - 1] == '0' && can_be_zero) {
      add(dp[i], dp[i - 1]);
    }
    if (i >= lower_len) {
      int end = i - lower_len;
      if (!lower_ok[end]) {
        end--;
      }
      int begin = i < upper_len ? 0 : i - upper_len + !upper_ok[i - upper_len];
      if (begin <= end) {
        add(dp[i], nz_sum[end + 1]);
        add(dp[i], MOD - nz_sum[begin]);
      }
    }
  }
  printf("%d\n", dp[n]);
}