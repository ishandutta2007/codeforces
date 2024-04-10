/*
 * author:  ADMathNoob
 * created: 02/22/22 20:45:16
 * problem: https://codeforces.com/contest/1268/problem/B
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
  int n;
  cin >> n;
  long long sum = 0;
  long long k0 = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    sum += a;
    if (i % 2 == 0) {
      k0 += (a + 1) / 2;
    } else {
      k0 += a / 2;
    }
  }
  long long k1 = sum - k0;
  cout << min(k0, k1) << '\n';
  return 0;
}