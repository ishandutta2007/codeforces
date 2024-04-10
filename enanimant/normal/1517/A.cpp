/*
 * author:  ADMathNoob
 * created: 04/23/21 10:33:27
 * problem: https://codeforces.com/contest/1517/problem/A
 */

/*
g++ 1517A.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -Wall -Wfatal-errors -ggdb && gdb a
g++ 1517A.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -O3 -Wall -Wfatal-errors


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    if (n % 2050 != 0) {
      cout << "-1\n";
      continue;
    }
    n /= 2050;
    int ans = 0;
    while (n > 0) {
      ans += n % 10;
      n /= 10;
    }
    cout << ans << '\n';
  }
  return 0;
}