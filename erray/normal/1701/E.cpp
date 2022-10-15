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
    int N, M;
    string S, T;
    cin >> N >> M >> S >> T;
    vector<vector<int>> match(N + 1, vector<int>(M + 1));
    for (int i = N - 1; i >= 0; --i) {
      for (int j = M - 1; j >= 0; --j) {
        match[i][j] = (S[i] == T[j] ? match[i + 1][j + 1] + 1 : 0);
      }
    }
    vector<int> fs(M);
    {
      int p = 0;
      for (int i = 0; i < M; ++i) {
        while (p < N && S[p] != T[i]) {
          ++p;
        }
        fs[i] = p;
        ++p;
      }
    }
    vector<int> fe(M);
    {
      int p = N - 1;
      for (int i = M - 1; i >= 0; --i) {
        while (p >= 0 && S[p] != T[i]) {
          --p;
        }
        fe[i] = p;
        --p;
      }
    }
    int ans = N - match[0][0];
    for (int i = 1; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (match[i][j] > 0 && fs[j] <= i && (j + match[i][j] == M || fe[j + match[i][j]] >= i + match[i][j])) {
          ans = min(ans, N - match[i][j] + (i - j) + 1);
        }
      }
    }
    if (fs[M - 1] >= N) {
      cout << -1 << '\n';
    } else {
      cout << ans << '\n';
    }
  }
}