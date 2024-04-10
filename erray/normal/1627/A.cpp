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
    int N, M, R, C;
    cin >> N >> M >> R >> C;
    --R, --C;
    int ans = 3;    
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        char c;
        cin >> c;
        if (c == 'B') {
          ans = min(ans, 2 - (i == R) - (j == C)); 
        }
      }
    }
    cout << (ans == 3 ? -1 : ans) << '\n';
  }
}