#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    // min = a | max = b
    // >= a    | <= b
    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) {
      p[i] = n - i;
    }
    if (a > n / 2 + 1 || b < n / 2) {
      puts("-1");
    } else {
      int i = n - a;
      int j = n - b;
      if (i < n / 2 ^ j < n / 2) {
        if (i >= n / 2) {
            std::swap(p[i], p[j]);
        }
        for (int i = 0; i < n; ++i) {
          printf("%d%c", p[i], " \n"[i + 1 == n]);
        }
      } else {
        puts("-1");
      }
    }
  }
}