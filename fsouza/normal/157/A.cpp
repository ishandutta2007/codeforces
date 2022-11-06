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
  int n;
  scanf("%d", &n);
  vector<int> c(n), r(n);

  for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++) {
      int v;
      scanf("%d", &v);
      c[x] += v;
      r[y] += v;
    }

  int ret = 0;

  for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++)
      if (c[x] > r[y])
	ret++;

  printf("%d\n", ret);

  return 0;
}