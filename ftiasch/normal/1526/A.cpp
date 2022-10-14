#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n << 1);
    for (int i = 0; i < n << 1; ++i) {
      scanf("%d", &a[i]);
    }
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n << 1; ++i) {
      printf("%d%c", a[(i & 1 ? n : 0) + (i >> 1)], " \n"[i + 1 == (n << 1)]);
    }
  }
}