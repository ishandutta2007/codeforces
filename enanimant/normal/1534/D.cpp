/*
 * author:  ADMathNoob
 * created: 06/13/21 11:35:03
 * problem: https://codeforces.com/contest/1534/problem/D
 */

/*
g++ 1534D.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1534D.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



*/

#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> ret;

vector<int> Ask(int v) {
  cout << "? " << v + 1 << endl;
  vector<int> d(n);
  for (int i = 0; i < n; i++) {
    cin >> d[i];
    if (d[i] == 1) {
      ret.push_back(minmax(v, i));
    }
  }
  return d;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  vector<int> d = Ask(0);
  int k0 = 0, k1 = 0;
  for (int i = 0; i < n; i++) {
    if (d[i] % 2 == 0) {
      k0 += 1;
    } else {
      k1 += 1;
    }
  }
  if (k0 <= (n + 1) / 2) {
    for (int i = 1; i < n; i++) {
      if (d[i] % 2 == 0) {
        Ask(i);
      }
    }
  } else {
    ret.clear();
    for (int i = 0; i < n; i++) {
      if (d[i] % 2 == 1) {
        Ask(i);
      }
    }
  }
  sort(ret.begin(), ret.end());
  ret.resize(unique(ret.begin(), ret.end()) - ret.begin());
  assert((int) ret.size() == n - 1);
  cout << "!" << endl;
  for (const auto& e : ret) {
    cout << e.first + 1 << ' ' << e.second + 1 << endl;
  }
  return 0;
}