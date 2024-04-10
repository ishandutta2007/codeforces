/*
 * author:  ADMathNoob
 * created: 08/24/21 10:35:10
 * problem: https://codeforces.com/contest/1558/problem/A
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
    int a, b;
    cin >> a >> b;
    if (a < b) {
      swap(a, b);
    }
    vector<int> res;
    if ((a + b) % 2 == 0) {
      int low = (a - b) / 2;
      int high = (a + 3 * b) / 2;
      for (int i = low; i <= high; i += 2) {
        res.push_back(i);
      }
    } else {
      int low = (a + b - (2 * b + 1)) / 2;
      int high = 2 * b + 1 + low;
      for (int i = low; i <= high; i++) {
        res.push_back(i);
      }
    }
    cout << res.size() << '\n';
    for (int i = 0; i < (int) res.size(); i++) {
      if (i > 0) {
        cout << ' ';
      }
      cout << res[i];
    }
    cout << '\n';
  }
  return 0;
}