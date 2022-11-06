#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <utility>

using namespace std;

typedef long long lint;

int main() {
  int r1, r2, c1, c2, d1, d2;

  scanf("%d %d %d %d %d %d", &r1, &r2, &c1, &c2, &d1, &d2);

  int a = (r1 + c1 - d2) / 2;
  int b = (r1 + c2 - d1) / 2;
  int c = (r2 + c1 - d1) / 2;
  int d = (r2 + c2 - d2) / 2;

  int v[4] = {a, b, c, d};
  sort(v, v+4);

  if (1 <= v[0] && v[3] <= 9 && unique(v, v+4) == v+4 &&
      r1 == a+b && r2 == c+d && c1 == a+c && c2 == b+d && d1 == a+d && d2 == b+c)
    printf("%d %d\n%d %d\n", a, b, c, d);
  else
    printf("-1\n");

  return 0;
}