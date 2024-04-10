#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXP = MAXN*4;
const int inf = 0x3f3f3f3f;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

struct Seg
{
	int l,r;
}a[MAXN];
int dsc[MAXP],m=0;

int b[MAXP];
int c[MAXP],to[MAXP],cnt=0;

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d%d",&a[i].l,&a[i].r);
	
	m=0;
	for(int i=1; i<=n; ++i)
	{
		a[i].l*=2; a[i].r*=2;
		dsc[++m]=a[i].l; dsc[++m]=a[i].l-1;
		dsc[++m]=a[i].r; dsc[++m]=a[i].r+1;
	}
	sort(dsc+1,dsc+m+1);
	m=unique(dsc+1,dsc+m+1)-dsc-1;
	for(int i=1; i<=n; ++i)
		a[i].l = lower_bound(dsc+1,dsc+m+1,a[i].l)-dsc,
		a[i].r = lower_bound(dsc+1,dsc+m+1,a[i].r)-dsc;
	
	for(int i=0; i<=m; ++i) b[i]=0;
	for(int i=1; i<=n; ++i)
		++b[a[i].l], --b[a[i].r+1];
	for(int i=1; i<=m; ++i)
		b[i] += b[i-1];
	for(int i=1; i<=m; ++i)
		if(b[i]>2) b[i]=2;
	
	b[0]=0;
	int tot=0;
	for(int i=1; i<=m; ++i)
		if(b[i]&&!b[i-1]) ++tot;
	
	b[0]=-1;
	cnt=0;
	for(int i=1; i<=m; ++i)
	{
		if(b[i]!=b[i-1])
			c[++cnt]=(b[i]>=2);
		to[i]=cnt;
	}
	for(int i=1; i<=cnt; ++i)
		c[i]+=c[i-1];
	
	int ans=0;
	for(int i=1; i<=n; ++i)
		chk_max(ans, tot + ( c[to[a[i].r]] - c[to[a[i].l]-1] - 1 ) );
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}