#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int x[3], y[3];

int gans(int xx, int yy) {
  int ret = 0;
  for (int i = 0; i < 3; ++i)
    ret += abs(xx - x[i]) + abs(yy - y[i]);
  return ret;
}

void gt(int x, int y, int x2, int y2) {
  while (x < x2)
    printf("%d %d\n", ++x, y);
  while (x > x2)
    printf("%d %d\n", --x, y);
  while (y < y2)
    printf("%d %d\n", x, ++y);
  while (y > y2)
    printf("%d %d\n", x, --y);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  for (int i = 0; i < 3; ++i)
    scanf("%d%d", &x[i], &y[i]);
  int px = 0, py = 0;
  for (int i = 0; i <= 1000; ++i)
    for (int j = 0; j <= 1000; ++j)
      if (gans(px, py) > gans(i, j)) {
        px = i;
        py = j;
      }
  printf("%d\n", gans(px, py) + 1);
  printf("%d %d\n", px, py);
  for (int i = 0; i < 3; ++i)
    gt(px, py, x[i], y[i]);

#ifndef ONLINE_JUDGE
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}