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
    cin >> N >> M;
    //even, really?
    int mat[2][2] = {{0, 1}, {1, 0}};
    vector<vector<int>> ans(N, vector<int>(M));
    for (int i = 0; i < N; i += 2) {
      for (int j = 0; j < M; j += 2) {
        for (int ii = 0; ii < 2; ++ii) {
          for (int jj = 0; jj < 2; ++jj) {
            ans[i + ii][j + jj] = mat[ii][jj] ^ (((i / 2) + (j / 2)) % 2);
          }
        }
      }
    }
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        cout << ans[i][j] << " \n"[j == M - 1];
      }
    }
  }
}