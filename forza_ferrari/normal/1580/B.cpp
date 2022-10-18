#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k,mod,dp[101][101][101],c[101][101],fac[101];
int main()
{
    cin>>n>>m>>k>>mod;
    c[1][0]=c[1][1]=1;
    fac[0]=fac[1]=1;
    for(register int i=2;i<=n;i++)
    {
        c[i][0]=1;
        fac[i]=1ll*fac[i-1]*i%mod;
        for(register int j=1;j<=i;j++)
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    }
    for(register int i=0;i<=n;++i)
        dp[0][i][0]=1;
    for(register int i=1;i<=n;++i)
    {
        dp[i][1][1]=fac[i];
        for(register int j=i+1;j<=n;++j)
            dp[i][j][0]=fac[i];
    }
    for(register int i=1;i<=n;++i)
		for(register int j=2;j<=i;++j)
			for(register int k=0;k<=i-j+1;++k)
				for(register int pos=1;pos<=i;++pos)
                    for(register int d=0;d<=k;++d)
                        if(dp[pos-1][j-1][d]&&dp[i-pos][j-1][k-d])
					        dp[i][j][k]=(dp[i][j][k]+1ll*c[i-1][pos-1]*dp[pos-1][j-1][d]%mod*dp[i-pos][j-1][k-d]%mod)%mod;
    cout<<dp[n][m][k]<<endl;
    return 0;
}