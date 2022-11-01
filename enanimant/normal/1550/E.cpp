/*
 * author:  ADMathNoob
 * created: 07/19/21 10:02:44
 * problem: https://codeforces.com/contest/1550/problem/E
 */

/*
g++ 1550E.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1550E.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> s(n);
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    s[i] = (c == '?' ? -1 : (int) (c - 'a'));
  }
  auto Works = [&](int need) -> bool {
    vector<vector<int>> nxt(k, vector<int>(n));
    for (int c = 0; c < k; c++) {
      int next_other = n;
      for (int i = n - 1; i >= 0; i--) {
        if (s[i] != c && s[i] != -1) {
          next_other = i;
        }
        if (next_other >= i + need) {
          nxt[c][i] = i + need;
        } else {
          nxt[c][i] = (i + 1 < n ? nxt[c][i + 1] : -1);
        }
      }
    }
    vector<int> dp(1 << k, -1);
    dp[0] = 0;
    for (int mm = 0; mm < (1 << k); mm++) {
      if (dp[mm] == -1 || dp[mm] == n) {
        continue;
      }
      for (int c = 0; c < k; c++) {
        if (!(mm & (1 << c))) {
          int nmm = mm | (1 << c);
          int r = nxt[c][dp[mm]];
          if (r != -1) {
            if (dp[nmm] == -1 || dp[nmm] > r) {
              dp[nmm] = r;
            }
          }
        }
      }
    }
    return (dp[(1 << k) - 1] != -1);
  };
  int low = 0, high = n;
  while (low < high) {
    int mid = (low + high + 1) / 2;
    if (Works(mid)) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }
  cout << low << '\n';
  return 0;
}