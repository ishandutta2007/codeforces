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
    int N, K, R, C;
    cin >> N >> K >> R >> C;
    --R, --C;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        cout << ((i + j - R - C) % K == 0 ? 'X' : '.');
      }
      cout << '\n';
    }
  }
}