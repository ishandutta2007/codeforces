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

int solve(int n, int h) {
  return n / (h+1);
}

lint solve2(int n, int m, int k) {
  lint ret = 0;

  for (int sn = 1; sn <= n / ((k+1)/2 + 1); sn++) {
    int x = min(n/sn - 1, k);
    int y = k - x;

    if (y <= m-1)
      ret = max(ret, (lint)sn * (m / (y + 1)));
  }
  
  return ret;
}

int main() {
  int n, m, k;

  scanf("%d %d %d", &n, &m, &k);

  lint ret;

  if (k > (n-1) + (m-1)) ret = -1;
  else {
    if (k < 100000) {
      ret = 0LL;
      for (int h = 0; h <= k; h++)
	if (h <= n-1 && k-h <= m-1)
	  ret = max(ret, (lint)solve(n, h) * solve(m, k-h));
    } else {
      ret = max(solve2(n, m, k), solve2(m, n, k));
    }
  }

  cout << ret << endl;

  return 0;
}