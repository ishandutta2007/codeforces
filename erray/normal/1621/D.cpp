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
    int N;
    cin >> N;
    vector<vector<int>> val(N * 2, vector<int>(N * 2));
    for (int i = 0; i < N * 2; ++i) {
      for (int j = 0; j < N * 2; ++j) {
        cin >> val[i][j];
      }
    }

    long long start = 0;
    array<vector<vector<int>>, 2> mats;
    for (int m = 0; m < 2; ++m) {
      mats[m].resize(N, vector<int>(N));
      for (int i = 0; i < N * 2; ++i) {
        for (int j = 0; j < N * 2; ++j) {
          if ((i < N) == (j < N)) {
            start += val[i][j];
            val[i][j] = 0;
          } else if ((i < N) == m) {
            mats[m][i - N * (m ^ 1)][j - N * m] = val[i][j];                                  
          }
        }
      }
    }
    int ans = int(1e9) + 1;
    for (auto mat : mats) {
      for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
          ans = min(ans, mat[(N - 1 + i) % N][(N - 1 + j) % N]);
        }
      }
    }
    cout << start + ans << '\n';
  }
}