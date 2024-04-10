#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  double res = 0;
  for (int i = 1; i <= n; ++ i) {
    res += 1.0 / i;
  }
  printf("%.9f\n", res);
}