#include <bits/stdc++.h>

const int N = 200000;

int a[N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    int result = 0;
    for (int l = 0; l < n; ++l) {
      for (int r = l; r < n; ++r) {
        bool found = false;
        for (int i = l; i < r; ++i) {
          for (int j = i + 1; j < r; ++j) {
            if (a[i] >= a[j] && a[j] >= a[r]) {
              found = true;
            }
            if (a[i] <= a[j] && a[j] <= a[r]) {
              found = true;
            }
          }
        }
        if (found) {
          break;
        } else {
          result++;
        }
      }
    }
    printf("%d\n", result);
  }
}