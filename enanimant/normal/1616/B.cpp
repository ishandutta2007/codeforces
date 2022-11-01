/*
 * author:  ADMathNoob
 * created: 12/29/21 10:35:14
 * problem: https://codeforces.com/contest/1616/problem/B
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
    int n;
    string s;
    cin >> n >> s;
    if (n == 1) {
      cout << s + s << '\n';
      continue;
    }
    if (s[0] == s[1]) {
      cout << s[0] << s[0] << '\n';
      continue;
    }
    int b = 0;
    while (b < n - 1 && s[b] >= s[b + 1]) {
      ++b;
    }
    string t = s.substr(0, b + 1);
    string rev = t;
    reverse(rev.begin(), rev.end());
    cout << t << rev << '\n';
  }
  return 0;
}