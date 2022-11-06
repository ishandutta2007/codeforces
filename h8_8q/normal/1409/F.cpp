#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
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

const int N=205;
int n,k,dp[2][N][N][N][3],ans;
char s[N],t[N];

signed main()
{
	n=read();k=read();
	scanf("%s%s",s+1,t+1);
	if(t[1]==t[2])
	{
		int sum=0;
		for(int i=1;i<=n;++i)
			if(s[i]==t[1])
				sum++;
		sum+=min(k,n-sum);
		ans=sum*(sum-1)/2;
		printf("%d\n",ans);
		return 0;
	}
	for(register int j=0;j<=k;++j)
		for(register int l=0;l<=n;++l)
			for(register int r=0;l+r<=n;++r)
			{
				dp[0][j][l][r][0]=-1e8;
				dp[1][j][l][r][0]=-1e8;
				dp[0][j][l][r][1]=-1e8;
				dp[1][j][l][r][1]=-1e8;
				dp[0][j][l][r][2]=-1e8;
				dp[1][j][l][r][2]=-1e8;
			}
	dp[0][0][0][0][0]=0;
	dp[0][0][0][0][1]=0;
	dp[0][0][0][0][2]=0;
	for(register int i=1;i<=n;++i)
	{
		for(register int j=0;j<=min(i,k);++j)
			for(register int l=0;l<=i;++l)
				for(register int r=0;l+r<=i;++r)
				{
					if(s[i]!=t[1]&&s[i]!=t[2])
						dp[i&1][j][l][r][0]=max(dp[i&1][j][l][r][0],max(max(dp[(i-1)&1][j][l][r][1],dp[(i-1)&1][j][l][r][2]),dp[(i-1)&1][j][l][r][0]));
					else if(j-1>=0)
						dp[i&1][j][l][r][0]=max(dp[i&1][j][l][r][0],max(max(dp[(i-1)&1][j-1][l][r][1],dp[(i-1)&1][j-1][l][r][2]),dp[(i-1)&1][j-1][l][r][0]));
					if(s[i]==t[1]&&l-1>=0)
						dp[i&1][j][l][r][1]=max(dp[i&1][j][l][r][1],max(max(dp[(i-1)&1][j][l-1][r][1],dp[(i-1)&1][j][l-1][r][2]),dp[(i-1)&1][j][l-1][r][0]));
					else if(j-1>=0&&l-1>=0)
						dp[i&1][j][l][r][1]=max(dp[i&1][j][l][r][1],max(max(dp[(i-1)&1][j-1][l-1][r][1],dp[(i-1)&1][j-1][l-1][r][2]),dp[(i-1)&1][j-1][l-1][r][0]));
					if(s[i]==t[2]&&r-1>=0)
						dp[i&1][j][l][r][2]=max(dp[i&1][j][l][r][2],max(max(dp[(i-1)&1][j][l][r-1][1],dp[(i-1)&1][j][l][r-1][2]),dp[(i-1)&1][j][l][r-1][0])+l);
					else if(j-1>=0&&r-1>=0)
						dp[i&1][j][l][r][2]=max(dp[i&1][j][l][r][2],max(max(dp[(i-1)&1][j-1][l][r-1][1],dp[(i-1)&1][j-1][l][r-1][2]),dp[(i-1)&1][j-1][l][r-1][0])+l);
					ans=max(ans,dp[i&1][j][l][r][0]);
					ans=max(ans,dp[i&1][j][l][r][1]);
					ans=max(ans,dp[i&1][j][l][r][2]);
				}
		for(register int j=0;j<=min(i,k);++j)
			for(register int l=0;l<=i;++l)
				for(register int r=0;l+r<=i;++r)
				{
					dp[(i-1)&1][j][l][r][0]=-1e8;
					dp[(i-1)&1][j][l][r][1]=-1e8;
					dp[(i-1)&1][j][l][r][2]=-1e8;
				}
					
	}
		
	printf("%d\n",ans);
	return 0;
}