#include<bits/stdc++.h>
using namespace std;
const int N=55;
int dp[N][N*N],sum[N*N],f[N],s[N][N*N],C[N][N],fac[N],mod;
int main() {
	int n;
	scanf("%d%d",&n,&mod);
	sum[0]=dp[0][0]=1;
	fac[0]=1;
	for(int i=0;i<=n;i++) {
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	for(int i=1;i<=n;i++) {
		fac[i]=1ll*i*fac[i-1]%mod;
		for(int j=0;j<=i*(i-1)/2;j++)
			dp[i][j]=(sum[j]-((j>=i)?sum[j-i]:0)+mod)%mod;
		sum[0]=dp[i][0];
		for(int j=1;j<=(i+1)*i/2;j++)
			sum[j]=(sum[j-1]+dp[i][j])%mod;
	}//asaf
	for(int i=2;i<=n;i++) {
		memset(s,0,sizeof(s));
		for(int j=i;j>=1;j--)
			for(int k=0;k<=(i-1)*(i-2)/2;k++) {
				if(k+j>=2)s[j][k+j-1]=(0ll+s[j+1][k+j-1]+s[j][k+j-2]-s[j+1][k+j-2]+dp[i-1][k]+mod)%mod;
				else s[j][k+j-1]=(0ll+s[j+1][k+j-1]+dp[i-1][k]+mod)%mod;
			}
		for(int j=1;j<=i;j++)
			for(int k=0;k<=(i-1)*(i-2)/2;k++)
				if(k+j>=2)f[i]=(f[i]+1ll*s[j+1][k+j-2]*dp[i-1][k])%mod;
	}
	int ans=0;
	for(int i=0;i<=n;i++)
		ans=(ans+1ll*f[n-i]*C[n][i]%mod*fac[i])%mod;
	printf("%d\n",ans);
	return 0;
}