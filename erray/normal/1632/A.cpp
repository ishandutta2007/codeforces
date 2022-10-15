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
    if (int(S.size()) > 2 || (int(S.size()) == 2 && S[0] == S[1])) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}