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

lint solve(int a, int b, int c, int maxdiff) {
  // c >= a+b
  lint ret = 0;
  for (int nab = 0; nab <= maxdiff; ++nab) {
    int sumab = a+b+nab;
    int minnc = max(0, sumab - c);
    int maxnc = maxdiff - nab;
    if (minnc <= maxnc)
      ret += (lint)(nab+1) * (maxnc - minnc + 1);
  }
  return ret;
}

int main() {
  int a, b, c, maxdiff;
  scanf("%d %d %d %d", &a, &b, &c, &maxdiff);

  lint ret = (lint)(maxdiff+3)*(maxdiff+2)*(maxdiff+1)/6;
  ret -= solve(b, c, a, maxdiff);
  ret -= solve(a, c, b, maxdiff);
  ret -= solve(a, b, c, maxdiff);

  printf("%lld\n", ret);

  return 0;
}