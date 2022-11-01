/*
 * author:  ADMathNoob
 * created: 06/25/21 11:41:57
 * problem: https://codeforces.com/contest/1540/problem/A
 */

/*
g++ 1540A.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1540A.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



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
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
      cin >> d[i];
    }
    sort(d.begin(), d.end());
    long long ans = d[n - 1];
    for (int i = 0; i < n; i++) {
      long long L = i;
      long long R = n - 1 - i;
      ans += (R - L) * d[i];
    }
    cout << ans << '\n';
  }
  return 0;
}