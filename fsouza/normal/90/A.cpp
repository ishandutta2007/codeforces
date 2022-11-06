#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long lint;

int solve(int n) {
  int need = (n+1)/2;
  return (need-1) * 3 + 30;
}

int main() {
  int r, g, b;

  scanf("%d %d %d", &r, &g, &b);

  int ret = 0;
  if (r > 0) ret = max(ret, solve(r));
  if (g > 0) ret = max(ret, 1+solve(g));
  if (b > 0) ret = max(ret, 2+solve(b));

  printf("%d\n", ret);

  return 0;
}