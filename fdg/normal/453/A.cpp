#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

double mPow(double a, int x) {
  double ret = 1;
  while (x > 0) {
    if (x & 1) ret = ret * a;
    a = a * a; x >>= 1;
  }
  return ret;
}

double prob[100005];

int main() {
  int m, n;
  cin >> m >> n;
  double ans = 0;
  // for (int i = 1; i <= m; ++i) {
  //   ans += i * n * mPow(1.0 * i / m, n - 1);
  // }
  for (int i = 1; i <= m; ++i) {
    prob[i] = 1.0 - mPow(1.0 * (i - 1) / m, n);
    prob[i - 1] -= prob[i];
  }
  for (int i = m; i >= 1; --i) {
    ans += prob[i] * i;
  }
  printf("%.10lf\n", ans);
  return 0;
}