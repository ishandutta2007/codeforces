#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

long long dist(int x1, int y1, int x2, int y2) {
  return 1LL * (x1 - x2) * (x1 - x2) + 1LL * (y1 - y2) * (y1 - y2);
}

int x[2002], y[2002];

int main() {
  int n, x1, y1, x2, y2;
  cin >> n >> x1 >> y1 >> x2 >> y2;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  long long ans = 1e+18;
  for (int i = 0; i < n; ++i) {
    long long d1 = dist(x1, y1, x[i], y[i]), d2 = 0;
    for (int j = 0; j < n; ++j) {
      if (dist(x1, y1, x[j], y[j]) > d1)
        d2 = max(d2, dist(x2, y2, x[j], y[j]));
    }
    ans = min(ans, d1 + d2);
  }
  for (int i = 0; i < n; ++i) {
    long long d1 = dist(x2, y2, x[i], y[i]), d2 = 0;
    for (int j = 0; j < n; ++j) {
      if (dist(x2, y2, x[j], y[j]) > d1)
        d2 = max(d2, dist(x1, y1, x[j], y[j]));
    }
    ans = min(ans, d1 + d2);
  }
  cout << ans << endl;
  return 0;
}