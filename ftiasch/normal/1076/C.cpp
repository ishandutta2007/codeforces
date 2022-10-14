#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int d;
    scanf("%d", &d);
    if (d * d >= 4 * d) {
      double delta = std::sqrt(d * d - 4 * d);
      printf("Y %.9f %9f\n", (d - delta) * .5, (d + delta) * .5);
    } else {
      puts("N");
    }
  }
}