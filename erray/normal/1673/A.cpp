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
    if (int(S.size()) == 1) {
      cout << "Bob " << int(S[0] - 'a' + 1) << '\n';
    } else {
      if (S[0] > S.back()) {
        swap(S.front(), S.back());
      }
      int ans = (S[0] - 'a' + 1) * (int(S.size()) % 2 ? -1 : 1);
      for (int i = 1; i < int(S.size()); ++i) {
        ans += S[i] - 'a' + 1;
      }
      cout << "Alice " << ans << '\n';
    }
  }
}