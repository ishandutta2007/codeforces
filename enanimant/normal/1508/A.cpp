/*
 * author:  ADMathNoob
 * created: 05/02/21 09:52:13
 * problem: https://codeforces.com/contest/1508/problem/A
 */

/*
g++ 1508A.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wfatal-errors -ggdb && gdb a
g++ 1508A.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wfatal-errors -O3


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
    vector<string> s(3);
    for (int i = 0; i < 3; i++) {
      cin >> s[i];
    }
    vector<int> ptr(3, 0);
    string res = "";
    while (count(ptr.begin(), ptr.end(), 2 * n) == 0) {
      vector<int> cnt(2, 0);
      for (int i = 0; i < 3; i++) {
        cnt[s[i][ptr[i]] - '0'] += 1;
      }
      int add = (cnt[0] > cnt[1] ? 0 : 1);
      for (int i = 0; i < 3; i++) {
        if (s[i][ptr[i]] - '0' == add) {
          ++ptr[i];
        }
      }
      res += (char) ('0' + add);
    }
    if (count(ptr.begin(), ptr.end(), 2 * n) == 1) {
      int mx = -1;
      int bid = -1;
      for (int i = 0; i < 3; i++) {
        if (ptr[i] != 2 * n && ptr[i] > mx) {
          mx = ptr[i];
          bid = i;
        }
      }
      res += s[bid].substr(ptr[bid]);
    }
    assert((int) res.size() <= 3 * n);
    cout << res << '\n';
  }
  return 0;
}