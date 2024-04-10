/*
 * author:  ADMathNoob
 * created: 07/07/21 10:37:03
 * problem: https://codeforces.com/contest/1543/problem/A
 */

/*
g++ 1543A.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1543A.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long a, b;
    cin >> a >> b;
    long long d = abs(a - b);
    if (d == 0) {
      cout << "0 0\n";
      continue;
    }
    long long down = b / d * d;
    long long up = (b + d - 1) / d * d;
    long long moves = min(b - down, up - b);
    cout << d << ' ' << moves << '\n';
  }
  return 0;
}