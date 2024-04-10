#line 1 "sol.cpp"
#include <bits/stdc++.h>

using Long = long long;

const int N = 200'001;

std::vector<int> divs[N];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int d = 1; d <= std::max(n, m); ++d) {
    for (int i = d; i <= std::max(n, m); i += d) {
      divs[i].push_back(d);
    }
  }
  Long low, high;
  scanf("%lld%lld", &low, &high);
  std::set<std::pair<int, int>> bs;
  for (int x = 1, min_y = m + 1, max_y = m; x <= n; ++x) {
    while (min_y >= 2 && x * (min_y - 1LL) >= low) {
      min_y--;
      for (int d : divs[min_y]) {
        bs.emplace(d, min_y);
      }
    }
    while (max_y >= min_y && 1LL * x * max_y > high) {
      for (int d : divs[max_y]) {
        bs.erase({d, max_y});
      }
      max_y--;
    }
    bool found = false;
    for (int a : divs[x]) {
      auto it = bs.upper_bound({a, INT_MAX});
      if (it != bs.end()) {
        auto [b, y] = *it;
        if (1LL * x / a * b <= n) {
          found = true;
          printf("%d %d %d %d\n", x, y, x / a * b, y / b * a);
          break;
        }
      }
    }
    if (!found) {
      puts("-1");
    }
  }
}