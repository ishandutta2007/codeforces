#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int t;
  scanf("%*d%d", &t);
  int n = 0;
  while (t > 0) {
    int a;
    scanf("%d", &a);
    n++;
    t -= 86400 - a;
  }
  printf("%d\n", n);
}