#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  int sum = 0;
  for (int i = 0, a; i < n; ++i) {
    scanf("%d", &a);
    sum += std::abs(a);
  }
  printf("%d\n", sum);
}