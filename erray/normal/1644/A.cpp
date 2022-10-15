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
    vector<int> pos(256);
    for (int i = 0; i < int(S.size()); ++i) {
      pos[S[i]] = i;
    }
    bool ok = true;
    for (auto c : {'r', 'g', 'b'}) {
      ok &= (pos[c] < pos[c + ('A' - 'a')]);
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}