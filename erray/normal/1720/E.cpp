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
  vector<vector<int>> A(N, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> A[i][j];
      --A[i][j];
    }
  }
  vector<array<int, 2>> ri(N * N, {N, -1});
  vector<array<int, 2>> rj(N * N, {N, -1});
  vector<int> ct(N * N);
  int uq = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      int x = A[i][j];
      uq += (ct[x] == 0);
      ct[x] += 1;
      ri[x][0] = min(ri[x][0], i);
      ri[x][1] = max(ri[x][1], i);
      rj[x][0] = min(rj[x][0], j);
      rj[x][1] = max(rj[x][1], j);
    }
  }
  debug(ri, rj);
  if (uq <= K) {
    cout << K - uq << '\n';
    return 0;
  }
  bool one = false;
  for (int len = 1; len <= N; ++len) {
    vector<vector<int>> sum(N + 1, vector<int>(N + 1));
    debug(len);
    for (int i = 0; i < N * N; ++i) {
      if (ct[i] && max(ri[i][1] - ri[i][0], rj[i][1] - rj[i][0]) < len) {
        int ai = ri[i][0];
        int aj = rj[i][0];
        int di = ri[i][1] - len;
        int dj = rj[i][1] - len;
        debug(i, ai, aj, di, dj);
        sum[ai][aj] += 1;
        if (di >= 0 && dj >= 0) {
          sum[di][dj] += 1;
        }
        if (di >= 0) {
          sum[di][aj] -= 1;
        }
        if (dj >= 0) {
          sum[ai][dj] -= 1;
        }
      }
    }
    for (int i = N - 1; i >= 0; --i) {
      for (int j = N - 1; j >= 0; --j) {
        sum[i][j] += sum[i + 1][j] + sum[i][j + 1] - sum[i + 1][j + 1];
        if (i + len <= N && j + len <= N) {
          one |= (sum[i][j] == uq - K) || (sum[i][j] == uq - K + 1);
        }
      }
    }
    debug(sum);
  }
  cout << (one ? 1 : 2) << '\n';
}