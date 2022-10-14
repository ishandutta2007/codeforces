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

#line 1 "/home/ftiasch/Documents/shoka/sa.h"
#include <algorithm>
#include <cstring>

namespace details {

struct DefaultCharRank {
  using Char = char;

  static const int C = 26;

  int operator[](int i) const { return s[i] - 'a'; }

  const Char *s;
};

} // namespace details

template <int _N, typename CharRank = details::DefaultCharRank> struct SA {
  using Char = typename CharRank::Char;

  static const int N = _N;

  void compute(int _n, const Char *s) {
    n = _n;
    sort(CharRank::C, IdOrder{}, CharRank{s}, sa);
    int range = rank(CharRank{s}, CharRank{s});
    for (int length = 1; length < n && range < n; length <<= 1) {
      memcpy(trk, rk, sizeof(*rk) * n);
      TRank r1{n, length, trk}, r0{n, 0, trk};
      sort(range + 1, IdOrder{}, r1, tsa);
      sort(range + 1, TOrder{tsa}, r0, sa);
      range = rank(r0, r1);
    }
  }

  int sa[N], rk[N];

private:
  struct IdOrder {
    int operator[](int i) const { return i; }
  };

  struct TOrder {
    int operator[](int i) const { return sa[i]; }
    const int *sa;
  };

  struct TRank {
    int operator[](int i) const {
      return i + shift < n ? rk[i + shift] + 1 : 0;
    }
    int n, shift;
    const int *rk;
  };

  template <typename Order, typename Rank>
  void sort(int range, const Order &o, const Rank &r, int *out) {
    memset(count, 0, sizeof(*count) * range);
    for (int i = 0; i < n; ++i) {
      count[r[i]]++;
    }
    for (int i = 1; i < range; ++i) {
      count[i] += count[i - 1];
    }
    for (int i = n; i--;) {
      out[--count[r[o[i]]]] = o[i];
    }
  }

  template <typename Rank0, typename Rank1>
  int rank(const Rank0 &r0, const Rank1 &r1) {
    rk[sa[0]] = 0;
    for (int _ = 1; _ < n; ++_) {
      int i = sa[_];
      int j = sa[_ - 1];
      rk[i] = rk[j] + (r0[i] != r0[j] || r1[i] != r1[j]);
    }
    return rk[sa[n - 1]] + 1;
  }

  int n;
  int count[std::max(N, CharRank::C)], tsa[N], trk[N];
};

template <typename SA, template <typename, int> class RMQT>
struct LCPTable : SA {
  void compute(int _n, const typename SA::Char *s) {
    n = _n, SA::compute(n, s);
    int lcp = 0;
    for (int i = 0; i < n; ++i) {
      if (SA::rk[i]) {
        int j = SA::sa[SA::rk[i] - 1];
        while (i + lcp < n && j + lcp < n && s[i + lcp] == s[j + lcp]) {
          lcp++;
        }
        height[SA::rk[i] - 1] = lcp;
        lcp = std::max(lcp - 1, 0);
      }
    }
    rmq.initialize(n - 1, height);
  }

  int lcp(int i, int j) const {
    if (i == j) {
      return n - i;
    }
    i = SA::rk[i], j = SA::rk[j];
    return i < j ? rmq(i, j - 1) : rmq(j, i - 1);
  }

private:
  static const int N = SA::N;

  int n, height[N - 1];
  RMQT<int, N - 1> rmq;
};
#line 2 "/home/ftiasch/Documents/shoka/sparse_table.h"

#line 5 "/home/ftiasch/Documents/shoka/sparse_table.h"

template <typename T, int N> struct SparseTable {
  SparseTable() {
    log[0] = 0;
    for (int i = 1; i < N; ++i) {
      log[i] = log[i - 1] + (1 << (log[i - 1] + 1) < i + 1);
    }
  }

  void initialize(int n, const T *value) {
    l = log2n(n), memcpy(table[0], value, sizeof(T) * n);
    for (int i = 1; i < l; ++i) {
      for (int j = 0; j + (1 << i) <= n; ++j) {
        table[i][j] =
            std::min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
      }
    }
  }

  T operator()(int l, int r) const {
    const int lv = log[r - l];
    return std::min(table[lv][l], table[lv][r - (1 << lv) + 1]);
  }

private:
  static constexpr int log2n(int n) {
    return n > 1 ? 32 - __builtin_clz(n - 1) : 1;
  }

  static const int L = log2n(N);

  int l, log[N];
  T table[L][N];
};
#line 5 "sol.cpp"

#include <bits/stdc++.h>

const int N = 200'000;
const int C = 26;

int n, nxt_idx[N + 1][C], prv_dis[N];
char s[N + 1];

struct IntRank {
  using Char = int;

  static const int C = N;

  int operator[](int i) const { return s[i]; }

  const Char *s;
};

LCPTable<SA<N, IntRank>, SparseTable> sa;

bool same(int x, int y, int len) {
  return len == 1 || sa.lcp(x + 1, y + 1) >= len - 1;
}

int main() {
  int q;
  scanf("%d%d%s", &n, &q, s);
  std::fill(nxt_idx[n], nxt_idx[n] + C, n);
  {
    int nxt[C];
    std::fill(nxt, nxt + C, n);
    for (int i = n; i--;) {
      memcpy(nxt_idx[i], nxt_idx[i + 1], sizeof(nxt_idx[i]));
      int c = s[i] - 'a';
      for (int j = std::find(nxt_idx[i], nxt_idx[i] + C, nxt[c]) - nxt_idx[i];
           j >= 1; --j) {
        nxt_idx[i][j] = nxt_idx[i][j - 1];
      }
      nxt_idx[i][0] = i;
      nxt[c] = i;
    }
  }
  {
    int prv[C];
    std::fill(prv, prv + C, -1);
    for (int i = 0; i < n; ++i) {
      int c = s[i] - 'a';
      prv_dis[i] = ~prv[c] ? i - prv[c] : 0;
      prv[c] = i;
    }
  }
//   std::cout << std::vector<int>(prv_dis, prv_dis + n) << std::endl;
//   for (int i = 0; i < n; ++ i) {
//       std::cout << std::vector<int>(nxt_idx[i], nxt_idx[i] + C) <<std::endl;
//   }
  sa.compute(n, prv_dis);
  while (q--) {
    int x, y, len;
    scanf("%d%d%d", &x, &y, &len);
    x--;
    y--;
    bool ok = true;
    int last = 0;
    for (int i = 1; i < C && ok; ++i) {
      int xx = nxt_idx[x][i] - x;
      int yy = nxt_idx[y][i] - y;
      if (xx >= len && yy >= len) {
        break;
      }
      if (xx == yy) {
        ok &= same(x + last, y + last, xx - last);
        last = xx;
      } else {
        ok = false;
      }
    }
    if (ok) {
      ok &= same(x + last, y + last, len - last);
    }
    puts(ok ? "YES" : "NO");
  }
}