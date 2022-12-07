#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int Mod=998244353;
const int M=505;
int n,opt[M],x[M],dp[M][M];

signed main()
{
	n=read();int ans=0;
	for (int i=1;i<=n;i++)
	{
		string s;cin>>s;
		if (s=="+")x[i]=read(),opt[i]=1;
	}
	for (int i=1;i<=n;i++)
	{
		if (opt[i]==0)continue;
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for (int j=1;j<i;j++)
		{
			if (opt[j]==1)
			{
				if (x[j]>x[i])
					for (int k=0;k<=n;k++)
						dp[j][k]=dp[j-1][k]*2%Mod;
				else
				{
					for (int k=0;k<=n;k++)dp[j][k]=dp[j-1][k];
					for (int k=1;k<=n;k++)dp[j][k]=(dp[j][k]+dp[j-1][k-1])%Mod;
				}
			}
			else
			{
				for (int k=0;k<=n;k++)dp[j][k]=dp[j-1][k];
				for (int k=0;k<=n;k++)dp[j][k]=(dp[j][k]+dp[j-1][k+1])%Mod;
				dp[j][0]=(dp[j][0]+dp[j-1][0])%Mod; 
			}
		}
		for (int j=0;j<=n;j++)
			dp[i][j]=dp[i-1][j];
		for (int j=i+1;j<=n;j++)
		{
			if (opt[j]==1)
			{
				if (x[j]>=x[i])
					for (int k=0;k<=n;k++)
						dp[j][k]=dp[j-1][k]*2%Mod;
				else
				{
					for (int k=0;k<=n;k++)dp[j][k]=dp[j-1][k];
					for (int k=1;k<=n;k++)dp[j][k]=(dp[j][k]+dp[j-1][k-1])%Mod;
				}
			}
			else
			{
				for (int k=0;k<=n;k++)dp[j][k]=dp[j-1][k];
				for (int k=0;k<=n;k++)dp[j][k]=(dp[j][k]+dp[j-1][k+1])%Mod;
			}
		}int cnt=0;
		for (int j=0;j<=n;j++)cnt=(cnt+dp[n][j])%Mod;
		ans=(ans+cnt*x[i])%Mod;
	}cout<<ans<<endl; 
	return 0;
}