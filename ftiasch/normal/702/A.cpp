#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  int result = 0, dp = 0, pre = INT_MAX;
  for (int i = 0, a; i < n; ++i) {
    scanf("%d", &a);
    if (pre < a) {
      dp++;
    } else {
      dp = 1;
    }
    pre = a;
    result = std::max(result, dp);
  }
  printf("%d\n", result);
}