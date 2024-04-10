#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=400;

int n,mod;

void into(){
  scanf("%d%d",&n,&mod);
}

int c[N+9][N+9],sum[N+9];

void Get_c(){
  c[0][0]=1;
  for (int i=1;i<=n;++i){
	c[i][0]=c[i][i]=1;
	for (int j=1;j<i;++j) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
  }
  for (int i=1;i<=n;++i)
	for (int j=1;j<=i;++j) sum[i]=(sum[i]+c[i-1][j-1])%mod;
}

int dp[N+9][N+9][2],ans;

void Get_dp(){
  dp[0][0][0]=1;
  for (int i=1;i<=n;++i)
	for (int j=0;j<=i;++j){
	  dp[i][j][0]=dp[i-1][j][1];
	  for (int k=1;k<=j;++k)
		dp[i][j][1]=(dp[i][j][1]+1LL*dp[i-k][j-k][0]*sum[k]%mod*c[j][k])%mod;
	  //printf("%d %d : %d %d\n",i,j,dp[i][j][0],dp[i][j][1]);
	}
  for (int i=0;i<=n;++i) ans=(ans+dp[n][i][1])%mod;
}

void work(){
  Get_c();
  Get_dp();
}

void outo(){
  printf("%d\n",ans);
}

int main(){
  int T=1;
  //scanf("%d",&T);
  for (;T--;){
    into();
    work();
    outo();
  }
  return 0;
}