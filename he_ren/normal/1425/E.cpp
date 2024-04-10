#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int a[MAXN],b[MAXN];
ll suf[MAXN];

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	
	for(int i=n; i>=1; --i)
		suf[i] = suf[i+1] + a[i];
	
	if(d == 0)
	{
		ll ans = 0;
		for(int i=1; i<=n; ++i)
			ans = max(ans, suf[i] - b[i]);
		printf("%lld",ans);
		return 0;
	}
	if(d >= 2)
	{
		ll ans = max(0, a[n] - b[n]);
		for(int i=1; i<n; ++i)
			ans = max(ans, suf[1] - b[i]);
		printf("%lld",ans);
		return 0;
	}
	
	static ll pre_mn[MAXN];
	pre_mn[0] = linf;
	for(int i=1; i<=n; ++i)
		pre_mn[i] = min(pre_mn[i-1], (ll)b[i]);
	
	ll ans = 0;
	
	ll part2 = 0;
	for(int i=n-1; i>=1; --i)
	{
		ll part1 = max(suf[1] - suf[i+1] - pre_mn[i], 0ll);
		part2 = max(part2, suf[i+1] - b[i+1]);
		
		ans = max(ans, part1 + part2);
	}
	
	ll f = -linf;
	for(int i=2; i<n; ++i)
	{
		f = max(f, suf[i-1] - b[i-1]);
		
		ans = max(ans, f - a[i] + max(a[i]-b[i], 0));
	}
	
	printf("%lld",ans);
	return 0;
}