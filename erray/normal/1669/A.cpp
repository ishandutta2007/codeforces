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
    int r[] = {1400, 1600, 1900};
    int X;
    cin >> X;
    cout << "Division " << 4 - int(lower_bound(r, r + 3, X + 1) - r) << '\n';
  }
}