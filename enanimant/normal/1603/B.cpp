/*
 * author:  ADMathNoob
 * created: 10/30/21 10:35:21
 * problem: https://codeforces.com/contest/1603/problem/B
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int x, y;
    cin >> x >> y;
    long long a = x / 2;
    long long b = y / 2;
    long long n;
    if (b < a) {
      n = 2 * a + 2 * b;
    } else {
      int q = b / a;
      int r = b % a;
      n = 2 * q * a + r;
    }
    cout << n << '\n';
    assert(n % x == y % n);
  }
  return 0;
}