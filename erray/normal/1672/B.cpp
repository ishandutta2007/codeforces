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
    int n = int(S.size());
    bool ok = (S[n - 1] == 'B');
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += (S[i] == 'A' ? +1 : -1);
      ok &= (sum >= 0);
    }

    cout << (ok ? "Yes" : "No") << '\n';
  }
}