#include<cstdio>
#include<iostream>
using namespace std;
const int N=10000010,p=1000000007;
int n,ans,num;
int a[N],mu[N],pr[N],g[N],b[N],v[N];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		a[x]++;
	}
	n=10000000;
	mu[1]=1;
	for (int i=2;i<=n;i++)
	{
		if (!v[i]) { pr[++num]=i;mu[i]=-1;}
		for (int j=1;i*pr[j]<=n&&j<=num;j++)
		if (i%pr[j]==0)
		{
			mu[i*pr[j]]=0;
			v[i*pr[j]]=1;
			break;
		}
		else
		{
			mu[i*pr[j]]=-mu[i];
			v[i*pr[j]]=1;
		}
	}
	for (int i=1;i<=n;i++)
	for (int j=2;i*j<=n;j++)
		a[i]+=a[i*j];
	for (int i=1;i<=n;i++)
	if (a[i]&&mu[i])
	for (int j=1;i*j<=n;j++)
		g[i*j]=g[i*j]+a[i]*mu[i];
	b[0]=1;
	for (int i=1;i<=n;i++) b[i]=2LL*b[i-1]%p;
	for (int i=2;i<=n;i++)
	if (g[i])
	{
		int res=0;
		for (int j=1;i*j<=n;j++) res=(res+mu[j]*(b[a[i*j]]-1))%p;
		ans=(ans+1LL*g[i]*res)%p;
	}
	ans=(ans+p)%p;
	printf("%d\n",ans);
	return 0;
}