/*
 * author:  ADMathNoob
 * created: 05/30/21 10:33:09
 * problem: https://codeforces.com/contest/1523/problem/D
 */

/*
g++ 1523D.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1523D.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, _;
  cin >> n >> m >> _;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (s[j] == '1') {
        a[i] |= (1LL << j);
      }
    }
  }
  vector<int> tests(n);
  iota(tests.begin(), tests.end(), 0);
  random_shuffle(tests.begin(), tests.end());
  tests.resize(min(n, 100));
  int mx = -1;
  string ans(m, '0');
  for (int id : tests) {
    vector<int> bits;
    for (int j = 0; j < m; j++) {
      if (a[id] & (1LL << j)) {
        bits.push_back(j);
      }
    }
    int h = (int) bits.size();
    vector<int> dp(1 << h, 0);
    for (int i = 0; i < n; i++) {
      int mm = 0;
      for (int j = 0; j < h; j++) {
        if (a[i] & (1LL << bits[j])) {
          mm |= (1 << j);
        }
      }
      dp[mm] += 1;
    }
    for (int j = 0; j < h; j++) {
      for (int mm = 0; mm < (1 << h); mm++) {
        if (mm & (1 << j)) {
          dp[mm & ~(1 << j)] += dp[mm];
        }
      }
    }
    for (int mm = 0; mm < (1 << h); mm++) {
      if (dp[mm] >= (n + 1) / 2 && __builtin_popcount(mm) > mx) {
        mx = __builtin_popcount(mm);
        // fill(ans.begin(), ans.end(), '0');
        ans = string(m, '0');
        for (int j = 0; j < h; j++) {
          if (mm & (1 << j)) {
            ans[bits[j]] = '1';
          }
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}