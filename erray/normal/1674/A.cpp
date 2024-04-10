// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
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
    if (Y % X != 0) {
      cout << "0 0\n";
    } else {
      cout << 1 << ' ' << Y / X << '\n';
    }
  }
}