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
    int mx = __lg(N - 1);
    for (int i = 1; i < (1 << mx); ++i) {
      cout << i << ' ';
    }
    cout << 0 << ' ';
    for (int i = (1 << mx); i < N; ++i) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}