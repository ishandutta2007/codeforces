#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    long long s[]{0, 0};
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
      s[i & 1] += a[i];
    }
    int parity = s[0] > s[1];
    for (int i = 0; i < n; ++i) {
      printf("%d%c", (i & 1) == parity ? 1 : a[i], " \n"[i + 1 == n]);
    }
  }
}