#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  printf("?");
  for (int mask = 1; mask <= 100; ++mask) {
    printf(" %d", mask);
  }
  puts("");
  fflush(stdout);
  int high;
  scanf("%d", &high);
  high &= ~((1 << 7) - 1);
  printf("?");
  for (int mask = 1; mask <= 100; ++mask) {
    printf(" %d", mask << 7);
  }
  puts("");
  fflush(stdout);
  int low;
  scanf("%d", &low);
  low &= ((1 << 7) - 1);
  printf("! %d\n", high | low);
  fflush(stdout);
}