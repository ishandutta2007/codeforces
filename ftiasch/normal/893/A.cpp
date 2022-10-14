#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, spec = 3;
  scanf("%d", &n);
  for (int i = 0, a; i < n; ++i) {
    scanf("%d", &a);
    if (a == spec) {
      puts("NO");
      return 0;
    }
    spec ^= a;
  }
  puts("YES");
}