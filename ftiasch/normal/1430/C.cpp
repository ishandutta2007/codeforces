#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    int last = n;
    puts("2");
    for (int i = n - 1; i >= 1; --i) {
      printf("%d %d\n", i, last);
      last = (i + last + 1) >> 1;
    }
  }
}