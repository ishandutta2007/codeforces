/*
 * author:  ADMathNoob
 * created: 04/21/21 09:48:16
 * problem: https://codeforces.com/contest/1516/problem/A
 */

/*
g++ 1516A.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -Wall -Wfatal-errors -ggdb && gdb a
g++ 1516A.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -O3 -Wall -Wfatal-errors


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
      int moves = min(a[i], k);
      a[i] -= moves;
      a[n - 1] += moves;
      k -= moves;
    }
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << ' ';
      }
      cout << a[i];
    }
    cout << '\n';
  }
  return 0;
}