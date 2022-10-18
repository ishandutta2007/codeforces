#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int bc(int mask) {
  int ret = 0;
  while (mask > 0) {
    ret += mask & 1;
    mask >>= 1;
  }
  return ret;
}

double solve(int n, int m) {
  double ans = 0; int cnt = 0;
  for (int mask = 0; mask < (1<< (n * m)); ++mask) {
    if (bc(mask) != n) continue;
    int p = 0;
    for (int i = 0; i < n; ++i) {
      int cur = 0;
      for (int j = 0; j < m; ++j, ++p) {
        if (mask & (1 << p)) ++cur;
      }
      if (cur)
        ans += 1.0 * cur * cur / n / n;
    }
    ++cnt;
  }
  return ans / cnt;
}

int main() {
  int n, m;
  cin >> n >> m;
  long double ans = 0;
  for (int i = 1; i <= n && i <= m; ++i) {
    long double cur = i * i;
    int p = 1, q = n * m;
    if (n - i <= (n - 1) * m)
    for (int j = 0; j < n - i; ++j) {
      cur = cur * ((n - 1) * m - j) / q / (j + 1) * p;
      ++p; --q;
    }
    for (int j = 0; j < i; ++j) {
      cur = cur * (m - j) / q / (j + 1) * p;
      ++p; --q;
    }
    // while (p <= n) {
    //   cur = cur * p / q;
    //   ++p; --q;
    // }
    // cout << cur << endl;
    ans += cur;
  }
  printf("%.10lf\n", (double) ans / n);
  // cout << solve(n, m) << endl;
  return 0;
}