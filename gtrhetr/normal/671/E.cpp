#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 2333333333333333333LL
 
ll a[100010],b[100010],d[100010],h[100010],k;
int st[100010],n,top;
 
inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

ll dis[400010];
ll mx[400010],mn[400010],res[400010],res1[400010],tag[400010];
 
inline void gao(const int &o,const ll &hh) { mx[o]+=hh;res[o]+=hh;res1[o]+=hh;tag[o]+=hh; }
 
inline void pushdown(const int &o)
{
	if (!tag[o]) return;
	gao(o<<1,tag[o]);gao(o<<1|1,tag[o]);
	tag[o]=0;
}
 
inline ll gao(int o,int l,int r,ll hh)
{
	if (l==r) return max(hh,mx[o]-dis[l])+mn[o];
	pushdown(o);
	int mid=(l+r)>>1;
	if (hh<=mx[o<<1]) return min(gao(o<<1,l,mid,hh),res1[o]);
	return min(hh+mn[o<<1],gao(o<<1|1,mid+1,r,hh));
}
 
inline void pushup(const int &o,const int &l,const int &r)
{
	mx[o]=max(mx[o<<1],mx[o<<1|1]);
	mn[o]=min(mn[o<<1],mn[o<<1|1]);
	int mid=(l+r)>>1;
	res[o]=min(res[o<<1],res1[o]=gao(o<<1|1,mid+1,r,mx[o<<1]));
}
 
inline void build(int o,int l,int r)
{
	if (l==r) { mx[o]=b[l];mn[o]=-mx[o];res[o]=0;return; }
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	pushup(o,l,r);
}
 
inline void modify(int o,int l,int r,int x,int y,ll hh)
{
	if (l>=x&&r<=y) { gao(o,hh);return; }
	pushdown(o);
	int mid=(l+r)>>1;
	if (x<=mid) modify(o<<1,l,mid,x,y,hh);
	if (y>mid) modify(o<<1|1,mid+1,r,x,y,hh);
	pushup(o,l,r);
}

inline void update(int o,int l,int r,int x)
{
	if (l==r) return;
	pushdown(o);
	int mid=(l+r)>>1;
	if (x<=mid) update(o<<1,l,mid,x);
	else update(o<<1|1,mid+1,r,x);
	pushup(o,l,r);
}
 
inline ll querymx(int o,int l,int r,int x,int y)
{
	if (l>=x&&r<=y) return mx[o];
	pushdown(o);
	int mid=(l+r)>>1;ll res=-inf;
	if (x<=mid) res=max(res,querymx(o<<1,l,mid,x,y));
	if (y>mid) res=max(res,querymx(o<<1|1,mid+1,r,x,y));
	return res;
}
 
ll hh;
 
inline ll query(int o,int l,int r,int x,int y)
{
	if (l>=x&&r<=y)
	{
		ll res=gao(o,l,r,hh);hh=max(hh,mx[o]);
		return res;
	}
	pushdown(o);
	int mid=(l+r)>>1;ll res=inf;
	if (x<=mid) res=min(res,query(o<<1,l,mid,x,y));
	if (y>mid) res=min(res,query(o<<1|1,mid+1,r,x,y));
	return res;
}
 
int main()
{
	n=rd();k=rd();
	for (int i=1;i<n;i++) d[i]=rd();
	for (int i=1;i<=n;i++) h[i]=rd();
	for (int i=1;i<=n;i++) a[i]=h[i]-d[i],b[i]=h[i]-d[i-1];
	for (int i=1;i<=n;i++) a[i]+=a[i-1],b[i]+=b[i-1];
	build(1,0,n);
	int ans=1;
	st[top=0]=n+1;
	for (int i=n;i;i--)
	{
		while (top&&a[i-1]<=a[st[top]])
		{
			dis[st[top]]=0;update(1,0,n,st[top]);
			modify(1,0,n,st[top],st[top-1]-1,a[st[top]]);
			top--;
		}
		if (st[top]<=n) dis[st[top]]=a[i-1]-a[st[top]],update(1,0,n,st[top]);
		modify(1,0,n,i-1,st[top]-1,-a[i-1]);st[++top]=i-1;
		while (i+ans<=n)
		{
			hh=querymx(1,0,n,i,i+ans-1);
			if (query(1,0,n,i+ans,n)+a[i-1]<=k) ans++;
			else break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
/*
20 10
8 18 15 18 3 20 12 10 7 8 4 8 18 7 5 13 13 7 11
14 15 16 5 1 5 18 12 10 3 19 18 12 13 7 13 10 3 14 12 
*/