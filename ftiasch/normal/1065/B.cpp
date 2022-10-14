#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  long long m;
  scanf("%d%lld", &n, &m);
  int min = n - std::min(2 * m, static_cast<long long>(n));
  int v = 0;
  while (v * (v - 1LL) / 2 < m) {
    v++;
  }
  int max = n - v;
  printf("%d %d\n", min, max);
}