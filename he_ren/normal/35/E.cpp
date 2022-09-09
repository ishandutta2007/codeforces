#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXD = MAXN*2;

inline int max(int a,int b){ return a>b? a: b;}
inline void chk_max(int &a,int b){ if(a<b) a=b;}

struct Building
{
	int h,l,r;
}a[MAXN];
int dsc[MAXD],cnt=0;

int mx[MAXD<<2],tag[MAXD<<2];
#define ls(u) ((u)<<1)
#define rs(u) ((u)<<1|1)

inline void push_down(int u)
{
	chk_max(mx[ls(u)], tag[u]); chk_max(tag[ls(u)], tag[u]);
	chk_max(mx[rs(u)], tag[u]); chk_max(tag[rs(u)], tag[u]);
	tag[u]=0;
}

void update(int u,int l,int r, int ql,int qr,int k)
{
	if(ql<=l && r<=qr)
	{
		chk_max(mx[u], k); chk_max(tag[u],k);
		return;
	}
	push_down(u);
	int mid = (l+r)>>1;
	if(ql<=mid) update(ls(u),l,mid, ql,qr,k);
	if(mid<qr) update(rs(u),mid+1,r, ql,qr,k);
}

int query(int u,int l,int r, int q)
{
	if(l==r) return mx[u];
	push_down(u);
	int mid = (l+r)>>1;
	if(q<=mid) return query(ls(u),l,mid, q);
	return query(rs(u),mid+1,r, q);
}

int t[MAXD*2];

struct Node
{
	int x,y;
}ans[MAXD*2];
int tot=0;

int main(void)
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d%d%d",&a[i].h,&a[i].l,&a[i].r);
	
	for(int i=1; i<=n; ++i)
		dsc[++cnt] = a[i].l,
		dsc[++cnt] = a[i].r;
	sort(dsc+1,dsc+cnt+1);
	cnt = unique(dsc+1,dsc+cnt+1)-dsc-1;
	for(int i=1; i<=n; ++i)
		a[i].l = lower_bound(dsc+1, dsc+cnt+1, a[i].l)-dsc,
		a[i].r = lower_bound(dsc+1, dsc+cnt+1, a[i].r)-dsc;
	
	for(int i=1; i<=n; ++i)
		update(1,1,cnt, a[i].l,a[i].r-1,a[i].h);
	
	for(int i=1; i<cnt; ++i)
		t[i] = query(1,1,cnt, i);
	
	ans[++tot] = (Node){dsc[1],0};
	for(int i=1; i<cnt; ++i)
	{
		if(t[i]!=t[i-1]) ans[++tot] = (Node){dsc[i],t[i]};
		if(t[i]!=t[i+1]) ans[++tot] = (Node){dsc[i+1],t[i]};
	}
	ans[++tot] = (Node){dsc[cnt],0};
	
	printf("%d\n",tot);
	for(int i=1; i<=tot; ++i)
		printf("%d %d\n",ans[i].x,ans[i].y);
	return 0;
}