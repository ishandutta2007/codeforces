#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int h1, a1, c1, h2, a2;
  scanf("%d%d%d%d%d", &h1, &a1, &c1, &h2, &a2);
  std::vector<int> plan;
  while (h2 > 0) {
    if (h2 <= a1) {
      plan.push_back(0);
      h2 -= a1;
      break;
    }
    if (h1 <= a2) {
      plan.push_back(1);
      h1 = h1 + c1 - a2;
    } else {
      plan.push_back(0);
      h2 -= a1;
      h1 -= a2;
    }
  }
  printf("%d\n", static_cast<int>(plan.size()));
  for (int p : plan) {
    puts(p ? "HEAL" : "STRIKE");
  }
}