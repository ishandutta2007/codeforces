#line 1 "/home/ftiasch/Documents/shoka/sa.h"
#include <algorithm>
#include <cstring>

namespace details {

struct DefaultCharRank {
  int operator[](int i) const { return s[i] - 'a'; }
  const char *s;
};

} // namespace details

template <int _N, int C, typename CharRank = details::DefaultCharRank>
struct SA {
  static const int N = _N;

  void compute(int _n, const char *s) {
    n = _n;
    sort(C, IdOrder{}, CharRank{s}, sa);
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
  int count[std::max(N, C)], tsa[N], trk[N];
};

template <typename SA, template <typename, int> class RMQT>
struct LCPTable : SA {
  void compute(int _n, const char *s) {
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
#line 3 "sol.cpp"

#include <bits/stdc++.h>

const int N = 200'000;

int n, indices[N + N], parent[N];
std::array<int, 2> size[N];
std::pair<int, int> order[N];
char s[N + 1];
LCPTable<SA<N, 26>, SparseTable> sa;

int find(int u) {
  if (parent[u] != u) {
    parent[u] = find(parent[u]);
  }
  return parent[u];
}

int main() {
  int q;
  scanf("%d%d%s", &n, &q, s);
  sa.compute(n, s);
  while (q--) {
    int m = 0;
    {
      int k[2];
      scanf("%d%d", k, k + 1);
      for (int t = 0; t < 2; ++t) {
        for (int i = 0, x; i < k[t]; ++i) {
          scanf("%d", &x);
          indices[m++] = (x - 1) << 1 | t;
        }
      }
    }
    std::sort(indices, indices + m,
              [&](int x, int y) { return sa.rk[x >> 1] < sa.rk[y >> 1]; });
    long long result = 0;
    {
      int mm = 0;
      for (int i = 0; i < m;) {
        std::array<int, 2> cnt{};
        int j = i;
        while (j < m && (indices[i] >> 1) == (indices[j] >> 1)) {
          cnt[indices[j] & 1]++;
          j++;
        }
        result += 1LL * cnt[0] * cnt[1] * (n - (indices[i] >> 1));
        parent[mm] = mm;
        size[mm] = cnt;
        indices[mm++] = indices[i] >> 1;
        i = j;
      }
      m = mm;
    }
    for (int i = 0; i + 1 < m; ++i) {
      order[i] = {sa.lcp(indices[i], indices[i + 1]), i};
    }
    std::sort(order, order + (m - 1), std::greater<std::pair<int, int>>());
    for (int _ = 0; _ < m - 1; ++_) {
      auto [lcp, i] = order[_];
      int x = find(i);
      int y = find(i + 1);
      result +=
          lcp * (1LL * size[x][0] * size[y][1] + 1LL * size[x][1] * size[y][0]);
      size[x][0] += size[y][0];
      size[x][1] += size[y][1];
      parent[y] = x;
    }
    printf("%lld\n", result);
  }
}