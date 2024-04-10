// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#define here void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    array<string, 2> X;
    array<int, 2> P;
    cin >> X[0] >> P[0] >> X[1] >> P[1];
    array<int, 2> s = {int(X[0].size()) + P[0], int(X[1].size()) + P[1]};
    array<int, 2> vals = {-1, -1};
    if (s[0] != s[1]) {
      vals = s;
    } else {
      for (int i = 0; i < 2; ++i) {
        while (int(X[i].size()) < int(X[i ^ 1].size())) {
          --P[i];
          X[i] += '0';
        }
      }
      int p = 0;
      while (p < int(X[0].size()) && X[0][p] == X[1][p]) {
        ++p;
      }
      if (p < int(X[0].size())) {
        vals = {X[0][p], X[1][p]};
      }
    }
    cout << (vals[0] == vals[1] ? '=' : (vals[0] < vals[1] ? '<' : '>')) << '\n';
  }
}