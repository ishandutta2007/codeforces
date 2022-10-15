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
  int N, K;
  cin >> N >> K;
  vector<int> B(N);
  for (int i = 0; i < N; ++i) {
    cin >> B[i];
  }
  
  vector<vector<int>> g(3, vector<int>(30));
  for (int xr = 0; xr < 3; ++xr) {
    for (int pw = 0; pw < 30; ++pw) {
      int n = N - 1 - pw - xr;
      int l = K - xr;
      for (int i = max(0, l); i <= n; ++i) {
        g[xr][pw] ^= ((i & n) == i);
      }
    }
  }

  debug(g);
  const int M = (1 << 20);
  vector<int> ans(M);
  for (int i = 0; i < N; ++i) {
    long long c = B[i];
    for (int j = i; j < N; ++j) {
      if (j != i) {
        if (B[j] > 20 || (1LL << B[j]) * c >= M) {
          break;
        }
        c *= 1LL << B[j];
      }

      int d = (i != 0) + (j != N - 1);
      debug(i, j, c, d, g[d][j - i]);
      ans[c] ^= g[d][j - i];
    }
  }

  int p = M - 1;
  while (p >= 0 && ans[p] == 0) {
    --p;
  }
  if (p == -1) {
    cout << 0 << '\n';
  } else {
    for (int i = p; i >= 0; --i) {
      cout << ans[i];
    }
  }
}