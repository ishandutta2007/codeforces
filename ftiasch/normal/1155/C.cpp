#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m;
  long long x0, g = 0, x;
  scanf("%d%d%lld", &n, &m, &x0);
  long long last = x0;
  for (int i = 1; i < n; ++i) {
    scanf("%lld", &x);
    g = std::__gcd(g, x - last);
    last = x;
  }
  int found = -1;
  for (int i = 0; i < m; ++i) {
    scanf("%lld", &x);
    if (g % x == 0) {
      found = i;
    }
  }
  if (~found) {
    printf("YES\n%lld %d\n", x0, found + 1);
  } else {
    puts("NO");
  }
}