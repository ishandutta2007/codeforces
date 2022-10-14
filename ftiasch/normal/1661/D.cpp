#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

#define READ(T, V)                                                             \
  T V;                                                                         \
  std::cin >> V;

#define READ_VECTOR(T, V, n)                                                   \
  std::vector<T> V((n));                                                       \
  for (int i = 0; i < (n); ++i) {                                              \
    std::cin >> V[i];                                                          \
  }

#define ALL(v) (v).begin(), (v).end()

template <typename T> std::vector<std::vector<T>> vector_2d(int n, int m) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m));
}

template <typename T> std::vector<std::vector<T>> vector_2d(int n, int m, T d) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m, d));
}

using Long = long long;
using u64 = uint64_t;

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-49393Fb0WpYVFbVu.cpp"

#line 4 "/tmp/tmp-49393Fb0WpYVFbVu.cpp"

int main() {
  std::ios::sync_with_stdio(false);
  READ(int, n);
  READ(int, m);
  READ_VECTOR(Long, b, n);
  std::vector<Long> delta(n);
  Long sum0 = 0, sum1 = 0;
  for (int i = n; i-- > m;) {
    Long d = delta[i - m + 1] = (std::max<Long>(b[i] - sum1, 0) + m - 1) / m;
    sum1 += d * m;
    sum0 += d;
    sum1 -= sum0;
    sum0 -= delta[i];
  }
  for (int i = m; i--;) {
    Long d = (std::max<Long>(b[i] - sum1, 0) + i) / (i + 1);
    delta[0] = std::max(delta[0], d);
    sum1 -= sum0;
    sum0 -= delta[i];
  }
  std::cout << std::accumulate(ALL(delta), 0LL) << "\n";
}