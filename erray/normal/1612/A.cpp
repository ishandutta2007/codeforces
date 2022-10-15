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
    int X, Y;
    cin >> X >> Y;
    if (X % 2 != Y % 2) {
      cout << -1 << ' ' << -1 << '\n';
    } else {
      cout << (X / 2) << ' ' << (Y + 1) / 2 << '\n';
    }
  }
}