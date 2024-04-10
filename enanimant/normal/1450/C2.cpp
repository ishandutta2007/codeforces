// December 6, 2020
// https://codeforces.com/contest/1450/problem/C

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1450C.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1450C.cpp -ggdb && gdb a
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


  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    int k = 0;
    vector<int> xs(3, 0), os(3, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int c = (i + j) % 3;
        if (s[i][j] == 'X') {
          xs[c] += 1;
          k += 1;
        }
        if (s[i][j] == 'O') {
          os[c] += 1;
          k += 1;
        }
      }
    }
    bool found = false;
    for (int d = 0; d < 3; d++) {
      for (int e = 0; e < 3; e++) {
        if (d == e || found) {
          continue;
        }
        if (xs[d] + os[e] <= k / 3) {
          for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
              if ((i + j) % 3 == d && s[i][j] == 'X') {
                s[i][j] = 'O';
              }
              if ((i + j) % 3 == e && s[i][j] == 'O') {
                s[i][j] = 'X';
              }
            }
          }
          found = true;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      cout << s[i] << '\n';
    }
  }


  return 0;
}