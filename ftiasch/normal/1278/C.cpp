#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n << 1);
    for (int i = 0; i < (n << 1); ++i) {
      scanf("%d", &a[i]);
      a[i] = a[i] * 2 - 3;
    }
    std::map<int, int> sufmap;
    sufmap[0] = n;
    for (int i = n, sum = 0; i--;) {
      sum += a[n + i];
      sufmap[sum] = i;
    }
    int result = sufmap[0] + n;
    for (int i = n, sum = 0; i--;) {
      sum += a[(n - 1) - i];
      auto iterator = sufmap.find(-sum);
      if (iterator != sufmap.end()) {
        result = std::min(result, i + iterator->second);
      }
    }
    printf("%d\n", result);
  }
}