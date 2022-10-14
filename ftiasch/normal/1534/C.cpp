#include <bits/stdc++.h>

static const int MOD = 1e9 + 7;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n), p(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 0, b; i < n; ++i) {
      scanf("%d", &b);
      p[a[i] - 1] = b - 1;
    }
    int result = 1;
    std::fill(a.begin(), a.end(), 0);
    for (int i = 0; i < n && result; ++i) {
      if (p[i] == i) {
        result = 0;
      } else if (!a[i]) {
        result += result;
        if (result >= MOD) {
          result -= MOD;
        }
        int j = i;
        do {
          a[j] = true;
          j = p[j];
        } while (j != i);
      }
    }
    printf("%d\n", result);
  }
}