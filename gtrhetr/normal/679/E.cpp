#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll num[100010],bin[110];
int n,m,tt;

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print(ll x)
{
	static char s[233];
	if (!x) { putchar('0');putchar('\n');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar('\n');
}

inline void pre_gao()
{
	bin[0]=1;
	while (bin[tt]<1e16) tt++,bin[tt]=bin[tt-1]*42;
}

ll mn[400010],val[400010],tag[400010],d[400010];
bool bo[400010];

inline void pushup(const int &o)
{
	mn[o]=min(mn[o<<1],mn[o<<1|1]);
	if (!bo[o<<1]||!bo[o<<1|1]||val[o<<1]!=val[o<<1|1]) { bo[o]=false;return; }
	bo[o]=true;val[o]=val[o<<1];d[o]=d[o<<1];
}

inline void gao(const int &o,const ll &hh)
{
	mn[o]-=hh;
	if (bo[o]) val[o]+=hh;
	else tag[o]+=hh;
}

inline void pushdown(const int &o)
{
	if (bo[o])
	{
		bo[o<<1]=bo[o<<1|1]=true;
		mn[o<<1]=mn[o];mn[o<<1|1]=mn[o];
		val[o<<1]=val[o];val[o<<1|1]=val[o];
		d[o<<1]=d[o];d[o<<1|1]=d[o];
		tag[o<<1]=tag[o<<1|1]=0;
	}
	else if (tag[o]) gao(o<<1,tag[o]),gao(o<<1|1,tag[o]),tag[o]=0;
}

inline void build(int o,int l,int r)
{
	if (l==r)
	{
		bo[o]=true;val[o]=num[l];d[o]=0;
		while (num[l]>bin[d[o]]) d[o]++;
		mn[o]=bin[d[o]]-num[l];
		return;
	}
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	pushup(o);
}

inline void modify1(int o,int l,int r,int x,int y,ll hh)
{
	if (l>=x&&r<=y)
	{
		bo[o]=true;val[o]=hh;d[o]=0;tag[o]=0;
		while (val[o]>bin[d[o]]) d[o]++;
		mn[o]=bin[d[o]]-val[o];
		return;
	}
	pushdown(o);
	int mid=(l+r)>>1;
	if (x<=mid) modify1(o<<1,l,mid,x,y,hh);
	if (y>mid) modify1(o<<1|1,mid+1,r,x,y,hh);
	pushup(o);
}

inline void modify2(int o,int l,int r,int x,int y,ll hh)
{
	if (l>=x&&r<=y)
	{
		if (bo[o])
		{
			val[o]+=hh;
			while (val[o]>bin[d[o]]) d[o]++;
			mn[o]=bin[d[o]]-val[o];
			return;
		}
		if (mn[o]>=hh) { gao(o,hh);return; }
		pushdown(o);
		int mid=(l+r)>>1;
		modify2(o<<1,l,mid,x,y,hh);
		modify2(o<<1|1,mid+1,r,x,y,hh);
		pushup(o);
		return;
	}
	pushdown(o);
	int mid=(l+r)>>1;
	if (x<=mid) modify2(o<<1,l,mid,x,y,hh);
	if (y>mid) modify2(o<<1|1,mid+1,r,x,y,hh);
	pushup(o);
}

inline ll query(int o,int l,int r,int x)
{
	if (l==r) return val[o];
	pushdown(o);
	int mid=(l+r)>>1;
	if (x<=mid) return query(o<<1,l,mid,x);
	return query(o<<1|1,mid+1,r,x);
}

int main()
{
	n=rd();m=rd();pre_gao();
	for (int i=1;i<=n;i++) num[i]=rd();
	build(1,1,n);
	while (m--)
	{
		int p=rd();
		if (p==1)
		{
			int x=rd();
			print(query(1,1,n,x));
		}
		else if (p==2)
		{
			int x=rd(),y=rd();ll hh=rd();
			modify1(1,1,n,x,y,hh);
		}
		else
		{
			int x=rd(),y=rd();ll hh=rd();
			do
			{
				modify2(1,1,n,x,y,hh);
			}while (mn[1]==0);
		}
	}
	return 0;
}