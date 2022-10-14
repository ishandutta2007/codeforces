#line 1 "sol.cpp"
#include <bits/stdc++.h>

bool check(int a, int b, int k) {
  if (a == b) {
    return true;
  }
  int g = std::__gcd(a, b);
  a /= g;
  b /= g;
  if (a > b) {
      std::swap(a, b);
  }
  if (b == 2) {
      return true;
  }
  return (b - 2) / a + 1 < k;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b, k;
    scanf("%d%d%d", &a, &b, &k);
    puts(check(a, b, k) ? "OBEY" : "REBEL");
  }
}