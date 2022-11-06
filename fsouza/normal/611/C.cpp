#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <complex>
#include <map>
#include <numeric>
#include <set>
#include <utility>
#include <vector>
#include <cstring>

#define INF 1000000000

#define MAXH 500
#define MAXW 500

using namespace std;

typedef long long lint;

char field[MAXH][MAXW+1];
int manyh[MAXH][MAXW], manyv[MAXH][MAXW];

void precalc(int h, int w, int many[MAXH][MAXW]) {
  for (int y = 0; y < h; ++y)
    for (int x = 0; x < w; ++x) {
      int &res = many[y][x];
      if (y > 0) res += many[y-1][x];
      if (x > 0) res += many[y][x-1];
      if (y > 0 && x > 0) res -= many[y-1][x-1];
    }
}

int query(int x0, int x1, int y0, int y1, int many[MAXH][MAXW]) {
  int ret = 0;
  ret += many[y1][x1];
  if (y0 > 0) ret -= many[y0-1][x1];
  if (x0 > 0) ret -= many[y1][x0-1];
  if (y0 > 0 && x0 > 0) ret += many[y0-1][x0-1];
  return ret;
}

int main() {
  int h, w;
  scanf("%d %d", &h, &w);

  for (int y = 0; y < h; ++y) scanf(" %s", field[y]);

  for (int y = 0; y < h; ++y)
    for (int x = 0; x < w; ++x) {
      manyh[y][x] = (field[y][x] == '.' && x+1 < w && field[y][x+1] == '.');
      manyv[y][x] = (field[y][x] == '.' && y+1 < h && field[y+1][x] == '.');
    }
  precalc(h, w, manyh);
  precalc(h, w, manyv);

  int nq;
  scanf("%d", &nq);
  for (int q = 0; q < nq; ++q) {
    int y0, x0, y1, x1;
    scanf("%d %d %d %d", &y0, &x0, &y1, &x1);
    --y0, --x0, --y1, --x1;

    int result = 0;
    if (x0 < x1) result += query(x0, x1-1, y0, y1, manyh);
    if (y0 < y1) result += query(x0, x1, y0, y1-1, manyv);
    printf("%d\n", result);
  }
  
  return 0;
}