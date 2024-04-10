/*
 * author:  ADMathNoob
 * created: 07/07/21 10:37:03
 * problem: https://codeforces.com/contest/1543/problem/C
 */

/*
g++ 1543C.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1543C.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



*/

#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

double T;

double f(const vector<double>& v) {
  vector<bool> valid(3);
  int cnt = 0;
  for (int i = 0; i < 3; i++) {
    valid[i] = (v[i] > EPS);
    cnt += valid[i];
  }
  if (cnt == 1) {
    assert(valid[2]);
    return 1;
  }
  double res = v[2];
  for (int i = 0; i < 2; i++) {
    if (valid[i]) {
      vector<double> new_v = v;
      double sub = min(v[i], T);
      new_v[i] -= sub;
      for (int j = 0; j < 3; j++) {
        if (valid[j] && j != i) {
          new_v[j] += sub / (cnt - 1);
        }
      }
      res += v[i] * (1 + f(new_v));
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    double a, b, c;
    cin >> a >> b >> c >> T;
    cout.precision(10);
    cout << fixed;
    cout << f({a, b, c}) << '\n';
  }
  return 0;
}