#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

set<pair<int, int>> f;

bool check(int x, int y) {
  return f.count({x, y}) &&
         f.count({x + 1, y}) &&
         f.count({x, y + 1}) &&
         f.count({x + 1, y + 1});
}

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    f.insert({x, y});
    if (check(x, y) || check(x - 1, y) || check(x, y - 1) || check(x - 1, y - 1)) {
      printf("%d\n", i);
      return 0;
    }
  }
  puts("0");
  return 0;
}