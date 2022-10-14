#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 200'000;

int n, limit, a[N];

int main() {
  scanf("%d%d", &n, &limit);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  std::sort(a, a + n, std::greater<int>());
  int result = 0, cost = 0;
  for (int h = a[0], i = 1; h >= 1; --h) {
    while (i < n && a[i] >= h) {
      i++;
    }
    if (i == n) {
        printf("%d\n", result + !!(cost));
        return 0;
    }
    if (cost + i <= limit) {
      cost += i;
    } else {
      result++;
      cost = i;
    }
  }
  printf("%d\n", result);
}