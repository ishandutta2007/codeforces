#include <bits/stdc++.h>

const int N = 100000;

int a[N];

int main() {
  int T, n;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    int amin = INT_MAX, amax = INT_MIN, lower = 0;
    for (int i = 0; i < n; ++i) {
      if (~a[i] && ((i && !~a[i - 1]) || (i + 1 < n && !~a[i + 1]))) {
        amin = std::min(amin, a[i]);
        amax = std::max(amax, a[i]);
      }
      if (~a[i] && i && ~a[i - 1]) {
        lower = std::max(lower, std::abs(a[i] - a[i - 1]));
      }
    }
    if (amin == INT_MAX) {
      printf("%d 0\n", lower);
    } else {
      printf("%d %d\n", std::max(amax - amin + 1 >> 1, lower),
             amin + amax >> 1);
    }
  }
}