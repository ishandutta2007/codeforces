/*
 * author:  ADMathNoob
 * created: 05/02/21 10:34:14
 * problem: https://codeforces.com/contest/1515/problem/D
 */

/*
g++ 1515D.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wfatal-errors -ggdb && gdb a
g++ 1515D.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wfatal-errors -O3


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
      cin >> c[i];
      --c[i];
    }
    if (l < r) {
      swap(l, r);
      reverse(c.begin(), c.end());
    }
    vector<int> cntL(n), cntR(n);
    for (int i = 0; i < l; i++) {
      cntL[c[i]] += 1;
    }
    for (int i = l; i < n; i++) {
      cntR[c[i]] += 1;
    }
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
      q.emplace(cntL[i] - cntR[i], i);
    }
    int side_changes = l - n / 2;
    for (int it = 0; it < side_changes; it++) {
      pair<int, int> p = q.top();
      q.pop();
      int i = p.second;
      cntL[i] -= 1;
      cntR[i] += 1;
      q.emplace(cntL[i] - cntR[i], i);
    }
    int ans = side_changes;
    int add = 0;
    for (int i = 0; i < n; i++) {
      add += abs(cntL[i] - cntR[i]);
    }
    add /= 2;
    ans += add;
    cout << ans << '\n';
  }
  return 0;
}