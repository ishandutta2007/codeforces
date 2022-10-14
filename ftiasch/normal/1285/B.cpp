#include <bits/stdc++.h>

int n, a[100000];

bool find() {
  long long s = 0;
  for (int i = 0; i < n - 1; ++i) {
    s += a[i];
    if (s <= 0) {
      return true;
    }
  }
  return false;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    bool ok = !find();
    std::reverse(a, a + n);
    ok &= !find();
    puts(ok ? "YES" : "NO");
  }
}