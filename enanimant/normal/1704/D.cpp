/*
 * author:  ADMathNoob
 * created: 07/31/22 07:05:07
 * problem: https://codeforces.com/contest/1704/problem/D
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

#ifdef _DEBUG
#include "../algorithms/debug/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> a(n, vector<long long>(m));
    vector<long long> value(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        value[i] += j * a[i][j];
      }
    }
    unordered_map<long long, int> cnt;
    for (int i = 0; i < n; i++) {
      cnt[value[i]] += 1;
    }
    assert(cnt.size() == 2);
    auto [min_v, max_v] = minmax(cnt.begin()->first, next(cnt.begin())->first);
    int k = find(value.begin(), value.end(), max_v) - value.begin();
    cout << k + 1 << ' ' << max_v - min_v << '\n';
  }
  return 0;
}