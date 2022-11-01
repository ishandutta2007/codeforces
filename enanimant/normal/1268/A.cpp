/*
 * author:  ADMathNoob
 * created: 02/22/22 20:27:38
 * problem: https://codeforces.com/contest/1268/problem/A
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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    a[i] = c - '0';
  }
  vector<int> b(a.begin(), a.begin() + k);
  for (int i = 0; i < n; i++) {
    if (a[i] > b[i % k]) {
      for (int j = k - 1; j >= 0; j--) {
        if (b[j] < 9) {
          b[j] += 1;
          break;
        }
        b[j] = 0;
      }
      break;
    }
    if (a[i] < b[i % k]) {
      break;
    }
  }
  cout << n << '\n';
  for (int i = 0; i < n; i++) {
    cout << b[i % k];
  }
  cout << '\n';
  return 0;
}