#include <bits/stdc++.h>

const int N = 100;

int n, m, x[N], y[N];
bool chosen[N << 1];

int count(int a, int b) {
  if (a > b) {
    std::swap(a, b);
  }
  int result = 0;
  for (int i = 0; i < m; ++i) {
    result += (a < x[i] && x[i] < b) ^ (a < y[i] && y[i] < b);
  }
  return result;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    memset(chosen, 0, sizeof(*chosen) * (n << 1));
    for (int i = 0; i < m; ++i) {
      scanf("%d%d", x + i, y + i);
      x[i]--;
      y[i]--;
      if (x[i] > y[i]) {
        std::swap(x[i], y[i]);
      }
      chosen[x[i]] = chosen[y[i]] = true;
    }
    std::vector<int> points;
    for (int i = 0; i < n << 1; ++i) {
      if (!chosen[i]) {
        points.push_back(i);
      }
    }
    int result = 0;
    for (int i = 0; i < m; ++i) {
      result += count(x[i], y[i]);
    }
    result >>= 1;
    if (m < n) {
      result += (n - m) * (n - m - 1) / 2;
      for (int i = 0; i < n - m; ++i) {
        result += count(points[i], points[n - m + i]);
      }
    }
    printf("%d\n", result);
  }
}