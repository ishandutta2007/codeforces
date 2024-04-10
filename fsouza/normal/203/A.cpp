#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <utility>

using namespace std;

typedef long long lint;

int main() {
  int x, t, a, b, da, db;

  scanf("%d %d %d %d %d %d", &x, &t, &a, &b, &da, &db);

  bool ret = false;

  if (x == 0) ret = true;
  for (int t0 = 0; t0 < t; t0++)
    if (x == a - t0*da)
      ret = true;
  for (int t1 = 0; t1 < t; t1++)
    if (x == b - t1*db)
      ret = true;
  for (int t0 = 0; t0 < t; t0++)
    for (int t1 = 0; t1 < t; t1++)
      if (x == a - t0*da + b - t1*db)
	ret = true;

  if (ret) printf("YES\n");
  else printf("NO\n");
  
  return 0;
}