#line 1 "sol.cpp"
#include <bits/stdc++.h>

int n, x, a[100'000];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    std::sort(a, a + n, std::greater<int>());
    int i = 0;
    long long s = 0;
    while (i < n && s + a[i] - x >= 0) {
      s += a[i] - x;
      i++;
    }
    printf("%d\n", i);
  }
}