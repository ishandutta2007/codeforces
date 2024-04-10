#line 1 "sol.cpp"
#include <bits/stdc++.h>

int n, a[200'000];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  long long sum = std::accumulate(a, a + n, 0LL);
  int i = 0;
  while (sum > 0) {
    sum -= 2 * a[i++];
  }
  printf("%d\n", i);
}