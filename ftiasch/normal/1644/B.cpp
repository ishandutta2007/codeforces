#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    if (n == 3) {
      puts("3 2 1");
      puts("1 3 2");
      puts("3 1 2");
    } else {
      std::vector<int> p(n);
      for (int i = 0; i < n; ++i) {
        p[i] = n - i;
      }
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          printf("%d%c", p[j], " \n"[j + 1 == n]);
        }
        std::rotate(p.begin(), p.begin() + 1, p.end());
      }
    }
  }
}