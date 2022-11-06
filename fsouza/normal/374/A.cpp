#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/2)

typedef long long lint;

using namespace std;

int solve(int n, int i, int a) {
  int diff1 = abs(1 - i), diff2 = abs(n - i);
  int ret = INF;
  if (diff1%a == 0) ret = min(ret, diff1/a);
  if (diff2%a == 0) ret = min(ret, diff2/a);
  return ret;
}

int main(int argc, char ** argv)
{
  int n, m, i, j, a, b;
  cin >> n >> m >> i >> j >> a >> b;

  int res = INF;

  for (int k = 0; k < 2; k++)
    for (int z = 0; z < 2; z++) {
      int d1 = abs(i - (k?1:n)), d2 = abs(j - (z?1:m));
      if (d1%a || d2%b) continue;
      int r1 = d1/a, r2 = d2/b;
      if (r1%2 == r2%2) {
	if (r1 == r2 || (r1 < r2 && 1+a <= n) || (r2 < r1 && 1+b <= m))
	  res = min(res, max(r1, r2));
      }
    }

  if (res == INF) cout << "Poor Inna and pony!" << endl;
  else cout << res << endl;

  return 0;
}