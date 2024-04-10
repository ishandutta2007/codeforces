#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 100;

int n, a[N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    std::sort(a, a + n, std::greater<int>());
    for (int i = 0; i < n; ++i) {
      printf("%d%c", a[i], " \n"[i + 1 == n]);
    }
  }
}