#include<bits/stdc++.h>
using namespace std;

const int N=200,mod=1000000007;

int add(int a,int b,int p=mod){return a+b>=p?a+b-p:a+b;}
int sub(int a,int b,int p=mod){return a-b<0?a-b+p:a-b;}
int mul(int a,int b,int p=mod){return 1LL*a*b%p;}
void sadd(int &a,int b,int p=mod){a=add(a,b,p);}
void ssub(int &a,int b,int p=mod){a=sub(a,b,p);}
void smul(int &a,int b,int p=mod){a=mul(a,b,p);}

int n,m;

void into(){
  scanf("%d%d",&n,&m);
}

int inv[N+9],fac[N+9],ifac[N+9],c[N*2+9][N+9];

void Get_c(){
  inv[1]=1;
  fac[0]=fac[1]=1;
  ifac[0]=ifac[1]=1;
  for (int i=2;i<=m+1;++i){
	inv[i]=mul(mod-mod/i,inv[mod%i]);
	fac[i]=mul(fac[i-1],i);
	ifac[i]=mul(ifac[i-1],inv[i]);
  }
  for (int i=0;i<=m<<1;++i)
	for (int j=0;j<=m+1;++j){
	  if (i>n) continue;
	  c[i][j]=1;
	  for (int k=0;k<j;++k) smul(c[i][j],1LL*(mod+n-i-k)*inv[k+1]%mod);
	  //printf("c %d %d : %d\n",i,j,c[i][j]);
	}
}

int dp[N+9][N+9],ans[N+9];

void Get_dp(){
  dp[0][0]=1;
  for (int i=1;i<=m;++i)
	for (int j=1;j<=m;++j)
	  for (int k=1;k<=j;++k) sadd(dp[i][j],mul(mul(c[j-k+i-1][k+1],dp[i-1][j-k]),fac[k]));
  ans[0]=1;
  for (int i=1;i<=m;++i){
	ans[i]=i>1?ans[i-2]:0;
	for (int j=1;j<=i;++j) sadd(ans[i],mul(dp[j][i],ifac[j]));//,printf("dp %d %d : %d\n",j,i,dp[j][i]);
  }
}

void work(){
  Get_c();
  Get_dp();
}

void outo(){
  for (int i=1;i<=m;++i)
	printf("%d ",ans[i]);
  puts("");
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