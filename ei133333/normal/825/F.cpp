#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

int dp[8001][8001], dp2[8001];
int sum[8001];

int main()
{
  string S;
  cin >> S;

  for(int i = S.size() - 1; i >= 0; i--) {
    for(int j = S.size() - 1; j >= 0; j--) {
      dp[i][j] = S[i] == S[j] ? dp[i + 1][j + 1] + 1 : 0;
    }
  }

  for(int i = 0; i < 8001; i++) {
    sum[i] = to_string(i).size();
  }

  fill_n(dp2, 8001, INF);
  dp2[0] = 0;
  for(int i = 0; i < S.size(); i++) {
    for(int j = 1; i + j <= S.size(); j++) {
      int mul = 1;
      for(int k = i + j; k <= S.size(); k += j) {
        if(dp[i][k - j] < j) break;
        dp2[k] = min(dp2[k], dp2[i] + sum[mul] + j);
        ++mul;
      }
    }
  }

  cout << dp2[S.size()] << endl;
}