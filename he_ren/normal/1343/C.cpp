#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	ll ans = 0;
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && (a[i]>0)==(a[j]>0)) ++j;
		
		int mx=a[i];
		for(int k=i; k<j; ++k) mx = max(mx,a[k]);
		ans += mx;
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