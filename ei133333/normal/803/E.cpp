#include <bits/stdc++.h>

using namespace std;

int N, K;
string S;

int dp[2300][1001];
pair< int, int > nt[2301][1001];

bool rec(int sa, int tern)
{
  int &ret = dp[sa+1100][tern];
  if(~ret) return (ret);
  if(tern == N) return (abs(sa) == K);
  if(abs(sa) == K) return (false);
  if(S[tern] == '?' || S[tern] == 'L') {
    if(rec(sa - 1, tern + 1)) {
      nt[sa+1100][tern] = {sa - 1, tern + 1};
      return (ret = true);
    }
  }
  if(S[tern] == '?' || S[tern] == 'W') {
    if(rec(sa + 1, tern + 1)) {
      nt[sa+1100][tern] = {sa + 1, tern + 1};
      return (ret = true);
    }
  }
  if(S[tern] == '?' || S[tern] == 'D') {
    if(rec(sa, tern + 1)) {
      nt[sa+1100][tern] = {sa, tern + 1};
      return (ret= true);
    }
  }
  return(ret = false);
}

int main()
{
  cin >> N >> K;
  cin >> S;

  memset(dp, -1, sizeof(dp));
  if(rec(0, 0)) {
    int latte = 0, malta = 0;
    for(int i = 0; i < N; i++) {
      auto ns = nt[latte + 1100][malta];
      if(latte == ns.first) cout << "D";
      else if(latte < ns.first) cout << "W";
      else cout << "L";
      latte = ns.first;
      malta = ns.second;
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
}