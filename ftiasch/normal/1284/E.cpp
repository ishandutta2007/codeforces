#include <bits/stdc++.h>

const int N = 2500;

struct Point {
  int quad() const { return x ? x > 0 : y > 0; }

  int x, y;
};

long long det(const Point &a, const Point &b) {
  return 1LL * a.x * b.y - 1LL * a.y * b.x;
}

bool operator<(const Point &a, const Point &b) {
  if (a.quad() != b.quad()) {
    return a.quad() < b.quad();
  }
  return det(a, b) > 0;
}

int n, x[N], y[N];
Point p[N + N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", x + i, y + i);
  }
  n--;
  long long result = 0;
  long long c4 = 1LL * n * (n - 1) * (n - 2) * (n - 3) / 24;
  for (int o = 0; o <= n; ++o) {
    result += c4;
    for (int i = 0; i <= n; ++i) {
      if (i != o) {
        p[i < o ? i : i - 1] = Point{x[i] - x[o], y[i] - y[o]};
      }
    }
    std::sort(p, p + n);
    std::copy(p, p + n, p + n);
    for (int i = 0, j = 0; i < n; ++i) {
      if (j) {
        j--;
      }
      while (j < n - 1 && det(p[i], p[i + 1 + j]) > 0) {
        j++;
      }
      result -= 1LL * j * (j - 1) * (j - 2) / 6;
    }
  }
  printf("%lld\n", result);
}