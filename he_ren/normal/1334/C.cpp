#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 3e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

ll a[MAXN],b[MAXN];
ll c[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%lld%lld",&a[i],&b[i]);
	
	for(int i=2; i<=n; ++i) c[i] = a[i] - b[i-1];
	c[1] = a[1] - b[n];
	for(int i=1; i<=n; ++i) c[i] = max(c[i],0ll);
	
	ll sum=0;
	for(int i=1; i<=n; ++i) sum += c[i];
	
	ll ans = linf;
	for(int i=1; i<=n; ++i)
		ans = min(ans, sum-c[i]+a[i]);
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}