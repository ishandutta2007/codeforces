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
    string S;
    cin >> N >> S;
    for (int i = 0; i < int(S.size()) - 1; ++i) {
      if (S[i] == '0' && S[i + 1] == '0') {
        S.insert(S.begin() + i + 1, '1');
      } 
    }
    int ans = int(S.size()) - N;
    for (int i = 1; i < int(S.size()) - 1; ++i) {
      if (S[i] == '1' && S[i - 1] == '0' && S[i + 1] == '0') {
        ans += 1;
      }
    }
    cout << ans << '\n';
  }
}