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
    if (N == 3) {
      cout << -1 << '\n';
      continue;
    }
    for (int i = 0; i < N; ++i) {
      cout << (i + 1 + (N > 2)) % N + 1 << " \n"[i == N - 1];
    }
  }
}