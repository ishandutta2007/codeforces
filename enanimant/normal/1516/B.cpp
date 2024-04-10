/*
 * author:  ADMathNoob
 * created: 04/21/21 09:48:16
 * problem: https://codeforces.com/contest/1516/problem/B
 */

/*
g++ 1516B.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -Wall -Wfatal-errors -ggdb && gdb a
g++ 1516B.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -O3 -Wall -Wfatal-errors


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] ^ a[i];
    }
    int x = pref[n];
    if (x == 0) {
      cout << "YES\n";
      continue;
    }
    vector<bool> dp(n + 1, false);
    for (int i = 0; i < n - 1; i++) {
      if (pref[i + 1] == x) {
        dp[i + 1] = true;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        if (dp[j] && (pref[i + 1] ^ pref[j]) == x) {
          dp[i + 1] = true;
        }
      }
    }
    cout << (dp[n] ? "YES" : "NO") << '\n';
  }
  return 0;
}