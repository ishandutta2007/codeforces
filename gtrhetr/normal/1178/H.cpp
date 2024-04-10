#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define inf 2333333333333333333LL
#define inf1 1061109567

struct node { ll x,y;int id; }h[5010];

pll num[5010],h1[5010];

int cnt[5010],n;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline bool cmp(const node &x,const node &y) { return (x.x^y.x)?(x.x<y.x):(x.y>y.y); }

inline bool check(int mid)
{
	for (int i=1;i<=n*2;i++) h[i].x=num[i].second,h[i].y=num[i].first*mid+num[i].second,h[i].id=i;
	for (int i=1;i<=n*2;i++) h1[i]=pll(h[i].y,i);
	sort(h+1,h+n*2+1,cmp);sort(h1+1,h1+n*2+1);
	memset(cnt,0,sizeof(cnt));
	ll mx=-inf;
	for (int i=1;i<=n*2;i++)
	{
		mx=max(mx,h[i].y);
		if (h[i].id<=n) cnt[upper_bound(h1+1,h1+n*2+1,pll(mx,inf))-h1]++;
	}
	int now=0;
	for (int i=1;i<=n*2;i++)
	{
		now-=cnt[i];
		if (now<0) return false;
		if (h1[i].second>n) now++;
	}
	return true;
}

namespace Gao
{

struct node { int t,v,c,op,next; }a[200010];

int head[14010],dis[14010],cur[14010],vs,vt,tot;
bool vis[14010],inq[14010];

inline void add(int x,int y,int z,int c)
{
	a[++tot].t=y;a[tot].v=z;a[tot].c=c;a[tot].op=tot+1;a[tot].next=head[x];head[x]=tot;
	a[++tot].t=x;a[tot].v=0;a[tot].c=-c;a[tot].op=tot-1;a[tot].next=head[y];head[y]=tot;
}

int ans,cost;

queue<int> q;

inline bool spfa()
{
	while (!q.empty()) q.pop();
	for (int i=vs;i<=vt;i++) dis[i]=inf1,inq[i]=false;
	dis[vt]=0;q.push(vt);inq[vt]=true;
	while (!q.empty())
	{
		int x=q.front();q.pop();
		for (int i=head[x];i;i=a[i].next) if (a[a[i].op].v)
		{
			int t=a[i].t;
			if (dis[t]>dis[x]-a[i].c)
			{
				dis[t]=dis[x]-a[i].c;
				if (!inq[t]) inq[t]=true,q.push(t);
			}
		}
		inq[x]=false;
	}
	return dis[vs]<inf1;
}

inline int dfs(int x,int y)
{
	if (x==vt||!y) return y;
	vis[x]=true;int res=0;
	for (int &i=cur[x];i;i=a[i].next) if (a[i].v)
	{
		int t=a[i].t;
		if (dis[t]!=dis[x]-a[i].c||vis[t]) continue;
		int hh=dfs(t,min(y,a[i].v));
		if (!hh) continue;
		res+=hh;y-=hh;
		a[i].v-=hh;a[a[i].op].v+=hh;
		cost+=a[i].c*hh;
		if (!y) break;
	}
	vis[x]=false;
	return res;
}

inline int work(int mid)
{
	vs=0;vt=n*6+1;
	for (int i=1;i<=n;i++) add(vs,i,1,0);
	for (int i=1;i<=n;i++) add(n+i,vt,1,0);
	for (int i=1;i<=n*2;i++) h1[i]=pll(num[i].second,i);
	sort(h1+1,h1+n*2+1);
	for (int i=1;i<=n*2;i++) add(n*2+i,h1[i].second,inf1,0);
	for (int i=2;i<=n*2;i++) add(n*2+i,n*2+i-1,inf1,0);
	for (int i=1;i<=n*2;i++)
		if (h1[i].second<=n) add(h1[i].second,n*2+upper_bound(h1+1,h1+n*2+1,pll(h1[i].first,inf))-h1-1,1,1);
	for (int i=1;i<=n*2;i++) h1[i]=pll(num[i].first*mid+num[i].second,i);
	sort(h1+1,h1+n*2+1);
	for (int i=1;i<=n*2;i++) add(n*4+i,h1[i].second,inf1,0);
	for (int i=2;i<=n*2;i++) add(n*4+i,n*4+i-1,inf1,0);
	for (int i=1;i<=n*2;i++) add(h1[i].second,n*4+upper_bound(h1+1,h1+n*2+1,pll(h1[i].first,inf))-h1-1,inf1,1);
	ans=cost=0;
	while (spfa())
	{
		int lst;
		do
		{
			lst=ans;
			for (int i=vs;i<=vt;i++) cur[i]=head[i];
			ans+=dfs(vs,inf1);
		}while (ans>lst);
	}
	return cost;
}

}

int main()
{
	n=rd();
	for (int i=1;i<=n*2;i++) num[i].first=rd(),num[i].second=rd();
	int l=0,r=1000000000;
	while (l<r)
	{
		int mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	if (!check(l)) { puts("-1");return 0; }
	printf("%d %d\n",l,Gao::work(l));
	return 0;
}