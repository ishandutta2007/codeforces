#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int inf = 0x3f3f3f3f;

int tot;
int a[MAXN], c[MAXN], b[MAXN];

inline void get_less(int n,int a[],int less[])
{
	for(int i=0; i<=tot+1; ++i)
		less[i] = lower_bound(a+1,a+n+1,i) - a - 1;
}

inline void get_greater(int n,int a[],int greater[])
{
	for(int i=0; i<=tot+1; ++i)
		greater[i] = n - (upper_bound(a+1,a+n+1,i) - a) + 1;
}

int main(void)
{
	int n,d,m;
	scanf("%d%d%d",&n,&d,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=d; ++i) scanf("%d",&c[i]);
	for(int i=1; i<=m; ++i) scanf("%d",&b[i]);
	
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	sort(c+1,c+d+1);
	
	tot = n + m + d;
	
	static int ga[MAXN], lb[MAXN], gc[MAXN], lc[MAXN];
	
	get_greater(n,a, ga);
	get_greater(d,c, gc);
	
	get_less(m,b, lb);
	get_less(d,c, lc);
	
	static int f[MAXN], g[MAXN];
	
	for(int i=0; i<=tot+1; ++i)
		f[i] = ga[i] + lc[i+1],
		g[i] = lb[i] + gc[i-1];
	
	int ans = inf;
	
	int mn = f[0];
	for(int i=1; i<=tot+1; ++i)
	{
		ans = min(ans, mn + g[i]);
		mn = min(mn, f[i]);
	}
	
	printf("%d",ans);
	return 0;
}