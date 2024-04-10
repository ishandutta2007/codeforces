#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  int result = 1;
  int k = 1;
  while (true) {
    int d = ((1 << k) - 1) << (k - 1);
    if (d > n) {
      break;
    }
    if (n % d == 0) {
      result = d;
    }
    k ++;
  }
  printf("%d\n", result);
}