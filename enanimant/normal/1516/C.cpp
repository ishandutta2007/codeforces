/*
 * author:  ADMathNoob
 * created: 04/21/21 09:48:16
 * problem: https://codeforces.com/contest/1516/problem/C
 */

/*
g++ 1516C.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -Wall -Wfatal-errors -ggdb && gdb a
g++ 1516C.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -O3 -Wall -Wfatal-errors


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  int g = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    g = __gcd(g, a[i]);
  }
  for (int i = 0; i < n; i++) {
    a[i] /= g;
  }
  int W = accumulate(a.begin(), a.end(), 0);
  vector<int> dp(W + 1, 0);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = W; j >= a[i]; j--) {
      if (dp[j - a[i]]) {
        dp[j] = true;
      }
    }
  }
  vector<int> ret;
  if (W % 2 == 0 && dp[W / 2]) {
    for (int i = 0; i < n; i++) {
      if (a[i] % 2 == 1) {
        ret.push_back(i);
        break;
      }
    }
  }
  cout << ret.size() << '\n';
  if (!ret.empty()) {
    cout << ret[0] + 1 << '\n';
  }
  return 0;
}