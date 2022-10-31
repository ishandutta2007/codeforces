#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
const int N=100010;
int n,cnt;
LL v[N],d[N],p[N];
int ans[N],vis[N];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld%lld%lld",&v[i],&d[i],&p[i]);
	for (int i=1;i<=n;i++)
	if (p[i]>=0)
	{
		for (int j=i+1;j<=n;j++)
		if (p[j]>=0)
		{
			p[j]-=v[i];
			if (p[j]<0) vis[j]=1;
			v[i]--;
			if (v[i]==0) break;
		}
		cnt++;ans[cnt]=i;
		for (int j=i+1;j<=n;j++)
		if (vis[j])
		{
			for (int k=j+1;k<=n;k++)
			if (p[k]>=0)
			{
				p[k]-=d[j];
				if (p[k]<0) vis[k]=1;
			}
			vis[j]=0;
		}
	}
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++) printf("%d ",ans[i]);printf("\n");
	return 0;
}