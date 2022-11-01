/*
 * author:  ADMathNoob
 * created: 11/28/21 09:35:14
 * problem: https://codeforces.com/contest/1609/problem/B
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, tt;
  cin >> n >> tt;
  string s;
  cin >> s;
  int cnt = 0;
  auto Check = [&](int i) -> int {
    return (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c');
  };
  for (int i = 0; i < n - 2; i++) {
    cnt += Check(i);
  }
  while (tt--) {
    int i;
    char c;
    cin >> i >> c;
    --i;
    for (int j = i - 2; j <= i; j++) {
      if (0 <= j && j < n - 2) {
        cnt -= Check(j);
      }
    }
    s[i] = c;
    for (int j = i - 2; j <= i; j++) {
      if (0 <= j && j < n - 2) {
        cnt += Check(j);
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}