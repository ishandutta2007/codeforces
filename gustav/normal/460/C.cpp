#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <stack>
#include <queue>
#include <vector>

#include <bitset>

#include <string>

#include <algorithm>
#include <functional>

#include <iostream>
#include <sstream>

using namespace std;
typedef long long llint;

#define pb push_back
#define MAXN 100005

int a[MAXN];
llint h[MAXN];
llint d[2 * MAXN];

int main(void)
{
  int n, m, w;
  scanf("%d%d%d", &n, &m, &w);

  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);

  llint lo = 0, hi = 2000000000, mid;

  while (lo < hi) {
    mid = (lo + hi + 1) / 2;

    for (int i = 0; i < n; ++i) {
      d[i] = 0;
      if (a[i] < mid) h[i] = mid - a[i];
      else h[i] = 0;
    }

    llint got = 0;
    llint cnt = 0;
    for (int i = 0; i < n; ++i) {
      got += d[i];
      if (got < h[i]) {
        llint add = h[i] - got;
        got += add;
        cnt += add;
        d[i + w] -= add;
      }
    }

    if (cnt <= m) lo = mid;
    else hi = mid - 1;
  }

  printf("%d\n", (int)lo);

  return 0;
}