/*
 * author:  ADMathNoob
 * created: 07/17/21 10:32:12
 * problem: https://codeforces.com/contest/1530/problem/A
 */

/*
g++ 1530A.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1530A.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int ans = 0;
    for (char c : s) {
      ans = max(ans, (int) (c - '0'));
    }
    cout << ans << '\n';
  }
  return 0;
}