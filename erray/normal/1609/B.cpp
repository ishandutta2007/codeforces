// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#define here void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, Q;
  cin >> N >> Q;
  string S(N, '*');
  int ans = 0;
  auto Add = [&](int x, char c) {
    debug(x, c);
    auto C = [&] {
      for (int i = -2; i < 1; ++i) {
        int pos = x + i;
        if (pos >= 0 && pos < N - 2 && S.substr(pos, 3) == "abc"s) {
          debug(pos, S);
          return true;
        }  
      }
      return false;
    };
    ans -= C();
    S[x] = c;
    ans += C();
  };

  for (int i = 0; i < N; ++i) {
    char C;
    cin >> C;
    Add(i, C);
  }

  while (Q--) {
    int P;
    char C;
    cin >> P >> C;
    --P;
    Add(P, C);
    cout << ans << '\n';
  }
}