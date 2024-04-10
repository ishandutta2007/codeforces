#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define y1 DCXISSOHANDSOME

struct node { int p,x,y; }e[200010];

map<int,bool> mp[200010];
map<pii,int> lst;

vector<pii> v[800010];

int fa[200010],size[200010];
int n,m,ans=0;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline int find(int x) { return (x==fa[x])?x:find(fa[x]); }

inline void modify(int o,int l,int r,int x,int y,pii hh)
{
	if (l>=x&&r<=y) { v[o].push_back(hh);return; }
	int mid=(l+r)>>1;
	if (x<=mid) modify(o<<1,l,mid,x,y,hh);
	if (y>mid) modify(o<<1|1,mid+1,r,x,y,hh);
}

inline void gao(int o,int l,int r)
{
	vector<pii> now;now.clear();
	for (pii hh:v[o])
	{
		int x=hh.first,y=hh.second;
		if (mp[x][y])
		{
			int f1=find(x),f2=find(y);
			if (f1==f2) continue;
			if (size[f1]>size[f2]) swap(f1,f2);
			now.push_back(pii(f1,f2));
			fa[f1]=f2;size[f2]+=size[f1];
		}
	}
	if (l==r)
	{
		if (e[l].p==2) putchar((ans=(find(e[l].x)==find(e[l].y))?1:0)+'0');
		if (l<m)
		{
			e[l+1].x=(e[l+1].x+ans-1)%n+1;e[l+1].y=(e[l+1].y+ans-1)%n+1;
			if (e[l+1].x>e[l+1].y) swap(e[l+1].x,e[l+1].y);
			if (e[l+1].p==1) mp[e[l+1].x][e[l+1].y]^=1;
		}
	}
	else
	{
		int mid=(l+r)>>1;
		gao(o<<1,l,mid);
		gao(o<<1|1,mid+1,r);
	}
	for (pii hh:now)
	{
		int x=hh.first,y=hh.second;
		size[y]-=size[x];fa[x]=x;
	}
	now.clear();
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=m;i++)
	{
		e[i].p=rd();e[i].x=rd();e[i].y=rd();
		if (e[i].x>e[i].y) swap(e[i].x,e[i].y);
	}
	for (int i=1;i<=m;i++) if (e[i].p==1)
	{
		int x=e[i].x,y=e[i].y;
		if (lst.count(pii(x,y))) modify(1,1,m,lst[pii(x,y)],i-1,pii(x,y));
		int h1=x,h2=y;
		x=x%n+1;y=y%n+1;
		if (x>y) swap(x,y);
		if (lst.count(pii(x,y))) modify(1,1,m,lst[pii(x,y)],i-1,pii(x,y));
		lst[pii(h1,h2)]=lst[pii(x,y)]=i;
	}
	for (map<pii,int>::iterator it=lst.begin();it!=lst.end();it++) modify(1,1,m,it->second,m,it->first);
	for (int i=1;i<=n;i++) fa[i]=i,size[i]=1;
	if (e[1].p==1) mp[e[1].x][e[1].y]=1;
	gao(1,1,m);
	putchar('\n');
	return 0;
}