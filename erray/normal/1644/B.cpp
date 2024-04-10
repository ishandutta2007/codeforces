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
    int N;
    cin >> N;
    for (int j = 0; j < N; ++j) {
      int p = N;
      for (int i = N - 1; i >= 0; --i) {
        if (i == j) {
          cout << 1 << ' ';
        } else {
          cout << p << ' ';
          --p;
        }
      }
      cout << '\n';
    }
  }
}