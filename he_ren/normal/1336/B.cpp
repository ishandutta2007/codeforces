#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n,m,d;
int a[MAXN],b[MAXN],c[MAXN];
ll ans;

#define pw(x) ((x)*(x))
inline ll calc(ll x,ll y,ll z){ return pw(x-y) + pw(y-z) + pw(z-x);}

inline void gao(int x,int y,int c[],int d)
{
	int i = lower_bound(c+1,c+d+1,(x+y)>>1) - c;
	if(i<=d) ans = min(ans, calc(x,y, c[i]));
	--i;
	if(i>=1) ans = min(ans, calc(x,y, c[i]));	
	i+=2;
	if(i<=d) ans = min(ans, calc(x,y, c[i]));
}

void gg(int n,int m,int d,int a[],int b[],int c[])
{
	for(int i=1; i<=n; ++i)
	{
		int j = lower_bound(b+1,b+m+1,a[i]) - b;
		if(j<=m) gao(a[i],b[j],c,d);
		--j;
		if(j>=1) gao(a[i],b[j],c,d);
	}
}

void solve(void)
{
	
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=m; ++i) scanf("%d",&b[i]);
	for(int i=1; i<=d; ++i) scanf("%d",&c[i]);
	
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	sort(c+1,c+d+1);
	
	ans = linf;
	gg(n,m,d, a,b,c);
	gg(n,d,m, a,c,b);
	gg(m,n,d, b,a,c);
	gg(m,d,n, b,c,a);
	gg(d,n,m, c,a,b);
	gg(d,m,n, c,b,a);
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}