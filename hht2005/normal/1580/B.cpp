#include<bits/stdc++.h>
using namespace std;
int mod,n,M,K;
int f[110][110][110],C[110][110];
int dfs(int i,int j,int k) {
	if(f[i][j][k]!=-1)return f[i][j][k];
	if(k<=1&&j!=1)return 0;
	if(j>i)return 0;
	if(j==1&&k==1) {
		f[i][1][1]=1;
		for(int j=1;j<=i;j++)
			f[i][1][1]=1ll*f[i][1][1]*j%mod;
		return f[i][1][1];
	}
	f[i][j][k]=0;
	for(int a=1;a<=i;a++)
		for(int x=max(j+a-i,0);x<=j&&x<=a;x++)
			f[i][j][k]=(f[i][j][k]+1ll*C[i-1][a-1]*dfs(a-1,x,k-1)%mod*dfs(i-a,j-x,k-1))%mod;
	return f[i][j][k];
}
int main() {
	memset(f,-1,sizeof(f));
	scanf("%d%d%d%d",&n,&M,&K,&mod);
	C[0][0]=1;
	for(int i=1;i<=n;i++) {
		C[i][0]=C[i][i]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	memset(f[0],0,sizeof(f[0]));
	for(int i=0;i<=n;i++)
		f[0][0][i]=1;
	printf("%d\n",dfs(n,K,M));
	return 0;
}