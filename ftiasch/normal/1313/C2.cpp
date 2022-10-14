#include <bits/stdc++.h>

using LL = long long;

const int N = 500001;

int n, a[N], stack[N];
LL sums[2][N];

int main() {
  while (scanf("%d", &n) == 1) {
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
    }
    for (int side = 0; side < 2; ++side) {
      int top = 0;
      stack[top++] = 0;
      LL sum = 0;
      for (int i = 1; i <= n; ++i) {
        while (a[stack[top - 1]] >= a[i]) {
          top--;
          sum -= 1LL * a[stack[top]] * (stack[top] - stack[top - 1]);
        }
        sum += 1LL * a[i] * (i - stack[top - 1]);
        stack[top++] = i;
        sums[side][side ? n + 1 - i : i] = sum;
      }
      std::reverse(a + 1, a + 1 + n);
    }
    std::pair<LL, int> best{0, 0};
    for (int i = 1; i <= n; ++i) {
      best = std::max(best, std::make_pair(sums[0][i] + sums[1][i] - a[i], i));
    }
    int m = best.second;
    for (int i = m - 1; i >= 1; --i) {
      a[i] = std::min(a[i], a[i + 1]);
    }
    for (int i = m + 1; i <= n; ++i) {
      a[i] = std::min(a[i], a[i - 1]);
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d%c", a[i], " \n"[i == n]);
    }
  }
}