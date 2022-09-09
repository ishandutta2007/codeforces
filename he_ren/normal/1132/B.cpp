#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 3e5 + 5;

int a[MAXN],q[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	int m;
	scanf("%d",&m);
	for(int i=1; i<=m; ++i) scanf("%d",&q[i]);
	
	sort(a+1,a+n+1); reverse(a+1,a+n+1);
	
	ll ans = 0;
	for(int i=1; i<=n; ++i)
		ans += a[i];
	
	for(int i=1; i<=m; ++i)
		printf("%lld\n",ans-a[q[i]]);
}

int main(void)
{
	int T=1;
	while(T--) solve();
	return 0;
}