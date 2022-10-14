#line 1 "sol.cpp"
#include <bits/stdc++.h>

using Long = long long;

const Long INF = 1'00'000'000'000'000LL;

int main() {
  int x0, y0, x1, y1, n;
  scanf("%d%d%d%d%d", &x0, &y0, &x1, &y1, &n);
  x0 -= x1;
  y0 -= y1;
  std::vector<char> dir(n + 1);
  scanf("%s", dir.data());
  std::vector<int> dx(n + 1), dy(n + 1);
  for (int i = 0; i < n; ++i) {
    dx[i + 1] = dx[i] - (dir[i] == 'L') + (dir[i] == 'R');
    dy[i + 1] = dy[i] - (dir[i] == 'D') + (dir[i] == 'U');
  }
  Long low = 0, high = INF + 1;
  while (low < high) {
    Long middle = (low + high) >> 1;

    Long x = x0 + dx[n] * (middle / n) + dx[middle % n];
    Long y = y0 + dy[n] * (middle / n) + dy[middle % n];

    if (std::abs(x) + std::abs(y) <= middle) {
      high = middle;
    } else {
      low = middle + 1;
    }
  }
  printf("%lld\n", high <= INF ? high : -1);
}