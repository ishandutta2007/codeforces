/*
 * author:  ADMathNoob
 * created: 04/16/21 10:34:21
 * problem: https://codeforces.com/contest/1508/problem/B
 */

/*
g++ 1508B.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -Wall -Wfatal-errors -ggdb && gdb a
g++ 1508B.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -O3 -Wall -Wfatal-errors


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
    long long k;
    cin >> n >> k;
    k -= 1;
    vector<bool> down(n - 1);
    for (int i = n - 2; i >= 0; i--) {
      down[i] = (k & 1);
      k >>= 1;
    }
    if (k > 0) {
      cout << "-1\n";
      continue;
    }
    vector<int> ret(n);
    iota(ret.begin(), ret.end(), 0);
    for (int i = 0; i < n; i++) {
      int r = i;
      while (r < n - 1 && down[r]) {
        r += 1;
      }
      reverse(ret.begin() + i, ret.begin() + r + 1);
      i = r;
    }
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << ' ';
      }
      cout << ret[i] + 1;
    }
    cout << '\n';
  }
  return 0;
}