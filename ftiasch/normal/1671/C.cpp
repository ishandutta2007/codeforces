#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

#define CIN(T, V)                                                              \
  T V;                                                                         \
  std::cin >> V;

#define ALL(v) (v).begin(), (v).end()

template <typename T> std::vector<std::vector<T>> vector_2d(int n, int m) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m));
}

template <typename T> std::vector<std::vector<T>> vector_2d(int n, int m, T d) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m, d));
}

using Long = long long;

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-91692uHdYil6j9z2R.cpp"

#line 4 "/tmp/tmp-91692uHdYil6j9z2R.cpp"

int main() {
  std::ios::sync_with_stdio(false);
  CIN(int, T);
  while (T--) {
    CIN(int, n);
    CIN(int, x);
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    Long result = 0;
    std::ranges::sort(a);
    Long sum = std::accumulate(ALL(a), 0LL);
    for (int i = n, offset = 0; i >= 1; --i) {
      Long exceed = x - (sum + 1LL * offset * i);
      if (exceed >= 0) {
        Long add = exceed / i + 1;
        result += add * i;
        offset += add;
      }
      sum -= a[i - 1];
    }
    std::cout << result << "\n";
  }
}