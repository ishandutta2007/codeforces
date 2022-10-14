#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 200'000;

const int DELTA_X[]{0, 0, -1, 1};
const int DELTA_Y[]{1, -1, 0, 0};

int n, tx, ty, d[N];
char s[N + 1];

bool check(int limit) {
  int x = tx, y = ty;
  for (int i = 0; i < n; ++i) {
    x -= DELTA_X[d[i]];
    y -= DELTA_Y[d[i]];
    if (i >= limit - 1) {
      int s = std::abs(x) + std::abs(y);
      if (s <= limit && ~(limit - s) & 1) {
        return true;
      }
      x += DELTA_X[d[i - limit + 1]];
      y += DELTA_Y[d[i - limit + 1]];
    }
  }
  return false;
}

int solve() {
  tx *= -1;
  ty *= -1;
  for (int i = 0; i < n; ++i) {
    d[i] = std::string("UDLR").find(s[i]);
    tx += DELTA_X[d[i]];
    ty += DELTA_Y[d[i]];
  }
  if (tx == 0 && ty == 0) {
    return 0;
  }
  int low = 1;
  int high = n + 1;
  while (low < high) {
    int middle = (low + high) >> 1;
    if (check(middle)) {
      high = middle;
    } else {
      low = middle + 1;
    }
  }
  return high <= n ? high : -1;
}

int main() {
  scanf("%d%s%d%d", &n, s, &tx, &ty);
  printf("%d\n", solve());
}