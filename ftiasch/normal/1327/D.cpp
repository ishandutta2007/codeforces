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

const int N = 200'000;

int n, p[N], c[N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", p + i);
      p[i]--;
    }
    for (int i = 0; i < n; ++i) {
      scanf("%d", c + i);
    }
    std::vector<int> cyc;
    cyc.reserve(n);
    int result = n;
    for (int u = 0; u < n; ++u) {
      if (~p[u]) {
        cyc.clear();
        int v = u;
        do {
          cyc.push_back(c[v]);
          int nv = p[v];
          p[v] = -1;
          v = nv;
        } while (v != u);
        // std::cout << cyc << std::endl;
        int m = cyc.size();
        for (int d = 1; d <= m && d < result; ++d) {
          if (m % d == 0) {
            bool found = false;
            for (int r = 0; r < d && !found; ++r) {
              bool ok = true;
              for (int i = r; i < m && ok; i += d) {
                ok &= cyc[i] == cyc[r];
              }
              found |= ok;
            }
            if (found) {
              result = std::min(result, d);
            }
          }
        }
      }
    }
    printf("%d\n", result);
  }
}