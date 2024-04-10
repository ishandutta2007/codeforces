#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, a0, a1;
  scanf("%d%d%d", &n, &a0, &a1);
  bool ok = true;
  for (int i = 2, a2; i < n; ++i) {
    scanf("%d", &a2);
    ok &= !(a0 > a1 && a1 < a2);
    a0 = a1;
    a1 = a2;
  }
  puts(ok ? "YES" : "NO");
}