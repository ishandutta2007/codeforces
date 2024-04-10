/*
 * author:  ADMathNoob
 * created: 05/02/21 10:34:14
 * problem: https://codeforces.com/contest/1515/problem/B
 */

/*
g++ 1515B.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wfatal-errors -ggdb && gdb a
g++ 1515B.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wfatal-errors -O3


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
    if (n % 2 == 1) {
      cout << "NO\n";
      continue;
    }
    n /= 2;
    bool ok = false;
    int k = (int) sqrt(n);
    ok |= (k * k == n);
    if (n % 2 == 0) {
      n /= 2;
      int k = (int) sqrt(n);
      ok |= (k * k == n);
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}