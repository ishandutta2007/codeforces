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
  int TT;
  cin >> TT;
  while (TT--) {
    int N, K;
    cin >> N >> K;
    if (K > (N + 1) / 2) {
      cout << -1 << '\n';
      continue;
    }
    vector<string> ans(N, string(N, '.'));
    for (int i = 0; i < K; ++i) {
      ans[i * 2][i * 2] = 'R';
    }
    for (auto e : ans) {
      cout << e << '\n';
    }
  }
}