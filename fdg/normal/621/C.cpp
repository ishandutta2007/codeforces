#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int l[100005], r[100005];

int main() {
  int n, p;
  scanf("%d%d", &n, &p);
  double ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &l[i], &r[i]);
    ans += 4.0 * (r[i] / p - (l[i] - 1) / p) / (r[i] - l[i] + 1);
  }
  for (int i = 0; i < n; ++i) {
    double p1 = 1.0 * (r[i] / p - (l[i] - 1) / p) / (r[i] - l[i] + 1);
    int ni = (i + 1) % n;
    double p2 = 1.0 * (r[ni] / p - (l[ni] - 1) / p) / (r[ni] - l[ni] + 1);
    ans -= 2.0 * p1 * p2;
  }
  printf("%.10lf\n", 1000 * ans);
  return 0;
}