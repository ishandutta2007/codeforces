#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 300'000;

int n, m, a[N], b[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", b + i);
  }
  if (std::accumulate(a, a + n, 0LL) != std::accumulate(b, b + m, 0LL)) {
    puts("-1");
  } else {
    int result = 0;
    int i = 0, j = 0;
    while (i < n || j < m) {
      result++;
      long long as = a[i++];
      long long bs = b[j++];
      while (as != bs) {
        if (as < bs) {
          as += a[i++];
        } else {
          bs += b[j++];
        }
      }
    }
    printf("%d\n", result);
  }
}