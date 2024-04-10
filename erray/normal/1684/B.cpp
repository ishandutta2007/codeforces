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
    int A, B, C;
    cin >> A >> B >> C;
    cout << (long long) 1e9 * B + A << ' ' << B << ' ' << C << '\n';
  }
}