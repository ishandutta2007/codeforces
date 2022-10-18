#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>
#include <cmath>

using namespace std;

void solve(int a, int b) {
  for (int x = 1; x < b; ++x) {
    int y = sqrt(0.0 + b * b - x * x) + 0.5;
    if (x * x + y * y == b * b) {
      // cout << x << "  " << y << endl;
      double dx = x, dy = y, g = sqrt(dx * dx + dy * dy);
      dx /= g; dy /= g;
      swap(dx, dy); dx *= -1;
      // cout << dx * a << " " << dy * a << endl;
      for (int tx = -1; tx <= 1; ++tx)
        for (int ty = -1; ty <= 1; ++ty) {
          int nx = x - dx * a + tx, ny = y - dy * a + ty;
          // if (ny == 0) puts("fuck");
          if (ny != 0 && (x - nx) * (x - nx) + (y - ny) * (y - ny) == a * a && nx * nx + ny * ny == a * a + b * b) {
            puts("YES");
            printf("0 0\n%d %d\n%d %d\n", x, y, nx, ny);
            return;
          }
        }
    }
  }
  puts("NO");
}

int main() {
  int a, b;
  cin >> a >> b;
  // for (a = 1; a <= 1000; ++a)
  //   for (b = 1; b <= 1000; ++b)
  // a = 3; b = 4;
  solve(a, b);
  return 0;
}