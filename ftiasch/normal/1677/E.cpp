#line 1 "/tmp/tmp-696031o42JZbZBaxgm.cpp"
// #include "debug.h"
#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

template <typename T = int> T read() {
  T v;
  std::cin >> v;
  return v;
}

template <typename T = int> std::vector<T> read_vector(size_t n) {
  std::vector<T> v(n);
  for (size_t i = 0; i < n; ++i) {
    v[i] = read<T>();
  }
  return v;
}

#define ALL(v) (v).begin(), (v).end()

template <typename T = int>
std::vector<std::vector<T>> vector_2d(int n, int m) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m));
}

template <typename T = int>
std::vector<std::vector<T>> vector_2d(int n, int m, T d) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m, d));
}

using Long = long long;
using u64 = uint64_t;

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 3 "/tmp/tmp-696031o42JZbZBaxgm.cpp"

#line 5 "/tmp/tmp-696031o42JZbZBaxgm.cpp"

struct Sum {
  int c = 0;
  Long x = 0, y = 0, xy = 0;
};

struct RangeSum2D {
  RangeSum2D(int n_, int q_) : n{n_}, q{q_}, ranges(n), queries(n) {}

  void add_range(int x1, int x2, int y1, int y2) {
    // std::cerr << std::make_pair(x1, x2) << " " << std::make_pair(y1, y2)
    //   << std::endl;
    add<1>(x2, y1);
    add<-1>(x2, y2 + 1);
    add<-1>(x1 - 1, y1);
    add<1>(x1 - 1, y2 + 1);
  }

  void add_query(int i, int x, int y) { queries[x].emplace_back(y, i); }

  std::vector<Long> solve() {
    std::vector<Long> result(q);
    std::vector<Sum> sum(n);
    for (int x = n; x--;) {
      for (auto [y, delta] : ranges[x]) {
        for (int k = y; k < n; k += ~k & k + 1) {
          sum[k].c += delta;
          sum[k].x += delta * x;
          sum[k].y += delta * y;
          sum[k].xy += static_cast<Long>(delta) * x * y;
        }
      }
      for (auto [y, id] : queries[x]) {
        Sum subtotal;
        for (int k = y; ~k; k -= ~k & k + 1) {
          subtotal.c += sum[k].c;
          subtotal.x += sum[k].x;
          subtotal.y += sum[k].y;
          subtotal.xy += sum[k].xy;
        }
        result[id] = -(x - 1LL) * (y + 1LL) * subtotal.c +
                     subtotal.x * (y + 1LL) + (x - 1LL) * subtotal.y -
                     subtotal.xy;
      }
    }
    return result;
  }

  template <int delta> void add(int x, int y) {
    if (~x && y < n) {
      ranges[x].emplace_back(y, delta);
    }
  }

  int n, q;
  std::vector<std::vector<std::pair<int, int>>> ranges, queries;
};

int main() {
  std::ios::sync_with_stdio(false);
  int n = read();
  int q = read();
  auto p = read_vector(n);
  std::vector<std::vector<std::pair<int, int>>> candidates(n + 1);
  std::vector<int> position(n + 1);
  for (int i = 0; i < n; ++i) {
    position[p[i]] = i;
  }
  for (int i = 0; i < n; ++i) {
    int x = p[i];
    for (int y = 1, xy = x; xy <= n; y++, xy += x) {
      if (i < position[y]) {
        candidates[xy].emplace_back(i, position[y]);
      }
    }
  }
  std::vector<int> pgreater(n), ngreater(n);
  for (int i = 0; i < n; ++i) {
    pgreater[i] = i - 1;
    while (~pgreater[i] && p[pgreater[i]] <= p[i]) {
      pgreater[i] = pgreater[pgreater[i]];
    }
  }
  for (int i = n; i--;) {
    ngreater[i] = i + 1;
    while (ngreater[i] < n && p[ngreater[i]] <= p[i]) {
      ngreater[i] = ngreater[ngreater[i]];
    }
  }
  RangeSum2D rsum(n, q);
  //   std::cerr << KV(p) << std::endl;
  for (int range_max = 1; range_max <= n; ++range_max) {
    auto &cs = candidates[range_max];
    for (int i = cs.size(); i-- > 1;) {
      cs[i - 1].second = std::min(cs[i - 1].second, cs[i].second);
    }
    int m = position[range_max];
    int l = pgreater[m];
    int r = ngreater[m];
    // std::cerr << KV(range_max) << KV(l) << KV(m) << KV(r) << KV(cs)
    //           << std::endl;
    {
      int j = 0;
      while (j < cs.size() && cs[j].first <= l) {
        j++;
      }
      for (int i = l + 1; i <= m && j < cs.size() && cs[j].second < r;) {
        int ii = std::min(cs[j].first, m);
        // x in [i, ii]
        // y in [max(cs[j].second, m), r - 1]
        rsum.add_range(i, ii, std::max(cs[j].second, m), r - 1);
        i = ii + 1;
        j++;
      }
    }
  }
  for (int i = 0; i < q; ++i) {
    int l = read() - 1;
    int r = read() - 1;
    rsum.add_query(i, l, r);
  }
  auto result = rsum.solve();
  for (int i = 0; i < q; ++i) {
    std::cout << result[i] << "\n";
  }
}