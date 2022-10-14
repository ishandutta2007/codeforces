#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<char> plan;
  for (int i = 1; i < n; ++i) {
    plan.push_back('U');
  }
  for (int i = 1; i < m; ++i) {
    plan.push_back('L');
  }
  for (int i = 0; i < n; ++i) {
    char lr = i & 1 ? 'L' : 'R';
    for (int j = 1; j < m; ++j) {
      plan.push_back(lr);
    }
    if (i + 1 < n) {
      plan.push_back('D');
    }
  }
  plan.push_back('\0');
  printf("%d\n", static_cast<int>(plan.size()) - 1);
  puts(plan.data());
}