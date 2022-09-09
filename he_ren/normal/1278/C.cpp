#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e5 + 5;
const int inf = 0x3f3f3f3f;

inline void chk_min(int &a,int b){ if(a>b) a=b;}

int a[MAXN],b[MAXN];
int ff[MAXN*2],gg[MAXN*2];
int *f=ff+MAXN, *g=gg+MAXN;

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	reverse(b+1,b+n+1);
	
	for(int i=0; i<=n; ++i)
		f[i]=f[-i]=g[i]=g[-i]=inf;
	f[0]=g[0]=n;
	int now=0;
	for(int i=1; i<=n; ++i)
	{
		if(a[i]==1) ++now;
		else --now;
		f[now]=n-i;
	}
	now=0;
	for(int i=1; i<=n; ++i)
	{
		if(b[i]==1) --now;
		else ++now;
		g[now]=n-i;
	}
	
	int ans=inf;
	for(int i=0; i<=n; ++i)
		chk_min(ans, f[i]+g[i]),
		chk_min(ans, f[-i]+g[-i]);
	printf("%d\n",ans);
	
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}