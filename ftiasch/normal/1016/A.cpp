#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 200'000;

int n, m, a[N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  long long s = 0;
  for (int i = 0; i < n; ++i) {
    printf("%lld%c", (s + a[i]) / m - s / m, " \n"[i + 1 == n]);
    s += a[i];
  }
}