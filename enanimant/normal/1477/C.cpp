/*
 * author:  ADMathNoob
 * created: 01/28/21 09:36:58
 * problem: https://codeforces.com/contest/1477/problem/C
 */

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1477C.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1477C.cpp -ggdb && gdb a
*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  auto Dist = [&](int i, int j) {
    long long dx = x[i] - x[j];
    long long dy = y[i] - y[j];
    return dx * dx + dy * dy;
  };
  vector<bool> used(n, false);
  vector<int> order(n);
  int v = 0;
  order[0] = v;
  used[v] = true;
  for (int i = 1; i < n; i++) {
    int far = v;
    for (int j = 0; j < n; j++) {
      if (!used[j] && Dist(v, j) > Dist(v, far)) {
        far = j;
      }
    }
    v = far;
    order[i] = v;
    used[v] = true;
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << order[i] + 1;
  }
  cout << '\n';


  return 0;
}