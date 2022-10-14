#line 1 "sol.cpp"
// #include "debug.h"

#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  {
    auto self = std::find(a.begin(), a.end(), -1);
    std::fill(a.begin(), self, 0);
    a.erase(self);
  }
  long long result = a[n - 2];
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
  for (int i = (n - 2), step = n / 2; step > 1; step >>= 1) {
    for (int j = i - step; j < i; ++j) {
      pq.emplace(a[j]);
    }
    i -= step;
    result += pq.top();
    pq.pop();
  }
  printf("%lld\n", result);
}