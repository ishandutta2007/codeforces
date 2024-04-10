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
    string S;
    cin >> N >> M >> S;
    vector<int> ans(N * M);
    {
      vector<bool> col(M);
      int cur = 0;
      for (int i = 0; i < N * M; ++i) {
        ans[i] = ans[i - !!i];
        if (!col[cur] && S[i] == '1') {
          col[cur] = true;
          ans[i] += 1;
        }
        (cur += 1) %= M;
      }
    }
    debug(ans);

    vector<int> row(N * M);
    int sum = 0;
    for (int i = 0; i < N * M; ++i) {
      if (i >= M) {
  			sum -= S[i - M] == '1';
        row[i] = row[i - M];
      }
      sum += S[i] == '1';
      if (sum > 0) {
        row[i] += 1;
      }
    }
    debug(row);
    for (int i = 0; i < N * M; ++i) {
      ans[i] += row[i];
    }

    for (int i = 0; i < N * M; ++i) {
      cout << ans[i] << " \n"[i == N * M - 1];
    }
  }
}