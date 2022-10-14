#line 1 "sol.cpp"
#include <bits/stdc++.h>

bool is_prime(int x) {
  if (x == 1) {
    return true;
  }
  for (int p = 2; p * p <= x; ++p) {
    if (x % p == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int x, d;
    scanf("%d%d", &x, &d);
    int c = 0;
    while (x % d == 0) {
      c++;
      x /= d;
    }
    if (c == 1) {
      puts("NO");
    } else if (c == 2) {
      puts(is_prime(x) ? "NO" : "YES");
    } else if (!is_prime(x)) {
      puts("YES");
    } else if (is_prime(d)) {
      puts("NO");
    } else if (x == 1) {
      puts("YES");
      // !is_prime(d) && is_prime(x)
    } else if (c > 3) {
      puts("YES");
      // c == 3
    } else if (d % x != 0) {
      puts("YES");
    } else if (!is_prime(d / x)) {
      puts("YES");
    } else {
      int y = d / x; // prime
      puts(x == y ? "NO" : "YES");
    }
  }
}