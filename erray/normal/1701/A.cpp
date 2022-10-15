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
    int c = 0;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        int X;
        cin >> X;
        c += X;
      }
    }
    if (c == 0) {
      cout << 0 << '\n';
    } else if (c <= 3) {
      cout << 1 << '\n';
    } else {
      cout << 2 << '\n';
    }
  }
}