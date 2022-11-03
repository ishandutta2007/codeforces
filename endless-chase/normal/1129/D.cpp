#include<bits/stdc++.h>
using namespace std;
const int magic=404,mod=998244353,maxn=100000;
int n,k,pre[111111],a[111111],cur[111111],dp[111111],b[111111];
int pr[255][222222],d[333];
void add(int &x,int y)
{
	x+=y;
	if (x<0) x+=mod;
	if (x>=mod) x-=mod;
}
void Add(int l,int r,int R)
{
	while(r>=l && r/magic==R/magic)
	{
		b[r]++;
		r--;
	}
	if (l>r) return;
	int lb=l/magic,rb=r/magic;
	if (lb==rb)
	{
		for (int i=l;i<=r;i++)
		{
			add(pr[lb][b[i]+maxn],-dp[i-1]);
			b[i]++;
		}
	}
	else
	{
		for (int i=l;i<(lb+1)*magic;i++)
		{
			add(pr[lb][b[i]+maxn],-dp[i-1]);
			b[i]++;
		}
		for (int i=rb*magic;i<=r;i++)
		{
			add(pr[rb][b[i]+maxn],-dp[i-1]);
			b[i]++;
		}
		for (int i=lb+1;i<rb;i++) 
		{
			d[i]++;
		}
	}
}
void del(int l,int r,int R)
{
	while(r>=l && r/magic==R/magic)
	{
		b[r]--;
		r--;
	}
	if (l>r) return;
	int lb=l/magic,rb=r/magic;
	if (lb==rb)
	{
		for (int i=l;i<=r;i++)
		{
			add(pr[lb][b[i]-1+maxn],dp[i-1]);
			b[i]--;
		}
	}
	else
	{
		for (int i=l;i<(lb+1)*magic;i++)
		{
			add(pr[lb][b[i]-1+maxn],dp[i-1]);
			b[i]--;
		}
		for (int i=rb*magic;i<=r;i++)
		{
			add(pr[rb][b[i]-1+maxn],dp[i-1]);
			b[i]--;
		}
		for (int i=lb+1;i<rb;i++) 
		{
			d[i]--;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=n;i++)
	{
		pre[i]=cur[a[i]];
		cur[a[i]]=i;
	}
	dp[0]=1;
	for (int i=1;i<=n;i++)
	{
		Add(pre[i]+1,i,i+1);
		if (pre[i]) del(pre[pre[i]]+1,pre[i],i+1);
		for (int j=i;j/magic==(i+1)/magic && j>0;j--)
		{
			if (b[j]<=k) add(dp[i],dp[j-1]); 
		}
		for (int j=(i+1)/magic-1;j>=0;j--)
		{
			add(dp[i],pr[j][k-d[j]+maxn]);
		}
		if ((i+1)%magic==magic-1)
		{
			for (int j=i+1;j/magic==(i+1)/magic && j>0;j--)
			{
				add(pr[j/magic][b[j]+maxn],dp[j-1]);
			}
			for (int j=1;j<=n+2;j++) add(pr[(i+1)/magic][j+maxn],pr[(i+1)/magic][j-1+maxn]);
		}
	}
	printf("%d\n",dp[n]);
	return 0;
}