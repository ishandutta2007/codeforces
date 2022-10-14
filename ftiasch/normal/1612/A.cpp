#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int x, y;
    scanf("%d%d", &x, &y);
    if ((x + y) & 1) {
      puts("-1 -1");
    } else {
      int target = (x + y) >> 1;
      if (target <= x) {
        printf("%d %d\n", target, 0);
      } else {
        printf("%d %d\n", x, target - x);
      }
    }
  }
}