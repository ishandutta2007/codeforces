/*
 * author:  ADMathNoob
 * created: 02/17/21 22:26:34
 * problem: https://codeforces.com/contest/1485/problem/D
 */

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1485D.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1485D.cpp -ggdb && gdb a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -O3 -Wall -Wfatal-errors 1485D.cpp && a


*/

#include <bits/stdc++.h>

using namespace std;

const int A = 16;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif

  int L = 1;
  for (int i = 1; i <= A; i++) {
    L = L / __gcd(L, i) * i;
  }
  vector<int> diff(A + 1, -1);
  for (int d = 1; d <= A; d++) {
    int b = 1;
    while (true) {
      int p = b * b * b * b;
      if ((L - p) % d == 0) {
        diff[d] = p;
        break;
      }
      b += 1;
    }
  }

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int a;
      cin >> a;
      if (j > 0) {
        cout << ' ';
      }
      if ((i + j) % 2 == 0) {
        cout << L;
      } else {
        cout << L - diff[a];
      }
    }
    cout << '\n';
  }

  return 0;
}