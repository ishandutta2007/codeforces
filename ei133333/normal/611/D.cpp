#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1 << 30;

string S;
int dp[5005][5005];
int sum[5005][5005];
bool on[5005][5005];

int main()
{
  int N;
  cin >> N;
  cin >> S;


  for(int i = N - 1; i >= 0; i--) {
    for(int j = 0; j < N; j++) {
      if(S[i] != S[j]) sum[i][j] = 0;
      else sum[i][j] = sum[i + 1][j + 1] + 1;
    }
  }
  for(int i = 0; i < N; i++) {
    for(int j = 1; j <= N; j++) {
      if(i + j + j > N) {
        on[i][j] = false;
      } else {
        int dist = sum[i][i + j];
        if(S[i] == '0' || S[i + j] == '0' || i + j + dist >= i + j + j) on[i][j] = false;
        else on[i][j] = S[i + dist] < S[i + j + dist];
      }
    }
  }

  int ret = 0;
  for(int j = N - 1; j >= 0; j--) {
    if(S[j] == '0') continue;
    dp[j][N] = 1;
    for(int i = N - 1; i >= 0; i--) (dp[j][i] += dp[j][i + 1]) %= MOD;
    for(int i = j - 1; i >= 0; i--) {
      if(S[i] == '0' || j + j - i > N) continue;
      (dp[i][j] += dp[j][j + j - i - on[i][j - i] + 1]) %= MOD;
    }
  }
  cout << dp[0][0] << endl;
}