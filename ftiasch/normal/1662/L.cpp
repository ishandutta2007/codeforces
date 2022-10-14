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

template <typename T> using Vector2D = std::vector<std::vector<T>>;

template <typename T = int> Vector2D<T> vector_2d(int n, int m) {
  return Vector2D<T>(n, std::vector<T>(m));
}

template <typename T = int> Vector2D<T> vector_2d(int n, int m, T d) {
  return Vector2D<T>(n, std::vector<T>(m, d));
}

using Long = long long;
using u64 = uint64_t;

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template <typename T> std::vector<int> discretize(const std::vector<T> &a) {
  auto values = a;
  std::sort(ALL(values));
  values.erase(std::unique(ALL(values)), values.end());
  std::vector<int> result(a.size());
  for (int i = 0; i < a.size(); ++i) {
    result[i] = std::lower_bound(ALL(values), a[i]) - values.begin();
  }
  return result;
}
#line 2 "/tmp/tmp-4448DqbQXX1p1t0O.cpp"

#line 4 "/tmp/tmp-4448DqbQXX1p1t0O.cpp"

int main() {
  std::ios::sync_with_stdio(false);
  int n = read();
  int v = read();
  auto t = read_vector(n);
  auto a = read_vector(n);
  std::vector<std::pair<Long, Long>> p;
  for (int i = 0; i < n; ++i) {
    Long x = 1LL * v * t[i];
    if (x + a[i] >= 0 && x - a[i] >= 0) {
      p.emplace_back(x + a[i], x - a[i]);
    }
  }
  std::ranges::sort(p);
  std::vector<int> y;
  {
    std::vector<Long> y_(p.size());
    for (int i = 0; i < p.size(); ++i) {
      y_[i] = p[i].second;
    }
    y = discretize(y_);
  }
  std::vector<int> fenwick(n);
  int result = 0;
  for (int i = 0; i < y.size(); ++i) {
    int dp = 1;
    for (int k = y[i]; ~k; k -= ~k & k + 1) {
      dp = std::max(dp, fenwick[k] + 1);
    }
    result = std::max(result, dp);
    for (int k = y[i]; k < n; k += ~k & k + 1) {
      fenwick[k] = std::max(fenwick[k], dp);
    }
  }
  std::cout << result << "\n";
}