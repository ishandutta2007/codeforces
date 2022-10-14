#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int a[3];
    scanf("%d%d%d", a, a + 1, a + 2);
    std::sort(a, a + 3);
    puts(a[2] - 1 <= a[0] + a[1] ? "Yes" : "No");
  }
}