#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    if (a[0] + a[1] <= a[n - 1]) {
      printf("1 2 %d\n", n);
    } else {
      puts("-1");
    }
  }
}