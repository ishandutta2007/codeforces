#line 1 "sol.cpp"
// #include "debug.h"

#include <bits/stdc++.h>

using Matrix = std::vector<std::vector<int>>;

int main() {
  int n, m, k, q;
  scanf("%d%d%d%d", &n, &m, &k, &q);
  Matrix a(n, std::vector<int>(m, INT_MAX));
  while (q--) {
    int x, y, t;
    scanf("%d%d%d", &x, &y, &t);
    a[x - 1][y - 1] = t;
  }
//   for (int i = 0; i < n; ++ i) {
//       std::cout << a[i] << std::endl;
//   }
  std::vector<int> queue;
  auto work = [&](const std::vector<int> &a, int n, int k) {
    queue.clear();
    int head = 0;
    std::vector<int> result(n);
    for (int i = 0; i < n; ++i) {
      while (head < queue.size() && a[queue.back()] < a[i]) {
        queue.pop_back();
      }
      queue.push_back(i);
      if (head < queue.size() && i - queue[head] == k) {
        head++;
      }
      result[i] = a[queue[head]];
    }
    return result;
  };
  Matrix ta(m, std::vector<int>(n));
  for (int i = 0; i < n; ++i) {
    auto v = work(a[i], m, k);
    for (int j = 0; j < m; ++j) {
      ta[j][i] = v[j];
    }
  }
  int result = INT_MAX;
  for (int j = k - 1; j < m; ++j) {
    auto v = work(ta[j], n, k);
    for (int i = k - 1; i < n; ++i) {
        result = std::min(result, v[i]);
    }
  }
  printf("%d\n", result < INT_MAX ? result : -1);
}