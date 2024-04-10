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
    string S;
    cin >> S;
    cout << (S[0] - 'a') * 25 + (1 + S[1] - 'a' - (S[0] < S[1])) << '\n';
  }
}