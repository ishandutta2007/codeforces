#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXQ = 3e5 + 5;
const int MAXD = MAXQ*2;

struct Oper
{
	int l,r,k;
}a[MAXQ];

int dsc[MAXD],cnt=0;

int ans[MAXD<<2],is[MAXD<<2],tag[MAXD<<2];
#define ls(u) ((u)<<1)
#define rs(u) ((u)<<1|1)

void push_up(int u,int l,int r)
{
	ans[u] = ans[ls(u)] + ans[rs(u)];
	if(is[u])
	{
		int mid = (l+r)>>1;
		ans[u] += dsc[mid+1]-dsc[mid]-1;
	}
}
void chku(int u,int l,int r,int k)
{
	if(k==1)
	{
		is[u] = ans[u] = 0;
		tag[u]=1;
	}
	else
	{
		is[u] = 1;
		ans[u] = dsc[r]-dsc[l]+1;
		tag[u]=2;
	}
}
void push_down(int u,int l,int r)
{
	if(!tag[u]) return;
	int mid = (l+r)>>1;
	chku(ls(u),l,mid, tag[u]);
	chku(rs(u),mid+1,r, tag[u]);
	tag[u]=0;
}

void build(int u,int l,int r)
{
	is[u]=1;
	if(l==r)
	{
		ans[u]=1;
		return;
	}
	int mid = (l+r)>>1;
	build(ls(u),l,mid);
	build(rs(u),mid+1,r);
	push_up(u,l,r);
}

void update(int u,int l,int r, int ql,int qr,int k)
{
	if(ql<=l && r<=qr)
	{
		chku(u,l,r,k);
		return;
	}
	push_down(u,l,r);
	int mid = (l+r)>>1;
	if(ql<=mid) update(ls(u),l,mid, ql,qr,k);
	if(mid<qr) update(rs(u),mid+1,r, ql,qr,k);
	if(ql<=mid && mid<qr)
	{
		if(k==1) is[u]=0;
		else is[u]=1;
	}
	push_up(u,l,r);
}

int main(void)
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1; i<=q; ++i)
		scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].k);
	
	for(int i=1; i<=q; ++i)
	{
		dsc[++cnt]=a[i].l;
		dsc[++cnt]=a[i].r;
		//if(a[i].l > 1) dsc[++cnt] = a[i].l-1;
		//if(a[i].r < n) dsc[++cnt] = a[i].r+1;
	}
	dsc[++cnt]=1; dsc[++cnt]=n;
	sort(dsc+1,dsc+cnt+1);
	cnt = unique(dsc+1,dsc+cnt+1)-dsc-1;
	for(int i=1; i<=q; ++i)
		a[i].l = lower_bound(dsc+1,dsc+cnt+1,a[i].l)-dsc,
		a[i].r = lower_bound(dsc+1,dsc+cnt+1,a[i].r)-dsc;
	
	build(1,1,cnt);
	for(int i=1; i<=q; ++i)
	{
		update(1,1,cnt, a[i].l,a[i].r,a[i].k);
		printf("%d\n",ans[1]);
	}
	return 0;
}