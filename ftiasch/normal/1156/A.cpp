#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int sum = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i - 1] + a[i] == 5) {
      puts("Infinite");
      return 0;
    }
    sum += a[i - 1] + a[i];
    sum -= i >= 2 && a[i - 2] == 3 && a[i - 1] == 1 && a[i] == 2;
  }
  printf("Finite\n%d\n", sum);
}