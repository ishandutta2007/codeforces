#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=2005,K=11,mod=1e9+7;
int n,k,a,dp[N][(1<<K)+5];

int main()
{
	n=read();k=read();
	dp[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		a=read();
		for(int j=0;j<=(1<<k);++j)
		{
			if(a==2||a==0)
				dp[i][min(j+2,1<<k)]=(dp[i][min(j+2,1<<k)]+dp[i-1][j])%mod;
			if(a==4||a==0)
			{
				if(j%4==2)
					dp[i][4]=(dp[i][4]+dp[i-1][j])%mod;
				else
					dp[i][min(j+4,1<<k)]=(dp[i][min(j+4,1<<k)]+dp[i-1][j])%mod;
			}
		}
	}
	printf("%d",dp[n][1<<k]);
	return 0;
}