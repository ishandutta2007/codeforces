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
    string foo, T;
    cin >> foo >> T;
    int n = int(foo.size());
    if (count(T.begin(), T.end(), 'a') > 0) {
      cout << (int(T.size()) == 1 ? 1 : -1) << '\n';
    } else {
      cout << (1LL << n) << '\n';
    }
  }
}