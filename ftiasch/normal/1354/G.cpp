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

struct Mock {
  Mock(const std::vector<int> &w_) : w(w_) {}

  int get_n() const { return w.size(); }

  int query(int l1, int r1, int l2, int r2) const {
    int s1 = 0, s2 = 0;
    for (int i = l1; i < r1; ++i) {
      s1 += w[i];
    }
    for (int i = l2; i < r2; ++i) {
      s2 += w[i];
    }
    return s1 == s2 ? 0 : s1 > s2 ? 1 : -1;
  }

  void report(int i) const {
    int m = *std::max_element(w.begin(), w.end());
    int j = 0;
    while (w[j] == m) {
      j++;
    }
    assert(i == j);
  }

  std::vector<int> w;
};

struct IO {
  IO() { scanf("%d%*d", &n); }

  int get_n() const { return n; }

  int query(int l1, int r1, int l2, int r2) const {
    printf("? %d %d\n", r1 - l1, r2 - l2);
    for (int i = l1; i < r1; ++i) {
      printf("%d%c", i + 1, " \n"[i + 1 == r1]);
    }
    for (int i = l2; i < r2; ++i) {
      printf("%d%c", i + 1, " \n"[i + 1 == r2]);
    }
    fflush(stdout);
    char buffer[7];
    scanf("%s", buffer);
    if (strcmp(buffer, "EQUAL") == 0) {
      return 0;
    }
    if (strcmp(buffer, "FIRST") == 0) {
      return 1;
    }
    if (strcmp(buffer, "SECOND") == 0) {
      return -1;
    }
    assert(false);
  }

  void report(int i) const {
    printf("! %d\n", i + 1);
    fflush(stdout);
  }

  int n;
};

std::mt19937 gen{0};

template <typename IO> void work(IO &&io) {
  int n = io.get_n();
  for (int _ = 0; _ < 30; ++_) {
    int i = std::uniform_int_distribution<>(1, n - 1)(gen);
    if (io.query(0, 1, i, i + 1) < 0) {
      io.report(0);
      return;
    }
  }
  // 0 is a stone
  int len = 1;
  while ((len << 1) <= n && io.query(0, len, len, len << 1) == 0) {
    len <<= 1;
  }
  //   std::cout << KV(len) << std::endl;
  int low = 0;
  int high = std::min(n - len, len);
  while (low < high) {
    int middle = (low + high + 1) >> 1;
    if (io.query(0, middle, len, len + middle) == 0) {
      low = middle;
    } else {
      high = middle - 1;
    }
  }
  io.report(len + low);
}

int main() {
  //   std::mt19937 gen{0};
  //   for (int T = 0; T < 1000; ++T) {
  //     int n = std::uniform_int_distribution<>(2, 1000)(gen);
  //     int m = std::uniform_int_distribution<>(2, 1000000)(gen);
  //     std::vector<int> w(n, m);
  //     int k = std::uniform_int_distribution<>(1, n / 2)(gen);
  //     while (k--) {
  //       int i = std::uniform_int_distribution<>(0, n - 1)(gen);
  //       w[i] = std::uniform_int_distribution<>(1, m - 1)(gen);
  //     }
  //     // std::cout << "T=" << T << " " << w << std::endl;
  //     work(Mock{w});
  //   }
  int T;
  scanf("%d", &T);
  while (T --) {
      IO io{};
      work(io);
  }
}