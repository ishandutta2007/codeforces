#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct rec{int d,c,p,kd;};
const int inf=1200000,M=100010;
typedef long long LL;
int n,m,k;
rec a[M];
int g[M];
LL f[M];
int cmp(rec a,rec b)
{
	if (a.d!=b.d) return a.d<b.d;
	return a.kd<b.kd;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d%d%d",&a[i].d,&x,&y,&a[i].c);
		if (x==0) a[i].p=y,a[i].kd=1;
		else      a[i].p=x,a[i].kd=0;
	}
	sort(a+1,a+1+m,cmp);
	for (int i=1;i<=n;i++) g[i]=inf;
	LL now=1LL*inf*n;f[0]=now;
	int cnt=0;
	for (int i=1;i<=m;i++)
	if (a[i].kd==0)
	{
		now-=g[a[i].p];
		if (g[a[i].p]==inf) cnt++;
		g[a[i].p]=min(g[a[i].p],a[i].c);
		now+=g[a[i].p];
		if (cnt==n) f[i]=now;
		else f[i]=1LL*inf*n;
	}
	for (int i=1;i<=m;i++) 	if (f[i]==0) f[i]=f[i-1];
	for (int i=1;i<=n;i++) g[i]=inf;
	LL ans=2LL*inf*n;
 now=1LL*inf*n;cnt=0;
	for (int i=m,j=m;i>=1;i--)
	if (a[i].kd==1)
	{
		now-=g[a[i].p];
		if (g[a[i].p]==inf) cnt++;
		g[a[i].p]=min(g[a[i].p],a[i].c);
		now+=g[a[i].p];
		while (a[i].d-a[j].d<=k&&j>=1) j--;
		if (j==0) break;
		if (f[j]<1LL*inf*n&&cnt==n) ans=min(ans,now+f[j]);
	}
	if (ans==2LL*inf*n) ans=-1;
	cout<<ans<<endl;
	return 0;
}