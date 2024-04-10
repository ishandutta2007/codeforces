#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    std::vector<int> maxp(n + 1);
    int m;
    scanf("%d", &m);
    while (m--) {
      int p, s;
      scanf("%d%d", &p, &s);
      maxp[s] = std::max(maxp[s], p);
    }
    for (int i = n; i--;) {
      maxp[i] = std::max(maxp[i], maxp[i + 1]);
    }
    int result = 0;
    for (int i = 0; i < n && ~result;) {
      int count = 0;
      int maxa = 0;
      while (i + count < n && std::max(maxa, a[i + count]) <= maxp[count + 1]) {
        maxa = std::max(maxa, a[i + count]);
        count++;
      }
      if (count) {
        i += count;
        result++;
      } else {
        result = -1;
      }
    }
    printf("%d\n", result);
  }
}