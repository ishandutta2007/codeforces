#include<bits/stdc++.h>

using namespace std;

#define int long long

inline int read()
{
	int res=0;
	char c=getchar();
	while(c<'0'||c>'9'){c=getchar();}
	while(c>='0'&&c<='9'){res=(res<<1)+(res<<3)+c-'0';c=getchar();}
	return res;
}

const int N=105;
int n,mod,dp[N][N*N],C[N][N],sm[N][N*N],jc[N],ans;

signed main()
{
	n=read();mod=read();
	dp[0][0]=1;
	for(int i=0;i<=n-1;++i)
		for(int j=0;j<=i*(i-1)/2;++j)
			for(int k=0;k<=i;++k)
				dp[i+1][j+k]=(dp[i+1][j+k]+dp[i][j])%mod;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=i*(i-1)/2;++j)
			for(int k=j+1;k<=i*(i-1)/2;++k)
				sm[i][k-j]=(sm[i][k-j]+dp[i][j]*dp[i][k]%mod)%mod;
	for(int i=1;i<=n;++i)
		for(int j=i*(i-1)/2;j>=0;--j)
			sm[i][j]=(sm[i][j]+sm[i][j+1])%mod;
	for(int i=0;i<=n;++i)
		for(int j=0;j<=n;++j)
			if(i==0&&j==0) C[i][j]=1;
			else C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	jc[0]=1;
	for(int i=1;i<=n;++i)
		jc[i]=jc[i-1]*i%mod;
	for(int i=0;i<=n-1;++i)
		for(int a=1;a<=n-i;++a)
			for(int b=a+1;b<=n-i;++b)
				ans=(ans+C[n][i]*jc[i]%mod*sm[n-i-1][b-a+1]%mod)%mod;
	printf("%lld\n",ans);
	return 0;
}