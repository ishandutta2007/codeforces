#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, w;
  scanf("%d%d", &n, &w);
  std::vector<int> a(n), v(n);
  std::vector<std::pair<int, int>> order(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    v[i] = (a[i] + 1) >> 1;
    w -= v[i];
    order[i] = {-a[i], i};
  }
  if (w < 0) {
    puts("-1");
    return 0;
  }
  std::sort(order.begin(), order.end());
  for (auto [_, i] : order) {
    int need = std::min(a[i] - v[i], w);
    w -= need;
    v[i] += need;
  }
  for (int i = 0; i < n; ++i) {
    printf("%d%c", v[i], " \n"[i + 1 == n]);
  }
}