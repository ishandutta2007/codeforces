/*
 * author:  ADMathNoob
 * created: 04/03/21 10:33:29
 * problem: https://codeforces.com/contest/1503/problem/B
 */

/*
g++ 1503B.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -Wall -Wfatal-errors -ggdb && gdb a
g++ 1503B.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -O3 -Wall -Wfatal-errors


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  // ios::sync_with_stdio(0);
  // cin.tie(0);
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> cells(2);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cells[(i + j) % 2].emplace_back(i, j);
    }
  }
  for (int it = 0; it < n * n; it++) {
    int forbid;
    cin >> forbid;
    --forbid;
    int take, color;
    if (forbid == 2) {
      take = (!cells[0].empty() ? 0 : 1);
      color = take;
    } else {
      if (!cells[forbid ^ 1].empty()) {
        take = color = (forbid ^ 1);
      } else {
        take = forbid;
        color = 2;
      }
    }
    int i, j;
    tie(i, j) = cells[take].back();
    cells[take].pop_back();
    cout << color + 1 << ' ' << i + 1 << ' ' << j + 1 << '\n';
  }
  return 0;
}