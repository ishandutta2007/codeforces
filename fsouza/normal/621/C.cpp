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
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n, p;
  scanf("%d %d", &n, &p);

  vector<int> start(n), end(n);
  for (int i = 0; i < n; ++i) scanf("%d %d", &start[i], &end[i]);

  double result = 0.0;
  for (int i = 0; i < n; ++i) {
    int i1 = (i+1)%n;
    double noti = 1.0 - (end[i] / p - (start[i]-1)/p) / (end[i] - start[i] + 1.0);
    double noti1 = 1.0 - (end[i1] / p - (start[i1]-1)/p) / (end[i1] - start[i1] + 1.0);
    double yes = 1.0 - noti * noti1;
    result += 2 * 1000 * yes;
  }

  printf("%.9f\n", result);
  
  return 0;
}