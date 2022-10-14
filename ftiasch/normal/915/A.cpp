#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int result = m;
  while (n--) {
    int d;
    scanf("%d", &d);
    if (m % d == 0) {
      result = std::min(result, m / d);
    }
  }
  printf("%d\n", result);
}