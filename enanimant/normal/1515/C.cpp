/*
 * author:  ADMathNoob
 * created: 05/02/21 10:34:14
 * problem: https://codeforces.com/contest/1515/problem/C
 */

/*
g++ 1515C.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wfatal-errors -ggdb && gdb a
g++ 1515C.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wfatal-errors -O3


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, x;
    cin >> n >> m >> x;
    set<pair<int, int>> s;
    for (int i = 0; i < m; i++) {
      s.emplace(0, i);
    }
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
      int h;
      cin >> h;
      pair<int, int> p = *s.begin();
      s.erase(s.begin());
      p.first += h;
      res[i] = p.second;
      s.insert(p);
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << ' ';
      }
      cout << res[i] + 1;
    }
    cout << '\n';
  }
  return 0;
}