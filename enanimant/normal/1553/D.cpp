/*
 * author:  ADMathNoob
 * created: 07/22/21 10:35:08
 * problem: https://codeforces.com/contest/1553/problem/D
 */

/*
g++ 1553D.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1553D.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s, t;
    cin >> s >> t;
    int n = (int) s.size();
    int m = (int) t.size();
    if (n % 2 != m % 2) {
      s.erase(s.begin());
      n -= 1;
    }
    int at = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == t[at]) {
        ++at;
        if (at == m) {
          break;
        }
      } else {
        ++i;
      }
    }
    cout << (at == m ? "YES" : "NO") << '\n';
  }
  return 0;
}