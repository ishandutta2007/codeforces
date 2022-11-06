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
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n, l, v1, v2, k;
  scanf("%d %d %d %d %d", &n, &l, &v1, &v2, &k);

  double left = (double)l / v2, right = (double)l / v1;

  for (int rep = 0; rep < 500; ++rep) {
    double mid = (left+right)/2.;
    double inbus = (l - mid * v1) / (v2 - v1);
    int nblock = (n + k-1) / k;

    double now = 0.0;
    double pos = 0.0;
    for (int i = 0; i < nblock; ++i) {
      now += inbus;
      pos += inbus * v2;
      if (i+1 < nblock) {
	double at = now * v1;
	double takes = (pos - at) / (v1 + v2);
	now += takes;
	pos -= takes * v2;
      }
    }

    if (now < mid) right = mid;
    else left = mid;
  }

  printf("%.10f\n", left);

  return 0;
}