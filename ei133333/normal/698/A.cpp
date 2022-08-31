#include<bits/stdc++.h>
using namespace std;

int N, A[100];
int dp[100][5];

int rec(int idx, int prev)
{
  if(idx == N) return(0);
  if(~dp[idx][prev]) return(dp[idx][prev]);
  int ret = rec(idx + 1, 0) + 1;
  if(A[idx] == 1 || A[idx] == 3) {
    if(prev != 1) ret = min(ret, rec(idx + 1, 1));
  }
  if(A[idx] == 2 || A[idx] == 3) {
    if(prev != 2) ret = min(ret, rec(idx + 1, 2));
  }
  return(dp[idx][prev] = ret);
}
int main()
{
  memset(dp, -1, sizeof(dp));
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  cout << rec(0, 0) << endl;
}