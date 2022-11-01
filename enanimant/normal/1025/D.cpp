/*
 * author:  ADMathNoob
 * created: 02/25/21 23:04:02
 * problem: https://codeforces.com/contest/1025/problem/D
 */

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1025D.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1025D.cpp -ggdb && gdb a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -O3 -Wall -Wfatal-errors 1025D.cpp && a


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<bool>> ok(n, vector<bool>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ok[i][j] = (__gcd(a[i], a[j]) > 1);
    }
  }
  // find if possible to build a tree "sloping" down to the left and right
  vector<vector<bool>> dpl(n, vector<bool>(n, false));
  vector<vector<bool>> dpr(n, vector<bool>(n, false));
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i; j < n; j++) {
      if (i == j) {
        dpl[i][j] = dpr[i][j] = true;
        continue;
      }
      for (int k = i + 1; k <= j; k++) {
        if (ok[i][k] && dpl[i + 1][k] && dpr[k][j]) {
          dpr[i][j] = true;
        }
      }
      for (int k = i; k <= j - 1; k++) {
        if (ok[j][k] && dpl[i][k] && dpr[k][j - 1]) {
          dpl[i][j] = true;
        }
      }
    }
  }
  bool ans = false;
  for (int i = 0; i < n; i++) {
    if (dpl[0][i] && dpr[i][n - 1]) {
      ans = true;
    }
  }
  cout << (ans ? "Yes" : "No") << '\n';

  return 0;
}