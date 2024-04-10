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

const int N = 100'000;
const int M = 6;

int n, letcnt[M], valid[N], letsum[1 << M], possum[1 << M];
char s[N + 1];

int main() {
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < n; ++i) {
    letcnt[s[i] - 'a']++;
  }
  std::fill(valid, valid + n, (1 << M) - 1);
  {
    int k;
    scanf("%d", &k);
    while (k--) {
      int pos;
      scanf("%d%s", &pos, s);
      int mask = 0;
      for (int i = 0; s[i]; ++i) {
        mask |= 1 << (s[i] - 'a');
      }
      valid[pos - 1] = mask;
    }
  }
  for (int mask = 0; mask < 1 << M; ++mask) {
    for (int i = 0; i < M; ++i) {
      if (mask >> i & 1) {
        letsum[mask] += letcnt[i];
      }
    }
    for (int i = 0; i < n; ++i) {
      if ((valid[i] & mask) == valid[i]) {
        possum[mask]++;
      }
    }
    if (letsum[mask] < possum[mask]) {
      puts("Impossible");
      return 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int mask = valid[i]; mask < 1 << M; mask = (mask + 1) | valid[i]) {
      possum[mask]--;
    }
    int c = 0;
    while (true) {
      bool ok = valid[i] >> c & 1;
      for (int mask = 1 << c; (mask < 1 << M) && ok;
           mask = (mask + 1) | (1 << c)) {
        ok &= letsum[mask] - 1 >= possum[mask];
      }
      if (ok) {
        for (int mask = 1 << c; mask < 1 << M; mask = (mask + 1) | (1 << c)) {
          letsum[mask]--;
        }
        s[i] = 'a' + c;
        break;
      }
      c++;
    }
  }
  s[n] = '\0';
  puts(s);
}