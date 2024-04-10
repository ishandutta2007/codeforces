#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 200'000;

int n;
long long a[N], b[N >> 1];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < (n >> 1); ++i) {
    scanf("%lld", b + i);
  }
  a[0] = 0;
  a[n - 1] = b[0];
  for (int i = 1; i < (n >> 1); ++ i) {
      a[i] = std::max(a[i - 1], b[i] - a[n - i]);
      a[n - 1 - i] = b[i] - a[i];
  }
  for (int i = 0; i < n; ++ i) {
      printf("%lld%c", a[i], " \n"[i + 1 == n]);
  }
}