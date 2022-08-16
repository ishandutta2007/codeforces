#include<bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;


int lcp[5000][5000];
int dp[5001];

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  string S;
  cin >> S;


  for(int i = S.size() - 1; i >= 0; i--) {
    for(int j = S.size() - 1; j >= 0; j--) {
      lcp[i][j] = S[i] == S[j] ? lcp[i + 1][j + 1] + 1 : 0;
    }
  }

  fill_n(dp, 5001, INF);
  dp[0] = 0;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      lcp[i][j] += j;
    }
  }

  for(int j = 0; j < N; j++) {
    int st = -INF;
    for(int i = 0; i < N; i++) {
      st = max(st, lcp[i][j]);
      lcp[i][j] = st;
    }
  }

  auto check = [&](int l, int r) {
    if(2 * l - r < 0) return false;
    return lcp[2 * l - r][l] >= r;
  };

  for(int i = 0; i <= N; i++) {
    for(int j = i + 1; j <= N; j++) {
      if(check(i, j)) dp[j] = min(dp[j], dp[i] + B);
      if(i + 1 == j) dp[j] = min(dp[j], dp[i] + A);
    }
  }
  cout << dp[N] << endl;
}