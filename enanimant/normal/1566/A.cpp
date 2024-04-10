/*
 * author:  ADMathNoob
 * created: 09/12/21 10:35:15
 * problem: https://codeforces.com/contest/1566/problem/A
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
    int n, s;
    cin >> n >> s;
    int d = n / 2 + 1;
    cout << s / d << '\n';
  }
  return 0;
}