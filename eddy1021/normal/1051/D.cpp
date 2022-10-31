#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=998244353;
const int N=1021;
int n, k;
int dp[2][2][N+N];
void add_to(int& to, int val){
  to=(to+val)%mod;
}
int main(){
  cin>>n>>k;
  dp[1][0][1]=2;
  dp[1][1][2]=2;
  for(int i=1; i<n; i++){
    int cur=i&1, nxt=1^cur;
    for(int j=0; j<2; j++)
      for(int k=0; k<=i+i+2; k++)
        dp[nxt][j][k]=0;
    for(int df=0; df<2; df++)
      for(int cp=0; cp<=i+i; cp++){
        int val=dp[cur][df][cp];
        if(df == 0){
          // 0 0, 0 0, 0 1, 0 1
          // 0 0  0 1  0 0  0 1
          add_to(dp[nxt][0][cp], val);
          add_to(dp[nxt][0][cp+1], val);
          add_to(dp[nxt][1][cp+1], (val+val)%mod);
        }else{
          // 0 0, 0 0, 0 1, 0 1
          // 1 0  1 1  1 0  1 1
          add_to(dp[nxt][0][cp], (val+val)%mod);
          add_to(dp[nxt][1][cp], val);
          add_to(dp[nxt][1][cp+2], val);
        }
      }
  }
  int ans=(dp[n&1][0][k]+dp[n&1][1][k])%mod;
  cout<<ans<<endl;
}