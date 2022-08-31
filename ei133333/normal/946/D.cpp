#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

int main() {
  int N, M, K;
  string S[500];

  cin >> N >> M >> K;
  for(int i = 0; i < N; i++) {
    cin >> S[i];
  }

  int all[500];
  int times[500][501];
  fill_n(*times, 500 * 501, INF);
  int need = 0;
  for(int i = 0; i < N; i++) {
    all[i] = count(begin(S[i]), end(S[i]), '1');
    times[i][all[i]] = 0;
    for(int j = 0; j < M; j++) {
      int add = 0;
      for(int k = j; k < M; k++) {
        if(S[i][k] == '1') ++add;
        times[i][all[i] - add] = min(times[i][all[i] - add], k - j + 1);
      }
    }
    int tot = times[i][0];
    need += tot;
    for(int j = 0; j <= all[i]; j++) {
      times[i][j] = tot - times[i][j];
    }
  }

  vector< int > dp(K + 1, 0);
  dp[0] = 0;
  for(int i = 0; i < N; i++) {
    for(int j = K; j >= 0; j--) {
      for(int k = 1; k <= all[i]; k++) {
        if(j + k > K) break;
        dp[j + k] = max(dp[j + k], dp[j] + times[i][k]);
      }
    }
  }

  cout << need - dp.back() << endl;
}