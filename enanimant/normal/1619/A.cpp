/*
 * author:  ADMathNoob
 * created: 12/24/21 09:33:38
 * problem: https://codeforces.com/contest/1619/problem/A
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
    int n = s.size();
    if (n % 2 == 0 && s.substr(0, n / 2) == s.substr(n / 2)) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}