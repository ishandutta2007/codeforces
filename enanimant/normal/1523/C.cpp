/*
 * author:  ADMathNoob
 * created: 05/30/21 10:33:09
 * problem: https://codeforces.com/contest/1523/problem/C
 */

/*
g++ 1523C.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1523C.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



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
    vector<int> stk;
    for (int i = 0; i < n; i++) {
      if (a[i] == 1) {
        stk.push_back(1);
      } else {
        while (!stk.empty() && stk.back() != a[i] - 1) {
          stk.pop_back();
        }
        assert(!stk.empty());
        stk.back() = a[i];
      }
      for (int j = 0; j < (int) stk.size(); j++) {
        if (j > 0) {
          cout << '.';
        }
        cout << stk[j];
      }
      cout << '\n';
    }
  }
  return 0;
}