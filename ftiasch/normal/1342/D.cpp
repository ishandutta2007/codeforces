#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 200'000;

int n, m, c[N];

int main() {
  scanf("%d%d", &n, &m);
  std::multiset<int> tests;
  for (int i = 0, t; i < n; ++i) {
    scanf("%d", &t);
    tests.insert(t);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", c + (m - 1 - i));
  }
  std::vector<std::vector<int>> plan;
  while (!tests.empty()) {
    std::vector<int> new_plan;
    while (true) {
      int i = std::upper_bound(c, c + m, static_cast<int>(new_plan.size())) - c;
      if (i == m) {
        break;
      }
      int maxt = m - i;
      // <= maxt
      auto it = tests.upper_bound(maxt);
      if (it == tests.begin()) {
        break;
      }
      it--;
      new_plan.push_back(*it);
      tests.erase(it);
    }
    plan.emplace_back(std::move(new_plan));
  }
  printf("%d\n", static_cast<int>(plan.size()));
  for (auto &&p : plan) {
    printf("%d", static_cast<int>(p.size()));
    for (int t : p) {
      printf(" %d", t);
    }
    puts("");
  }
}