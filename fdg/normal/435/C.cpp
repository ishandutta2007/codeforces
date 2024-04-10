#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

char ans[2005][1005];

int main() {
  int n, a;
  scanf("%d", &n);
  int pos = 1001, mx = pos, mn = pos;
  int y = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a);
    for (int j = 0; j < a; ++j) {
      ans[pos][y] = (i & 1) ? '\\' : '/';
      if (i & 1) --pos;
      else ++pos;
      ++y;
    }
    if (i & 1) ++pos;
    else --pos;
    mx = max(mx, pos);
    mn = min(mn, pos);
  }
  for (int i = mx; i >= mn; --i) {
    for (int j = 0; j < y; ++j) {
      if (ans[i][j] == '\0') ans[i][j] = ' ';
      printf("%c", ans[i][j]);
    }
    printf("\n");
  }
  return 0;
}