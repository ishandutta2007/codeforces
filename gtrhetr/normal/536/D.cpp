#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define inf 2333333333333333333LL

struct node { int t,v,next; }a[200010];

priority_queue<pll,vector<pll>,greater<pll> > q;
pii d[2010];

ll num[2010],dis[2010],h[2010];
ll f[2010][2010][2],sum[2010][2010],s1[2010][2010],s2[2010][2010],mx[2010],mn[2010];
int cnt[2010][2010],c1[2010][2010],c2[2010][2010],head[2010],lst1[2010],lst2[2010],n,m,vs,vt,tt,t1,t2,tot;

inline int rd()
{
	int x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

inline void add(int x,int y,int z) { a[++tot].t=y;a[tot].v=z;a[tot].next=head[x];head[x]=tot; }

inline void dijkstra(int vs)
{
	while (!q.empty()) q.pop();
	for (int i=1;i<=n;i++) dis[i]=inf;
	dis[vs]=0;q.push(pll(dis[vs],vs));
	while (!q.empty())
	{
		pll hh=q.top();q.pop();
		int x=hh.second;
		if (dis[x]<hh.first) continue;
		for (int i=head[x];i;i=a[i].next)
		{
			int t=a[i].t;
			if (dis[t]>dis[x]+a[i].v) dis[t]=dis[x]+a[i].v,q.push(pll(dis[t],t));
		}
	}
	tt=0;
	for (int i=1;i<=n;i++) h[++tt]=dis[i];
	sort(h+1,h+tt+1);
	tt=unique(h+1,h+tt+1)-h-1;
	for (int i=1;i<=n;i++) dis[i]=lower_bound(h+1,h+tt+1,dis[i])-h;
}

int main()
{
	n=rd();m=rd();vs=rd();vt=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	for (int i=1;i<=m;i++) { int x=rd(),y=rd(),z=rd();add(x,y,z);add(y,x,z); }
	dijkstra(vs);t1=tt;
	for (int i=1;i<=n;i++) d[i].first=dis[i];
	dijkstra(vt);t2=tt;
	for (int i=1;i<=n;i++) d[i].second=dis[i];
	for (int i=1;i<=n;i++) sum[d[i].first][d[i].second]+=num[i],cnt[d[i].first][d[i].second]++;
	n=t1;m=t2;
	for (int i=1;i<=n;i++) for (int j=m;j;j--) c1[i][j]=c1[i][j+1]+cnt[i][j];
	for (int i=n;i;i--) for (int j=1;j<=m;j++) c2[i][j]=c2[i+1][j]+cnt[i][j];
	for (int i=0;i<=m;i++) mx[i]=-inf,lst1[i]=n+1;
	for (int i=0;i<=n;i++) mn[i]=inf,lst2[i]=m+1;
	for (int i=n;i;i--) for (int j=m;j;j--)
	{
		s1[i][j]=s1[i][j+1]+sum[i][j];
		s2[i][j]=s2[i+1][j]+sum[i][j];
	}
	for (int i=n;i>=0;i--)
	{
		for (int j=m;j>=0;j--)
		{
			if (lst1[j]>n) f[i][j][0]=0;
			else f[i][j][0]=mx[j];
			if (lst2[i]>m) f[i][j][1]=0;
			else f[i][j][1]=mn[i];
			if (c1[i][j+1])
			{
				for (int k=lst1[j]-1;k>=i;k--) mx[j]=max(mx[j],f[k][j][1])+s1[k][j+1]; 
				lst1[j]=i;
			}
			if (c2[i+1][j])
			{
				for (int k=lst2[i]-1;k>=j;k--) mn[i]=min(mn[i],f[i][k][0])-s2[i+1][k];
				lst2[i]=j;
			}
		}
	}
	if (f[0][0][0]>0) puts("Break a heart");
	else if (f[0][0][0]<0) puts("Cry");
	else puts("Flowers");
	return 0;
}