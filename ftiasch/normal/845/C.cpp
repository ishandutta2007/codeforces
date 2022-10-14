#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<std::pair<int, int>> events(n << 1);
  for (int i = 0, l, r; i < n; ++i) {
    scanf("%d%d", &l, &r);
    events[i << 1] = {l, -1};
    events[i << 1 | 1] = {r, 1};
  }
  std::sort(events.begin(), events.end());
  bool ok = true;
  for (int i = 0, sum = 0; i < n << 1; ++i) {
    sum -= events[i].second;
    ok &= sum <= 2;
  }
  puts(ok ? "YES" : "NO");
}