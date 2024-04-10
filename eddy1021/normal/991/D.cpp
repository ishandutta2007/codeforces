#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=111;
char c[2][N];
int dp[N][2][2];
int main(){
  scanf("%s", c[0]+1);
  scanf("%s", c[1]+1);
  int n=strlen(c[0]+1);
  for(int i=0; i<=n; i++)
    for(int j1=0; j1<2; j1++)
      for(int j2=0; j2<2; j2++)
        dp[i][j1][j2]=-1e6;
  dp[0][1][1]=0;
  for(int i=0; i<n; i++)
    for(int j1=0; j1<2; j1++)
      for(int j2=0; j2<2; j2++){
        int val=dp[i][j1][j2];
        int nj1=c[0][i+1]=='X';
        int nj2=c[1][i+1]=='X';
        {
          int& to=dp[i+1][nj1][nj2];
          to=max(to, val);
        }
        if(j1==0 and j2==0 and nj1==0){
          int& to=dp[i+1][1][nj2];
          to=max(to, val+1);
        }
        if(j1==0 and j2==0 and nj2==0){
          int& to=dp[i+1][nj1][1];
          to=max(to, val+1);
        }
        if(j1==0 and nj1==0 and nj2==0){
          int& to=dp[i+1][1][1];
          to=max(to, val+1);
        }
        if(j2==0 and nj1==0 and nj2==0){
          int& to=dp[i+1][1][1];
          to=max(to, val+1);
        }
      }
  int ans=0;
  for(int i=0; i<2; i++)
    for(int j=0; j<2; j++)
      ans=max(ans, dp[n][i][j]);
  cout<<ans<<endl;
}