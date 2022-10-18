#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int main() {
  int n, m;
  long long k;
  cin >> n >> m >> k;
  long long l = 0, r = 1LL * n * m + 1;
  while (r - l > 1) {
    long long mid = (l + r) >> 1;
    long long cnt = 0;
    for (int i = 1; i <= n; ++i) {
      int res = min((long long) m, mid / i);
      cnt += res;
    }
    if (cnt >= k) r = mid;
    else l = mid;
  }
  cout << r << endl;
  return 0;
}