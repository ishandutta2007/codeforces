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
    cin >> N;
    vector<vector<int>> mat(N, vector<int>(N));
    vector<vector<bool>> use(N, vector<bool>(N));
    const int di[] = {0, 0, +1, -1}, dj[] = {1, -1, 0, 0};
    vector<array<int, 2>> all;
    for (int i = 0; i < N; ++i) {
      for (int j = (i == 0); j < N; ++j) {
        all.push_back({i, j});
      }
    }
    sort(all.begin(), all.end(), [&](auto x, auto y) {
      return pair{x[0] + x[1], x[0]} < pair{y[0] + y[1], y[0]};
    });

    for (auto[i, j] : all) {
      if((i == 0 ? mat[i][j - 1] : mat[i - 1][j]) == 0) {
        use[i][j] = true;
        for (int d = 0; d < 4; ++d) {
          int ni = i + di[d];
          int nj = j + dj[d];
          if (ni >= 0 && ni < N && nj >= 0 && nj < N) { 
            mat[ni][nj] ^= 1;
          }
        }
      }
    }



    int ans = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        int X;
        cin >> X;
        ans ^= X * use[i][j];
      }
    }
    cout << ans << '\n';
  }
}