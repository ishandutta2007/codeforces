#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<int> count(2 * n + 2);
    for (int i = 0, x; i < n; ++i) {
      scanf("%d", &x);
      count[x]++;
    }
    int result = 0;
    for (int x = 1; x <= 2 * n + 1; ++x) {
      if (count[x - 1]) {
        count[x - 1]--, result++;
      } else if (count[x]) {
        count[x]--, result++;
      }
    }
    printf("%d\n", result);
  }
}