#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,mod,f[105][105][105],vst[105][105][105],C[105][105],jc[105];
int dp(int n,int m,int k){
	if(vst[n][m][k])return f[n][m][k];
	if(k>n)return 0;
	if(m>n)return k==0?jc[n]:0;
	if(m==1)return k==1?jc[n]:0;
	if(n==1||n==0)return 1;
	if(k>n-m+1)return 0;
	vst[n][m][k]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			f[n][m][k]=(f[n][m][k]+1ll*dp(i-1,m-1,j)*dp(n-i,m-1,k-j)%mod*C[n-1][i-1])%mod;
		}
	}
	return f[n][m][k];
}
int main(){
	cin>>n>>m>>k>>mod,C[0][0]=1%mod,jc[0]=1%mod;
	for(int i=1;i<=n;i++){
		C[i][0]=1%mod,jc[i]=1ll*jc[i-1]*i%mod;
		for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	cout<<dp(n,m,k);
}