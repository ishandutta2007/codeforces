#include<cstdio>
#include<cmath>
#include<algorithm>
const int MAXN = 2e5 + 5;
const int LB = 20 + 5;
using namespace std;

struct Seg
{
	int l,r,id;
}a[MAXN];
inline bool cmp(const Seg &a,const Seg &b){ return a.r<b.r;}

int rnk[MAXN*2],cnt=0;

int t[MAXN*2];
#define lowbit(x) ((x)&-(x))
inline void update(int u)
{
	while(u<=cnt)
	{
		++t[u];
		u+=lowbit(u);
	}
}
inline int query(int u)
{
	int res=0;
	while(u)
	{
		res+=t[u];
		u^=lowbit(u);
	}
	return res;
}

int ans[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d%d",&a[i].l,&a[i].r);
		a[i].id=i;
	}
	
	for(int i=1; i<=n; ++i)
		rnk[++cnt] = a[i].l,
		rnk[++cnt] = a[i].r;
	sort(rnk+1,rnk+cnt+1);
	cnt=unique(rnk+1,rnk+cnt+1)-rnk-1;
	for(int i=1; i<=n; ++i)
		a[i].l = lower_bound(rnk+1, rnk+cnt+1, a[i].l)-rnk,
		a[i].r = lower_bound(rnk+1, rnk+cnt+1, a[i].r)-rnk;
	
	sort(a+1,a+n+1,cmp);
	for(int i=1; i<=n; ++i)
	{
		ans[a[i].id] = i-query(a[i].l)-1;
		update(a[i].l);
	}
	
	for(int i=1; i<=n; ++i) printf("%d\n",ans[i]);
	return 0;
}