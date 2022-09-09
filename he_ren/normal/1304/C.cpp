#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e2 + 5;
const int MAXP = MAXN*3;
const int inf = 0x3f3f3f3f;

inline void chk_min(int &a,int b){ if(a>b) a=b;}
inline void chk_max(int &a,int b){ if(a<b) a=b;}

struct Node
{
	int t,l,h;
}a[MAXN];

int dsc[MAXP],cnt=0;

int l[MAXP],h[MAXP];
int x[MAXP],y[MAXP];

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		scanf("%d%d%d",&a[i].t,&a[i].l,&a[i].h);
	
	cnt=0;
	for(int i=1; i<=n; ++i)
		dsc[++cnt]=a[i].t;
	sort(dsc+1,dsc+cnt+1);
	cnt=unique(dsc+1,dsc+cnt+1)-dsc-1;
	for(int i=1; i<=n; ++i)
		a[i].t=lower_bound(dsc+1,dsc+cnt+1,a[i].t)-dsc;
	
	l[0]=h[0]=m;
	for(int i=1; i<=cnt; ++i)
		l[i]=-inf, h[i]=inf;
	for(int i=1; i<=n; ++i)
	{
		chk_max(l[a[i].t],a[i].l);
		chk_min(h[a[i].t],a[i].h);
	}
	for(int i=1; i<=cnt; ++i)
	{
		chk_max(l[i], l[i-1]-(dsc[i]-dsc[i-1]));
		chk_min(h[i], h[i-1]+(dsc[i]-dsc[i-1]));
		if(l[i]>h[i]){ printf("NO\n"); return;}
	}
	printf("YES\n");
}

int main(void)
{
	int Q;
	scanf("%d",&Q);
	while(Q--) solve();
	return 0;
}