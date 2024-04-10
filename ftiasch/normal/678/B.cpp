#line 1 "sol.cpp"
#include <bits/stdc++.h>

bool leap(int y) { return y % 100 == 0 ? y % 400 == 0 : y % 4 == 0; }

int main() {
  int y, sum = 0;
  scanf("%d", &y);
  bool l0 = leap(y);
  do {
    sum = (sum + (leap(y++) ? 366 : 365)) % 7;
  } while (sum != 0 || leap(y) != l0);
  printf("%d\n", y);
}