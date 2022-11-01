/*
 * author:  ADMathNoob
 * created: 07/11/21 10:04:54
 * problem: https://codeforces.com/contest/1545/problem/D
 */

/*
g++ 1545D.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1545D.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m, k;
  cin >> m >> k;
  vector<vector<long long>> a(k, vector<long long>(m));
  vector<long long> sum(k);
  vector<long long> sum2(k);
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < m; j++) {
      long long x;
      cin >> x;
      a[i][j] = x;
      sum[i] += x;
      sum2[i] += x * x;
    }
  }
  vector<long long> d(k - 1);
  for (int i = 0; i < k - 1; i++) {
    d[i] = sum[i + 1] - sum[i];
  }
  auto ds = d;
  sort(ds.begin(), ds.end());
  ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
  assert((int) ds.size() == 3);
  int mode = ds[1];
  assert(count(d.begin(), d.end(), mode) > 1);
  int when = -1;
  int added = 0;
  for (int i = 0; i < k - 1; i++) {
    if (d[i] != mode) {
      when = i + 1;
      added = d[i] - mode;
      break;
    }
  }
  int ans = -1;
  for (int j = 0; j < m; j++) {
    long long p = sum2[when];
    sum2[when] -= a[when][j] * a[when][j];
    a[when][j] -= added;
    sum2[when] += a[when][j] * a[when][j];
    bool ok = true;
    for (int i = max(when - 3, 0); i <= when && i + 3 < k; i++) {
      ok &= (sum2[i] + sum2[i + 2] - 2 * sum2[i + 1] == sum2[i + 1] + sum2[i + 3] - 2 * sum2[i + 2]);
    }
    if (ok) {
      ans = a[when][j];
      break;
    }
    a[when][j] += added;
    sum2[when] = p;
  }
  cout << when << ' ' << ans << endl;
  return 0;
}