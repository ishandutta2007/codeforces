#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <map>
#include <numeric>
#include <set>
#include <iostream>
#include <vector>

#define INF 1000000000

using namespace std;

typedef long long lint;

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, A;
  int cperf, cmin;
  lint money;
  cin >> n >> A >> cperf >> cmin >> money;

  vector<int> vals(n);
  vector<pair<int, int>> valpos(n);
  for (int i = 0; i < n; ++i) {
    cin >> vals[i];
    valpos[i] = make_pair(vals[i], i);
  }
  sort(vals.begin(), vals.end());
  sort(valpos.begin(), valpos.end());
  
  vector<lint> vsum(n+1);
  vsum[0] = 0;
  for (int i = 0; i < n; ++i) vsum[i+1] = vsum[i] + vals[i];

  lint result = -1;
  int resultmp, resultm, resultminv;

  for (int manyperf = 0; manyperf <= n; ++manyperf) {
    lint have = vsum[n] - vsum[n - manyperf];
    lint need = (lint)manyperf * A - have;

    lint remain = money - need;
    if (remain >= 0) {
      if (manyperf == n) {
    result = (lint)cperf * n + (lint)cmin * A;
    resultmp = n;
    resultm = -1;
    resultminv = -1;
    break;
      }
      
      int l = 0, r = n-1-manyperf;
      while (l < r) {
    int m = (l+r+1)/2;

    lint have2 = vsum[m+1];
    lint need2 = (lint)vals[m] * (m+1) - have2;

    if (need2 <= remain) l = m;
    else r = m-1;
      }
      int m = l;

      lint have2 = vsum[m+1];
      lint need2 = (lint)vals[m] * (m+1) - have2;

      lint remain2 = remain - need2;
      assert(remain2 >= 0);

      lint minv = min(vals[m] + remain2 / (m+1), (lint)A);
      lint res = (lint)cperf * manyperf + (lint)cmin * minv;
      
      if (res >= result) {
    result = res;
    resultmp = manyperf;
    resultm = m;
    resultminv = minv;
      }
    }
  }
  
  cout << result << "\n";

  for (int i = 0; i < resultmp; ++i) vals[n-1-i] = A;
  for (int i = 0; i <= resultm; ++i) vals[i] = resultminv;

  vector<int> vals2(n);
  for (int i = 0; i < n; ++i) vals2[valpos[i].second] = vals[i];

  for (int i = 0; i < n; ++i) {
    if (i > 0) cout << " ";
    cout << vals2[i];
  }
  cout << "\n";
  
  return 0;
}