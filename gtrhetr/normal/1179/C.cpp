#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define inf 1000000

pii t[4000010];

int cnt[1000010],tag[4000010];
int a[300010],b[300010],n,m,q;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print(int x)
{
	static char s[233];
	if (x<0) putchar('-'),x=-x;
	if (!x) { putchar('0');putchar('\n');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar('\n');
}

inline pii merge(pii x,pii y)
{
	return pii(x.first+y.first,min(y.second,x.second-y.first));
}

inline void pushup(int o) { t[o]=merge(t[o<<1],t[o<<1|1]); }

inline void gao(int o,int hh) { t[o].second+=hh;tag[o]+=hh; }

inline void pushdown(int o)
{
	if (!tag[o]) return;
	gao(o<<1,tag[o]);
	gao(o<<1|1,tag[o]);
	tag[o]=0;
}

inline void build(int o,int l,int r)
{
	if (l==r) { t[o]=pii(cnt[l],-cnt[l]);return; }
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	pushup(o);
}

inline void modify(int o,int l,int r,int x,int y,int hh)
{
	if (l>=x&&r<=y) { gao(o,hh);return; }
	pushdown(o);
	int mid=(l+r)>>1;
	if (x<=mid) modify(o<<1,l,mid,x,y,hh);
	if (y>mid) modify(o<<1|1,mid+1,r,x,y,hh);
	pushup(o);
}

inline void update(int o,int l,int r,int x,int hh)
{
	if (l==r)
	{
		t[o].first+=hh;t[o].second-=hh;
		return;
	}
	pushdown(o);
	int mid=(l+r)>>1;
	if (x<=mid) update(o<<1,l,mid,x,hh);
	else update(o<<1|1,mid+1,r,x,hh);
	pushup(o);
}

inline int query(int o,int l,int r,pii hh)
{
	if (l==r)
	{
		if (merge(t[o],hh).second>=0) return -1;
		return l;
	}
	pushdown(o);
	int mid=(l+r)>>1;
	if (merge(t[o<<1|1],hh).second<0) return query(o<<1|1,mid+1,r,hh);
	return query(o<<1,l,mid,merge(t[o<<1|1],hh));
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++) a[i]=rd();
	for (int i=1;i<=m;i++) b[i]=rd();
	for (int i=1;i<=n;i++) cnt[a[i]]++;
	build(1,1,inf);
	for (int i=1;i<=m;i++) modify(1,1,inf,1,b[i],1);
	q=rd();
	while (q--)
	{
		int p=rd(),x=rd(),y=rd();
		if (p==1)
		{
			update(1,1,inf,a[x],-1);
			update(1,1,inf,y,1);
			a[x]=y;
		}
		else
		{
			modify(1,1,inf,1,b[x],-1);
			modify(1,1,inf,1,y,1);
			b[x]=y;
		}
		print(query(1,1,inf,pii(0,0)));
	}
	return 0;
}