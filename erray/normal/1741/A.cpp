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
    string a, b;
    cin >> a >> b;
    auto C = [&](string x) {
      if (x == "M") {
        return 0;
      }
      return int(x.size()) * (x.back() == 'L' ? 1 : -1);
    };
    cout << (C(a) == C(b) ? "=" : (C(a) < C(b) ? "<" : ">")) << '\n';
  }
}