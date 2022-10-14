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

const int S = 4 * 4 * 4; // 64
const int MOD = 998'244'353;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

int make_state(int a, int b, int c) { return a | b << 2 | c << 4; }

int get_state(int state, int i) { return state >> (i << 1) & 3; }

using Vector = std::array<int, S>;

struct Matrix {
  Matrix() { memset(data, 0, sizeof(data)); }

  int *operator[](int i) { return data[i]; }

  const int *operator[](int i) const { return data[i]; }

  int data[S][S];
};

Matrix operator*(const Matrix &a, const Matrix &b) {
  static int buffer[S];
  Matrix c;
  for (int j = 0; j < S; ++j) {
    for (int k = 0; k < S; ++k) {
      buffer[k] = b[k][j];
    }
    for (int i = 0; i < S; ++i) {
      for (int k = 0; k < S; ++k) {
        add(c[i][j], 1LL * a[i][k] * buffer[k] % MOD);
      }
    }
  }
  return c;
}

Vector operator*(const Vector &a, const Matrix &b) {
  Vector c;
  std::fill(c.begin(), c.end(), 0);
  for (int i = 0; i < S; ++i) {
    for (int j = 0; j < S; ++j) {
      add(c[j], 1LL * a[i] * b[i][j] % MOD);
    }
  }
  return c;
}

bool ok[3][3];

Matrix a[4];

const int N = 1000;

int n, len[N];
std::vector<std::pair<int, int>> colored[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", len + i);
  }
  int max_len = *std::max_element(len, len + n);
  int m;
  scanf("%d", &m);
  while (m--) {
    int x, y, c;
    scanf("%d%d%d", &x, &y, &c);
    colored[x - 1].emplace_back(y - 1, c - 1);
  }
  for (int c = 0; c < 3; ++c) {
    for (int st = 0, x; st < 3; ++st) {
      scanf("%d", &x);
      ok[c][st] = x;
    }
  }
  for (int c = 0; c < 3; ++c) {
    for (int s = 0; s < S; ++s) {
      bool pre[4]{};
      for (int st = 0; st < 3; ++st) {
        if (ok[c][st]) {
          pre[get_state(s, 2 - st)] = true;
        }
      }
      int mex = 0;
      while (pre[mex]) {
        mex++;
      }
      int ns = s >> 2 | mex << 4;
      a[c][s][ns]++;
      a[3][s][ns]++;
    }
  }
  std::vector<Matrix> power_of_a3{a[3]};
  for (int i = 1; 1 << i <= max_len; ++i) {
    power_of_a3.push_back(power_of_a3[i - 1] * power_of_a3[i - 1]);
  }
  int dp[4]{};
  dp[0] = 1;
  for (int i = 0; i < n; ++i) {
    auto &clist = colored[i];
    clist.emplace_back(-1, -1);
    clist.emplace_back(len[i], -1);
    std::sort(clist.begin(), clist.end());
    Vector v;
    std::fill(v.begin(), v.end(), 0);
    v[make_state(3, 3, 3)] = 1;
    for (int j = 1; j < static_cast<int>(clist.size()); ++j) {
      int gap = clist[j].first - clist[j - 1].first - 1;
      for (int k = power_of_a3.size(); k--;) {
        if (gap >> k & 1) {
          v = v * power_of_a3[k];
        }
      }
      int c = clist[j].second;
      if (~c) {
        v = v * a[c];
      }
    }
    int tot[4]{};
    for (int s = 0; s < S; ++s) {
      add(tot[get_state(s, 2)], v[s]);
    }
    int new_dp[4]{};
    for (int s = 0; s < 4; ++s) {
      for (int x = 0; x < 4; ++x) {
        add(new_dp[s ^ x], 1LL * dp[s] * tot[x] % MOD);
      }
    }
    memcpy(dp, new_dp, sizeof(dp));
  }
  printf("%d\n", dp[0]);
}