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

int solve_ab(int k, int k0, int a, int b) {
  if (k0 <= 0) {
    return k + 1;
  }
  int y = std::max(b - (a - 1LL) * k, 1LL);
  return (y > k || std::max(a - k0, 0) > 1LL * k * (b - y)) ? k + 1 : y;
}

int solve_aba(int k, int k0, int a, int b) {
  if (k0 <= 0) {
    return k + 1;
  }
  int y = std::max(a - k0 - (b - 1LL) * k, 1LL);
  return (y > k || b > 1LL * k * (a - y)) ? k + 1 : y;
}

// int brute_ab(int k, int k0, int a, int b) {
//   if (k0 == 0) {
//     return -1;
//   }
//   for (int y = 1; y <= b && y <= k; ++y) {
//     bool ok = false;
//     for (int x = 1; x <= a && x - 1 <= b - y && !ok; ++x) {
//       ok |= a <= k0 + k * (x - 1) && b - y <= k * (x - 1);
//     }
//     if (ok) {
//       return y;
//     }
//   }
//   return -1;
// }

// int brute_aba(int k, int k0, int a, int b) {
//   if (k0 == 0) {
//     return -1;
//   }
//   for (int y = 1; y <= a && y <= k; ++y) {
//     bool ok = false;
//     for (int x = 1; x <= a - y && x <= b && !ok; ++x) {
//       ok |= a - y <= k0 + k * (x - 1) && b <= k * x;
//     }
//     if (ok) {
//       return y;
//     }
//   }
//   return -1;
// }

// void self_check() {
//   const int M = 100;
//   for (int k = 1; k <= M; ++k) {
//     for (int k0 = 0; k0 <= k; ++k0) {
//       for (int a = 1; a <= M; ++a) {
//         for (int b = 1; b <= M; ++b) {
//           {
//             int bf = brute_ab(k, k0, a, b);
//             int sv = solve_ab(k, k0, a, b);
//             if (bf != sv) {
//               std::cout << KV(k) << KV(k0) << KV(a) << KV(b) << KV(bf) <<
//               KV(sv)
//                         << std::endl;
//             }
//             assert(bf == sv);
//           }
//           {
//             int bf = brute_aba(k, k0, a, b);
//             int sv = solve_aba(k, k0, a, b);
//             if (bf != sv) {
//               std::cout << KV(k) << KV(k0) << KV(a) << KV(b) << KV(bf) <<
//               KV(sv)
//                         << std::endl;
//             }
//             assert(bf == sv);
//           }
//         }
//       }
//     }
//   }
//   std::cout << "OK|" << KV(M) << std::endl;
// }

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
  }
  int dp_a = 0, dp_b = 0;
  for (int i = 0; i < n; ++i) {
    int max_a = k - dp_a;
    if (dp_b <= k) {
      max_a = k;
    }
    int max_b = k - dp_b;
    if (dp_a <= k) {
      max_b = k;
    }
    dp_a = std::min(solve_aba(k, max_a, a[i], b[i]),
                    solve_ab(k, max_b, b[i], a[i]));
    dp_b = std::min(solve_aba(k, max_b, b[i], a[i]),
                    solve_ab(k, max_a, a[i], b[i]));
    // std::cout << KV(a[i]) << KV(b[i]) << KV(max_a) << KV(max_b) << KV(dp_a)
    //           << KV(dp_b) << std::endl;
  }
  puts(dp_a <= k || dp_b <= k ? "YES" : "NO");
}