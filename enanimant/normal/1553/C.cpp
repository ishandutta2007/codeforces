/*
 * author:  ADMathNoob
 * created: 07/22/21 10:35:08
 * problem: https://codeforces.com/contest/1553/problem/C
 */

/*
g++ 1553C.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1553C.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  const int n = 10;
  vector<int> score(n);
  while (tt--) {
    string s;
    cin >> s;
    int ans = n;
    for (int mm = 0; mm < (1 << n); mm++) {
      bool match = true;
      for (int i = 0; i < n; i++) {
        score[i] = ((mm >> i) & 1);
        if (s[i] != '?' && (int) (s[i] - '0') != score[i]) {
          match = false;
        }
      }
      if (match) {
        vector<int> p(2);
        int cnt = 10;
        for (int i = 0; i < n / 2; i++) {
          if (score[2 * i]) {
            p[0] += 1;
          }
          if (p[0] + (4 - i) < p[1] || p[1] + (5 - i) < p[0]) {
            cnt = 2 * i + 1;
            break;
          }
          if (score[2 * i + 1]) {
            p[1] += 1;
          }
          if (p[0] + (4 - i) < p[1] || p[1] + (4 - i) < p[0]) {
            cnt = 2 * i + 2;
            break;
          }
        }
        ans = min(ans, cnt);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}