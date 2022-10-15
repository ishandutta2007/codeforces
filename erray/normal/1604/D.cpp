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
  int tt;
  cin >> tt;
  while (tt--) {
    int X, Y;
    cin >> X >> Y;
    int ans;
    if (X == Y) {
      ans = X;
    } else if (X >= Y) {
      ans = X + Y;
    } else {
      int M = Y % X;
      ans = Y - M / 2;
    }
    cout << ans << '\n';
  }
}