#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
const int N=1000010;
int n,m,num;
int a[N],c[N],v[N],pr[N],mu[N];
int main()
{
	scanf("%d%d",&n,&m);
	mu[1]=1;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=2;i<=500000;i++)
	{
		if (!v[i]) pr[++num]=i,mu[i]=-1;
		for (int j=1;i*pr[j]<=500000&&j<=num;j++)
		if (i%pr[j]==0)
		{
			v[i*pr[j]]=1;
			mu[i*pr[j]]=0;
			break;
		}
		else
		{
			v[i*pr[j]]=1;
			mu[i*pr[j]]=-mu[i];
		}
	}
	for (int i=1;i<=n;i++) v[i]=0;
	LL ans=0,cnt=0;
	while (m--)
	{
		int x,d;
		scanf("%d",&x);
		if (v[x]) d=-1;else d=1;
		v[x]^=1;
		x=a[x];
		if (x==1) cnt+=d;
		for (int i=1;i*i<=x;i++)
		if (x%i==0)
		{
			int j=i;
			ans-=1LL*mu[j]*c[j]*c[j];
			c[j]+=d;
			ans+=1LL*mu[j]*c[j]*c[j];
			if (i*i==x) continue;
			
			j=x/i;
			ans-=1LL*mu[j]*c[j]*c[j];
			c[j]+=d;
			ans+=1LL*mu[j]*c[j]*c[j];
		}
		printf("%I64d\n",(ans-cnt)/2);
	}
	return 0;
}