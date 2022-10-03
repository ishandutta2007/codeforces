#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct tree { int ls,rs,mn,smn,tag,size;ll sum,sum1; }t[600010];

ll ans1[150010],ans2[150010];
int num[150010],pos[150010],c[150010],n,tot,root;

inline int rd()
{
	int x=0;char ch=getchar();
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

namespace sgt
{

ll sum2[600010],sum[600010],tag[600010];

inline void init()
{
	for (int i=1;i<=n*4;i++) sum2[i]=sum[i]=tag[i]=0;
}

inline void pushup(const int &o)
{
	sum[o]=sum[o<<1]+sum[o<<1|1];
	sum2[o]=sum2[o<<1]+sum2[o<<1|1];
}

inline void gao(const int &o,const ll &hh) { sum[o]+=hh*sum2[o];tag[o]+=hh; }

inline void pushdown(const int &o)
{
	if (!tag[o]) return;
	gao(o<<1,tag[o]);gao(o<<1|1,tag[o]);
	tag[o]=0;
}

inline void modify1(int o,int l,int r,int x,int y,ll hh)
{
	if (l>=x&&r<=y) { gao(o,hh);return; }
	pushdown(o);
	int mid=(l+r)>>1;
	if (x<=mid) modify1(o<<1,l,mid,x,y,hh);
	if (y>mid) modify1(o<<1|1,mid+1,r,x,y,hh);
	pushup(o);
}

inline void modify2(int o,int l,int r,int x,ll hh)
{
	if (l==r) { sum2[o]+=hh;sum[o]+=tag[o]*hh;return; }
	pushdown(o);
	int mid=(l+r)>>1;
	if (x<=mid) modify2(o<<1,l,mid,x,hh);
	else modify2(o<<1|1,mid+1,r,x,hh);
	pushup(o);
}

}

inline void init()
{
	for (int i=1;i<=n*4;i++) t[i].ls=t[i].rs=t[i].size=0,t[i].mn=t[i].smn=n+1,t[i].tag=-1;
	tot=root=0;
}

inline void copy(const int &x,const int &y) { t[x].mn=t[y].mn;t[x].smn=t[y].smn;t[x].size=t[y].size; }

inline void pushup(const int &o)
{
	if (!t[o].ls) copy(o,t[o].rs);
	else if (!t[o].rs) copy(o,t[o].ls);
	else
	{
		if (t[t[o].ls].mn<t[t[o].rs].mn)
		{
			t[o].mn=t[t[o].ls].mn;t[o].size=t[t[o].ls].size;
			t[o].smn=min(t[t[o].ls].smn,t[t[o].rs].mn);
		}
		else if (t[t[o].rs].mn<t[t[o].ls].mn)
		{
			t[o].mn=t[t[o].rs].mn;t[o].size=t[t[o].rs].size;
			t[o].smn=min(t[t[o].rs].smn,t[t[o].ls].mn);
		}
		else
		{
			t[o].mn=t[t[o].ls].mn;t[o].size=t[t[o].ls].size+t[t[o].rs].size;
			t[o].smn=min(t[t[o].ls].smn,t[t[o].rs].smn);
		}
	}
}

inline void gao(const int &o,const int &hh)
{
	if (t[o].mn>hh) return;
	t[o].mn=hh;t[o].tag=hh;
}

inline void pushdown(const int &o)
{
	if (t[o].tag==-1) return;
	if (t[o].ls) gao(t[o].ls,t[o].tag);
	if (t[o].rs) gao(t[o].rs,t[o].tag);
	t[o].tag=-1;
}

inline void insert(int &o,int l,int r,int x)
{
	if (!o) o=++tot;
	if (l==r) { t[o].mn=0;t[o].size=1;return; }
	pushdown(o);
	int mid=(l+r)>>1;
	if (x<=mid) insert(t[o].ls,l,mid,x);
	else insert(t[o].rs,mid+1,r,x);
	pushup(o);
}

inline void modify(int o,int l,int r,int x,int y,int hh)
{
	if (!o) return;
	if (l>=x&&r<=y)
	{
		if (t[o].mn>hh) return;
		if (t[o].smn>hh)
		{
			if (t[o].mn) sgt::modify2(1,1,n,t[o].mn,-t[o].size);
			t[o].mn=hh;sgt::modify2(1,1,n,t[o].mn,t[o].size);
			t[o].tag=hh;
			return;
		}
	}
	pushdown(o);
	int mid=(l+r)>>1;
	if (x<=mid) modify(t[o].ls,l,mid,x,y,hh);
	if (y>mid) modify(t[o].rs,mid+1,r,x,y,hh);
	pushup(o);
}

inline void work(ll *ans)
{
	init();sgt::init();
	for (int i=1;i<=n;i++)
	{
		sgt::modify1(1,1,n,pos[i],n,1);
		insert(root,1,n,pos[i]);
		if (pos[i]<n) modify(root,1,n,pos[i]+1,n,pos[i]);
		ans[i]=sgt::sum[1];
	}
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) num[i]=rd(),pos[num[i]]=i;
	work(ans1);
	for (int i=1;i<=n;i++) pos[i]=n-pos[i]+1;
	work(ans2);
	for (int i=1;i<=n;i++) print((ll)i*i-ans2[i]-ans1[i]);
	return 0;
}