#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

long long fen[2][2][1002][1002]; 

void upd(int i, int j, int x, int y, long long val) {
  if (x < 0 || y < 0) return;
  for (int nx = x ; nx <= 1000; nx |= (nx + 1))
    for (int ny = y ; ny <= 1000; ny |= (ny + 1))
      fen[i][j][nx][ny] ^= val;
}

long long fget(int i, int j, int x, int y) {
  // i ^= 1; j ^= 1;
  long long ret = 0;
  for (int nx = x ; nx >= 0; nx = (nx & (nx + 1)) - 1)
    for (int ny = y; ny >= 0; ny = (ny & (ny + 1)) - 1)
      ret ^= fen[i][j][nx][ny];
  return ret;
}

long long get(int x, int y) {
  long long ret = fget(0, 0, x, y);
  if (x % 2 == 0) {
    ret ^= fget(1, 0, 1000, y) ^ fget(1, 0, x, y);
    ret ^= fget(0, 0, 1000, y) ^ fget(0, 0, x, y); 
  }
  if (y % 2 == 0) {
    ret ^= fget(0, 1, x, 1000) ^ fget(0, 1, x, y);
    ret ^= fget(0, 0, x, 1000) ^ fget(0, 0, x, y); 
  }
  if ((x % 2 == 0) && (y % 2 == 0)) {
    for (int dx = 0; dx <= 1; ++dx)
      for (int dy = 0; dy <= 1; ++dy)
        ret ^= fget(dx, dy, 1000, 1000) ^ fget(dx, dy, 1000, y) ^ fget(dx, dy, x, 1000) ^ fget(dx, dy, x, y); 
  }
  return ret;
}

long long get(int x0, int y0,int x1, int y1) {
  return get(x1, y1) ^
         get(x0 - 1, y1) ^
         get(x1, y0 - 1) ^
         get(x0 - 1, y0 - 1);
}

void update(int x, int y, long long v) {
  upd(x & 1, y & 1, x, y, v);
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  while (m--) {
    int t, x0, y0, x1, y1;
    scanf("%d%d%d%d%d", &t, &x0, &y0, &x1, &y1);
    --x0; --y0; --x1; --y1;
    if (t == 2) {
      long long v;
      scanf("%lld", &v);
      update(x1, y1, v);
      update(x1, y0 - 1, v);
      update(x0 - 1, y1, v);
      update(x0 - 1, y0 - 1, v);
    } else {
      printf("%lld\n", get(x0, y0, x1, y1));
    }
  }
  return 0;
}