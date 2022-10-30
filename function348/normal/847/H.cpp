#include<cstdio>
#include<iostream>
using namespace std;
int a[101000];
int n;
long long f[101000],g[101000];
long long ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	long long cnt=0,now=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]>now) now=a[i];
		else cnt+=now+1-a[i],now++;
		f[i+1]+=cnt;
		g[i+1]=now+1;
	}
	cnt=now=0;
	for (int i=n;i>=1;i--)
	{
		if (a[i]>now) now=a[i];
		else cnt+=now+1-a[i],now++;
		f[i-1]+=cnt;
		g[i-1]=max(g[i-1],now+1);
	}
	ans=1LL<<60;
	for (int i=1;i<=n;i++)
		ans=min(ans,f[i]+max(g[i]-a[i],0LL));
	cout<<ans;
	return 0;
}