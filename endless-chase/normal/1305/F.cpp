#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const int maxn=1000000,maxt=88;
int n,prime[1111111],cnt,ans,cur,x,fuck;
long long a[222222];
bool f[1111111],timup,used[222222];
double tt;
void Init()
{
	for (int i=2;i<=maxn;i++)
	{
		if (!f[i])
		{
			prime[++cnt]=i;
		}
		for (int j=1;j<=cnt && i*prime[j]<=maxn;j++)
		{
			f[i*prime[j]]=1;
			if (i%prime[j]==0) break;
		}
	}
}
int Get(int x)
{
	return ((rand()<<10)+rand())%x+1;
}
long long eval(long long x)
{
	long long res=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]<x) res+=(x-a[i]);
		else res+=min(a[i]%x,x-(a[i]%x));
	}
	return res;
}
void calc(long long x)
{
	long long cur;
	for (int i=1;i<=cnt;i++)
	{
		if (x==1) break;
		if (x%prime[i]==0)
		{
			if (i>88)
			{
				cur=eval(prime[i]);
				if (cur<ans) ans=cur;
			}
			while(x%prime[i]==0)
			{
				x/=prime[i];
			}
		}
	}
	if (x!=1) 
	{
		cur=eval(x);
		if (cur<ans) ans=cur;
	}
}
int main()
{
	srand(time(0));
	tt=clock();
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
	{
		scanf("%lld",&a[i]);
	}
	Init();
	ans=1e9;
	for (int i=1;i<=maxt;i++)
	{
		cur=0;
		for (int j=1;j<=n;j++)
		{
			if (a[j]<prime[i]) cur+=(prime[i]-a[j]);
			else cur+=min(a[j]%prime[i],prime[i]-a[j]%prime[i]);
		}
		ans=min(ans,cur);
	}
	while(fuck<n && fuck<200)
	{
		x=Get(n);
		while(used[x]) x=Get(n);
		used[x]=1;
		for (long long i=max(1ll,a[x]-10);i<=a[x]+10;i++)
		{
			if ((clock()-tt)/CLOCKS_PER_SEC>2.2)
			{
				timup=1;
				break;
			}
			calc(i);
		}
		if (timup) break;
		fuck++;
	}
	printf("%d\n",ans);
	return Accepted;
}