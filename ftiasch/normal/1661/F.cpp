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
#line 2 "/tmp/tmp-148550EOx2IJG51gwL.cpp"

#line 4 "/tmp/tmp-148550EOx2IJG51gwL.cpp"

Long sqr(int n) { return static_cast<Long>(n) * n; }

Long eval(int n, int k) {
  // k >= 0
  k++;
  int m = n / k;
  int r = n % k;
  return sqr(m) * (k - r) + sqr(m + 1) * r;
}

int solve(int n, Long slope) {
  // max k. eval(n, k - 1) - eval(n, k) >= slope
  int low = 0, high = n;
  while (low < high) {
    int middle = (low + high + 1) >> 1;
    if (eval(n, middle - 1) - eval(n, middle) >= slope) {
      low = middle;
    } else {
      high = middle - 1;
    }
  }
  return low;
}

int main() {
  std::ios::sync_with_stdio(false);
  READ(int, n);
  std::vector<Long> lens(n);
  for (int i = 0, p = 0; i < n; ++i) {
    READ(int, a);
    lens[i] = a - p;
    p = a;
  }
  READ(Long, limit);
  Long low = 0;
  Long high = 1'000'000'000'000'000'001;
  while (low < high) {
    Long middle = (low + high + 1) >> 1;
    Long cost = 0;
    for (int len : lens) {
      int k = solve(len, middle);
      cost += eval(len, k);
    }
    if (cost <= limit) {
      low = middle;
    } else {
      high = middle - 1;
    }
  }
  int result = 0;
  Long cost = 0;
  for (int len : lens) {
    int k = solve(len, low);
    result += k;
    cost += eval(len, k);
  }
  std::cout << result - (limit - cost) / low << "\n";
}