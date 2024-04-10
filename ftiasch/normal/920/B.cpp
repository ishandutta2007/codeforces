#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    int now = 0;
    for (int i = 0, l, r; i < n; ++i) {
      scanf("%d%d", &l, &r);
      int result = 0;
      if (now <= r) {
        result = std::max(now, l);
        now = result + 1;
      }
      printf("%d%c", result, " \n"[i + 1 == n]);
    }
  }
}