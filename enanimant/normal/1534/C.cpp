/*
 * author:  ADMathNoob
 * created: 06/13/21 11:35:03
 * problem: https://codeforces.com/contest/1534/problem/C
 */

/*
g++ 1534C.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1534C.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



*/

#include <bits/stdc++.h>

using namespace std;

const int md = (int) 1e9 + 7;

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
      --a[i];
    }
    vector<int> succ(n);
    for (int i = 0; i < n; i++) {
      int b;
      cin >> b;
      --b;
      succ[a[i]] = b;
    }
    int ans = 1;
    vector<bool> was(n, false);
    for (int i = 0; i < n; i++) {
      if (!was[i]) {
        int u = i;
        while (!was[u]) {
          was[u] = true;
          u = succ[u];
        }
        ans = ans * 2 % md;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}