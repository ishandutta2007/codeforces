#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  long long a, b;
  scanf("%lld%lld", &a, &b);
  while (a && b) {
    if (a >= 2 * b) {
        a %= 2 * b;
    } else if (b >= 2 * a) {
        b %= 2 * a;
    } else {
        break;
    }
  }
  printf("%lld %lld\n", a, b);
}