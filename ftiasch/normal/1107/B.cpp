#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long k;
    int x;
    scanf("%lld%d", &k, &x);
    printf("%lld\n", (k - 1) * 9 + x);
  }
}