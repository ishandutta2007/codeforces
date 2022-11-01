/*
 * author:  ADMathNoob
 * created: 06/13/21 11:35:03
 * problem: https://codeforces.com/contest/1534/problem/B
 */

/*
g++ 1534B.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1534B.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



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
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
        int new_ai = max(a[i - 1], a[i + 1]);
        ans += a[i] - new_ai;
        a[i] = new_ai;
      }
    }
    for (int i = 0; i <= n; i++) {
      ans += abs(a[i + 1] - a[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}