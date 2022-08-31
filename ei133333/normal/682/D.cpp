#include <bits/stdc++.h>
using namespace std;

int N, M, K;
string S, T;
int LCP[1006][1006];
int dp[1006][1006][10];

int rec(int S_begin, int T_begin, int dec)
{
  if(dec == -1) return(0);
  if(S_begin >= S.size() || T_begin >= T.size()) return(-11451419);
  if(~dp[S_begin][T_begin][dec]) return(dp[S_begin][T_begin][dec]);
  int ret = max(rec(S_begin + 1, T_begin, dec), rec(S_begin, T_begin + 1, dec));
  for(int i = 1; i <= LCP[S_begin][T_begin] && dec - i >= -1; i++) {
    ret = max(ret, rec(S_begin + LCP[S_begin][T_begin], T_begin + LCP[S_begin][T_begin], dec - i) + LCP[S_begin][T_begin]);
  }
  return(dp[S_begin][T_begin][dec] = ret);
}

int main()
{
  memset(dp, -1, sizeof(dp));
  cin >> N >> M >> K; 
  cin >> S >> T;
  for(int i = S.size() - 1; i >= 0; i--) {
    for(int j = T.size() - 1; j >= 0; j--) {
      LCP[i][j] = S[i] == T[j] ? LCP[i + 1][j + 1] + 1 : 0;
    }
  }
  cout << rec(0, 0, K - 1) << endl;
}