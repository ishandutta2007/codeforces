#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<int> children(n + 1);
    children[0]++;
    for (int i = 2, p; i <= n; ++i) {
      scanf("%d", &p);
      children[p]++;
    }
    std::ranges::sort(children, std::greater<int>());
    while (!children.empty() && !children.back()) {
      children.pop_back();
    }
    int infections = children.size();
    int low = infections;
    int high = n;
    while (low < high) {
      int middle = (low + high) >> 1;
      int extra_infections = 0;
      for (int i = 0; i < infections; ++i) {
        extra_infections += std::max(i + children[i] - middle, 0);
      }
      if (infections + extra_infections <= middle) {
        high = middle;
      } else {
        low = middle + 1;
      }
    }
    printf("%d\n", high);
  }
}