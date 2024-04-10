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
    int N, M;
    cin >> N >> M;
    vector<int> X(N);
    for (int i = 0; i < N; ++i) {
      cin >> X[i];
    }

    vector<vector<bool>> A(N, vector<bool>(M));
    for (int i = 0; i < N; ++i) {
      string S;
      cin >> S;
      for (int j = 0; j < M; ++j) {
        A[i][j] = S[j] == '1';
      }
    }

    int mx = -1;
    vector<int> ans;
    for (int mask = 0; mask < (1 << N); ++mask) {
      vector<int> ct(M);
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
          ct[j] += (((mask >> i) & 1) ? 1 : -1) * A[i][j];
        }
      }
      vector<vector<int>> srt(N * 2 + 1);
      for (int i = 0; i < M; ++i) {
        srt[ct[i] + N].push_back(i);
      }

      int p = 0;
      vector<int> res(M);
      for (int i = 0; i <= N * 2; ++i) {
        for (auto e : srt[i]) {
          ++p;
          res[e] = p;
        }
      } 
      vector<int> sum(N);
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
          sum[i] += A[i][j] * res[j];
        }
      }

      bool ok = true;
      int tot = 0;
      for (int i = 0; i < N; ++i) {
        int diff = sum[i] - X[i];
        if (mask == 7) {
          debug(diff);
          debug(ok);
        }
        ok &= (diff == 0 || ((diff > 0) == ((mask >> i) & 1)));
        tot += abs(sum[i] - X[i]);
      }

      debug(bitset<4>(mask), res, sum, X, ok, tot);
      if (ok && mx < tot) {
        mx = tot;
        swap(ans, res);
        debug(mask, ans, sum, tot);
      }
    }
    for (auto e : ans) {
      cout << e << ' ';
    }
    cout << '\n';

  }
}