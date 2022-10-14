#include <bits/stdc++.h>

bool lava[2][100000];

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  int count = 0;
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--, y--;
    for (int yy = std::max(y - 1, 0); yy <= std::min(y + 1, n - 1); ++yy) {
      count -= lava[x][y] && lava[x ^ 1][yy];
    }
    lava[x][y] ^= 1;
    for (int yy = std::max(y - 1, 0); yy <= std::min(y + 1, n - 1); ++yy) {
      count += lava[x][y] && lava[x ^ 1][yy];
    }
    puts(count == 0 ? "Yes" : "No");
  }
}