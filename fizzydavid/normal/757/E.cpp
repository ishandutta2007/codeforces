//by yjz
#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
inline int getnum()
{
	register int r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
inline void putnum(int x)
{
	if(x<0)putchar('-'),x=-x;
	register char a[10]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
int n,q,dp[1000111][20];
int p[100111],pn,mxcnt[1000111],pre[1000111];
bool np[1000111];
int main()
{
	dp[0][0]=1;
	for(int i=1;i<20;i++)dp[0][i]=2;
	for(int i=1;i<=1000000;i++)
	{
		dp[i][0]=1;
		for(int j=1;j<20;j++)
		{
			dp[i][j]=dp[i][j-1]+dp[i-1][j];
			dp[i][j]=dp[i][j]>=mod?dp[i][j]-mod:dp[i][j];
		}
	}
	np[1]=1;
	for(int i=2;i<=1000000;i++)
	{
		if(!np[i])
		{
			p[pn++]=i;
			pre[i]=1;
			mxcnt[i]=1;
		}
		for(int j=0;j<pn&&i*p[j]<=1000000;j++)
		{
			np[i*p[j]]=1;
			pre[i*p[j]]=pre[i]*p[j];
			mxcnt[i*p[j]]=mxcnt[i];
			if(i%p[j]==0)
			{
				if(pre[i]==1)
				{
					pre[i*p[j]]=1;
					mxcnt[i*p[j]]=mxcnt[i]+1;
				}
				break;
			}
		}
	}
	n=getnum();
	for(int i=1;i<=n;i++)
	{
		int x=getnum(),y=getnum(),ans=1;
		while(y>1)
		{
			ans=1ll*ans*dp[x][mxcnt[y]]%mod;
			y=pre[y];
		}
		putnum(ans);puts("");
	}
	return 0;
}