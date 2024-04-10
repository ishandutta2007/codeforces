/*
 * author:  ADMathNoob
 * created: 05/30/21 10:33:09
 * problem: https://codeforces.com/contest/1523/problem/B
 */

/*
g++ 1523B.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1523B.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> start = a;
    vector<tuple<int, int, int>> ret;
    auto Do = [&](int op, int i, int j) {
      ret.emplace_back(op, i, j);
      if (op == 1) {
        a[i] += a[j];
      } else {
        assert(op == 2);
        a[j] -= a[i];
      }
    };
    for (int i = 0; i < n; i += 2) {
      int j = i + 1;
      Do(1, i, j);
      Do(2, i, j);
      Do(1, i, j);
      Do(1, i, j);
      Do(2, i, j);
      Do(1, i, j);
    }
    for (int i = 0; i < n; i++) {
      assert(a[i] == -start[i]);
    }
    cout << ret.size() << '\n';
    for (const auto& t : ret) {
      int op, i, j;
      tie(op, i, j) = t;
      cout << op << ' ' << i + 1 << ' ' << j + 1 << '\n';
    }
  }
  return 0;
}