#include <bits/stdc++.h>

const int INF = 1e9;

int solve(int num1, int num2, int a) {
  int result = INF;
  for (int x = 0; x <= num1; ++x) {
    for (int y = 0; y <= num2; ++y) {
      int b = a - x - 2 * y;
      if (b >= 0 && b % 3 == 0) {
        result = std::min(result, b / 3);
      }
    }
  }
  return result;
}

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
    int result = INF;
    for (int num1 = 0; num1 < 3; ++num1) {
      for (int num2 = 0; num2 < 3; ++num2) {
        int num3 = 0;
        for (int i = 0; i < n; ++i) {
          num3 = std::max(num3, solve(num1, num2, a[i]));
        }
        result = std::min(result, num1 + num2 + num3);
      }
    }
    printf("%d\n", result);
  }
}