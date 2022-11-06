#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d), --a, --b, --c, --d;
  if (n <= 4 || k < n+1) printf("-1\n");
  else {
    printf("%d %d", a+1, c+1);
    for (int i = 0; i < n; ++i)
      if (i != a && i != b && i != c && i != d)
	printf(" %d", i+1);
    printf(" %d %d\n", d+1, b+1);

    printf("%d %d", c+1, a+1);
    for (int i = 0; i < n; ++i)
      if (i != a && i != b && i != c && i != d)
	printf(" %d", i+1);
    printf(" %d %d\n", b+1, d+1);
  }

  return 0;
}