#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

int a[MAXN],b[MAXN],p[MAXN];

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	for(int i=1; i<=m; ++i)
		scanf("%d",&b[i]);
	
	for(int i=1; i<=n; ++i) p[a[i]]=i;
	
	ll ans=0;
	int mxp=0, cnt=0;
	for(int i=1; i<=m; ++i)
	{
		if(p[b[i]]<mxp)
		{
			++ans;
			--cnt;
			continue;
		}
		
		cnt += p[b[i]]-mxp-1;
		ans += cnt*2 + 1;
		mxp=p[b[i]];
	}
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}