#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define inf 2333333333333333333LL

struct node { int s,t,d;ll w; }a[100010];

pll maxn[400010];

ll f[100010][210];
int n,m,k;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void modify(int o,int l,int r,int x,int y,ll h1,ll h2)
{
	if (l>=x&&r<=y) { maxn[o]=max(maxn[o],pll(h1,h2));return; }
	int mid=(l+r)>>1;
	if (x<=mid) modify(o<<1,l,mid,x,y,h1,h2);
	if (y>mid) modify(o<<1|1,mid+1,r,x,y,h1,h2);
}

inline pll query(int o,int l,int r,int x)
{
	if (l==r) return maxn[o];
	pll res=maxn[o];
	int mid=(l+r)>>1;
	if (x<=mid) res=max(res,query(o<<1,l,mid,x));
	else res=max(res,query(o<<1|1,mid+1,r,x));
	return res;
}

int main()
{
	n=rd();m=rd();k=rd();
	for (int i=1;i<=k;i++) a[i].s=rd(),a[i].t=rd(),a[i].d=rd()+1,a[i].w=rd();
	for (int i=1;i<=k;i++) modify(1,1,n,a[i].s,a[i].t,a[i].w,a[i].d);
	for (int i=1;i<=n+1;i++) for (int j=0;j<=m;j++) f[i][j]=inf;
	f[1][0]=0;
	for (int i=1;i<=n;i++)
	{
		pll hh=query(1,1,n,i);
		if (hh.second==0)
		{
			for (int j=0;j<=m;j++) f[i+1][j]=min(f[i+1][j],f[i][j]);
			continue;
		}
		for (int j=0;j<m;j++) f[i+1][j+1]=min(f[i+1][j+1],f[i][j]);
		for (int j=0;j<=m;j++) f[hh.second][j]=min(f[hh.second][j],f[i][j]+hh.first);
	}
	ll ans=inf;
	for (int i=0;i<=m;i++) ans=min(ans,f[n+1][i]);
	printf("%I64d\n",ans);
	return 0;
}