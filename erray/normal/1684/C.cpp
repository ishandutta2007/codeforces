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
    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        cin >> A[i][j];
      }
    }

    int x = -1, y = -1;
    for (int i = 0; i < N; ++i) {
      auto sa = A[i];
      sort(sa.begin(), sa.end());
      for (int j = 0; j < M; ++j) {
        if (sa[j] != A[i][j]) {
          (x == -1 ? x : y) = j;
        }
      }
      if (x != -1) {
        assert(y != -1);
        debug(x, y);
        for (int j = 0; j < N; ++j) {
          swap(A[j][x], A[j][y]);
        }
        break;
      }
    }

    bool ok = true;
    for (int i = 0; i < N; ++i) {
      ok &= is_sorted(A[i].begin(), A[i].end());
    }
    if (!ok) {
      cout << -1 << '\n';
    } else {
      if (x == -1) {
        x = y = 0;
      }           
      cout << x + 1 << ' ' << y + 1 << '\n';
    }
  }
}