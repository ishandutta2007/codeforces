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
    vector<int> ct(256);
    for (char c : S) {
      ct[c] += 1;
    }
    int p = 0;
    while (ct[S[p]] > 1) {
      --ct[S[p]];
      ++p;
    }
    cout << S.substr(p) << '\n';
  }
}