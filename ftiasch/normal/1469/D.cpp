// #include "debug.h"

#include <bits/stdc++.h>

int divide(int a, int b) { return (a + b - 1) / b; }

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n + 1);
    std::iota(a.begin(), a.end(), 0);
    int len = n - 1;
    // invariant: a[n] == len + 1
    std::vector<std::pair<int, int>> plan;
    auto app = [&](int x, int y) {
      a[x] = divide(a[x], a[y]);
      plan.emplace_back(x, y);
    };
    while (a[n] > 3) {
      while (len > 2 && divide(a[n], a[len]) <= len) {
        app(len--, n);
      }
      app(n, len);
    }
    assert(len == 2);
    if (a[n] > 1) {
      app(n, 2);
    }
    if (a[n] > 1) {
      app(n, 2);
    }
    assert(static_cast<int>(plan.size()) <= n + 5);
    assert(std::count(a.begin(), a.end(), 1) == n - 1);
    assert(std::count(a.begin(), a.end(), 2) == 1);
    printf("%d\n", static_cast<int>(plan.size()));
    for (auto [a, b] : plan) {
      printf("%d %d\n", a, b);
    }
  }
}