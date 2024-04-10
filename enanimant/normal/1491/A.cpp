/*
 * author:  ADMathNoob
 * created: 02/28/21 08:33:49
 * problem: https://codeforces.com/contest/1491/problem/A
 */

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1491A.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1491A.cpp -ggdb && gdb a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -O3 -Wall -Wfatal-errors 1491A.cpp && a


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

  int n, tt;
  cin >> n >> tt;
  vector<int> a(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  while (tt--) {
    int op, x;
    cin >> op >> x;
    if (op == 1) {
      --x;
      sum -= a[x];
      a[x] ^= 1;
      sum += a[x];
    } else {
      cout << (sum >= x ? 1 : 0) << '\n';
    }
  }

  return 0;
}