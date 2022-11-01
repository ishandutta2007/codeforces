/*
 * author:  ADMathNoob
 * created: 05/08/22 08:24:28
 * problem: https://codeforces.com/contest/1677/problem/C
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
    int n;
    cin >> n;
    vector<int> q(n);
    for (int i = 0; i < n; i++) {
      cin >> q[i];
      --q[i];
    }
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[q[i]];
      --p[q[i]];
    }
    vector<bool> was(n, false);
    vector<int> lengths;
    for (int i = 0; i < n; i++) {
      if (!was[i]) {
        int v = i;
        int len = 0;
        while (!was[v]) {
          was[v] = true;
          v = p[v];
          len += 1;
        }
        lengths.push_back(len);
      }
    }
    debug(lengths);
    int k = 0;
    for (int len : lengths) {
      k += len / 2;
    }
    // 1, 2, 3, ..., k, k, ..., 3, 2, 1
    // n-1 numbers total
    vector<int> nums(n - 1, k);
    for (int i = 0; i < k; i++) {
      nums[i] = i + 1;
      nums[n - 2 - i] = i + 1;
    }
    debug(nums);
    long long ans = accumulate(nums.begin(), nums.end(), 0LL);
    ans *= 2;
    cout << ans << '\n';
  }
  return 0;
}