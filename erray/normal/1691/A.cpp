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
    array<int, 2> ct = {};
    for (int i = 0; i < N; ++i) {
      int X;
      cin >> X;
      ct[X % 2] += 1;
    }
    cout << min(ct[0], ct[1]) << '\n';
  }
}