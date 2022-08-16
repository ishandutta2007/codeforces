#include<bits/stdc++.h>
using namespace std;

int N;
string S;
int dp[100000][3][3];

int rec(int idx, int isend, int prev)
{
  int& it = dp[idx][isend][prev];
  if(idx == N) {
    return(0);
  } else if(~it) {
    return(it);
  } if(isend == 2) {
    if(S[idx] != prev) {
      return(it = rec(idx + 1, 2, !prev) + 1);
    } else {
      return(it = rec(idx + 1, 2, prev));
    }
  } else if(isend == 1) {
    if(S[idx] == prev) {
      return(it = rec(idx + 1, 1, !prev) + 1);
    } else {
      return(it = max(rec(idx + 1, 1, prev), rec(idx, 2, prev)));
    }
  } else {
    if(S[idx] != prev) {
      return(it = rec(idx + 1, 0, !prev) + 1);
    } else {
      return(it = max(rec(idx + 1, 0, prev), rec(idx, 1, prev)));
    }
  }
}

int main()
{
  memset(dp, -1, sizeof(dp));

  cin >> N;
  cin >> S;
  for(int i = 0; i < S.size(); i++) S[i] -= '0';
  cout << rec(0, 0, !S[0]) << endl;
}