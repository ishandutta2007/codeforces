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
    int N, X, Y;
    cin >> N >> X >> Y;
    if (((X != 0) ^ (Y != 0) ^ 1) || ((N - 1) % max(X, Y) != 0)) {
      cout << -1 << '\n';
    } else {
      int k = max(X, Y);
      int c = 0;
      int p = 0;
      for (int i = 0; i < N - 1; ++i) {
        if (i % k == 0) {
          p = i;
        }
        cout << p + 2 << ' ';
      }
      cout << '\n';
    }
  }
}