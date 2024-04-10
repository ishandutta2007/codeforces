/*
 * author:  ADMathNoob
 * created: 09/06/22 10:35:06
 * problem: https://codeforces.com/contest/1726/problem/B
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

#ifdef _DEBUG
#include "../.cp/algorithms/debug/debug.h"
#else
#define debug(...) 42
#endif

void TestCase(int n, int m) {
  if (m < n) {
    cout << "No\n";
    return;
  }
  if (m % 2 == 1 && n % 2 == 0) {
    cout << "No\n";
    return;
  }
  if (n % 2 == 1) {
    cout << "Yes\n";
    for (int i = 0; i < n - 1; i++) {
      cout << "1 ";
    }
    cout << m - (n - 1) << '\n';
    return;
  }
  // n, m even
  cout << "Yes\n";
  for (int i = 0; i < n - 2; i++) {
    cout << "1 ";
  }
  int h = (m - (n - 2)) / 2;
  cout << h << ' ' << h << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    TestCase(n, m);
  }
  return 0;
}