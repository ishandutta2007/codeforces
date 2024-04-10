#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    if (n % 3 == 1) {
      printf("1");
    }
    for (int i = 0; i < n / 3; ++i) {
      printf("21");
    }
    if (n % 3 == 2) {
      printf("2");
    }
    puts("");
  }
}