/*
 * author:  ADMathNoob
 * created: 05/02/21 10:34:14
 * problem: https://codeforces.com/contest/1515/problem/A
 */

/*
g++ 1515A.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wfatal-errors -ggdb && gdb a
g++ 1515A.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wfatal-errors -O3


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, bad;
    cin >> n >> bad;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int sum = accumulate(a.begin(), a.end(), 0);
    if (sum == bad) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      int cur = 0;
      vector<int> res;
      for (int i = 0; i < n; i++) {
        if (cur + a[i] == bad) {
          assert(i < n - 1);
          res.push_back(a[i + 1]);
          res.push_back(a[i]);
          cur += a[i] + a[i + 1];
          ++i;
        } else {
          res.push_back(a[i]);
          cur += a[i];
        }
      }
      for (int i = 0; i < n; i++) {
        if (i > 0) {
          cout << ' ';
        }
        cout << res[i];
      }
      cout << '\n';
    }
  }
  return 0;
}