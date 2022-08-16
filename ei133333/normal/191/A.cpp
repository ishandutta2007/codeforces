#include <bits/stdc++.h>

using namespace std;


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  string S[500000];

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> S[i];
  }

  int dp[26][26];
  memset(dp, -1, sizeof(dp));

  for(int i = 0; i < N; i++) {
    auto s = S[i].front() - 'a';
    auto t = S[i].back() - 'a';
    const int sz = S[i].size();
    for(int j = 0; j < 26; j++) {
      if(~dp[j][s]) dp[j][t] = max(dp[j][t], dp[j][s] + sz);
    }
    dp[s][t] = max(dp[s][t], sz);
  }

  int ret = 0;
  for(int i = 0; i < 26;i++) {
    ret = max(ret, dp[i][i]);
  }
  cout << ret << endl;
}