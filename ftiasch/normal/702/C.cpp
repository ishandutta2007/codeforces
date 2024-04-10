#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<std::pair<int, int>> events(n + m);
  for (int i = 0, a; i < n; ++i) {
    scanf("%d", &a);
    events[i] = {a, i};
  }
  for (int i = 0, b; i < m; ++i) {
    scanf("%d", &b);
    events[n + i] = {b, -1};
  }
  std::sort(events.begin(), events.end());
  std::vector<int> result(n, INT_MAX);
  for (int _ = 0, last = INT_MIN; _ < events.size(); ++_) {
    auto [x, i] = events[_];
    if (~i) {
      if (last > INT_MIN) {
        result[i] = std::min(result[i], x - last);
      }
    } else {
      last = x;
    }
  }
  for (int _ = events.size(), last = INT_MAX; _--;) {
    auto [x, i] = events[_];
    if (~i) {
      if (last < INT_MAX) {
        result[i] = std::min(result[i], last - x);
      }
    } else {
      last = x;
    }
  }
  printf("%d\n", *std::max_element(result.begin(), result.end()));
}