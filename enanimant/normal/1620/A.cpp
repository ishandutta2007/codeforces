/*
 * author:  ADMathNoob
 * created: 12/18/21 10:35:18
 * problem: https://codeforces.com/contest/1620/problem/A
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
    string s;
    cin >> s;
    cout << (count(s.begin(), s.end(), 'N') != 1 ? "YES" : "NO") << '\n';
  }
  return 0;
}