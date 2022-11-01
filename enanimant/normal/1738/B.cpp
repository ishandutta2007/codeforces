/*
 * author:  ADMathNoob
 * created: 09/30/22 10:35:09
 * problem: https://codeforces.com/contest/1738/problem/B
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

int CeilDiv(int a, int b) {
  if (a % b == 0) return a / b;
  if (a < 0) return a / b;
  return a / b + 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> s(n + 1);
    for (int i = n - k + 1; i <= n; i++) {
      cin >> s[i];
    }
    vector<int> a(n);
    for (int i = n - k + 1; i < n; i++) {
      a[i] = s[i + 1] - s[i];
    }
    int c = n - k + 1;
    int x = CeilDiv(s[c], c);
    for (int i = 0; i <= n - k; i++) {
      a[i] = x;
    }
    cout << (is_sorted(a.begin(), a.end()) ? "Yes" : "No") << '\n';
  }
  return 0;
}