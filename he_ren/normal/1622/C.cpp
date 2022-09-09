#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int a[MAXN];
ll sum[MAXN];

void solve(void)
{
	int n;
	ll d;
	scanf("%d%lld",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	for(int i=1; i<=n; ++i) sum[i] = sum[i-1] + a[i];
	
	ll ans = linf;
	for(int i=0; i<n; ++i)
	{
		ll has = sum[n-i] - sum[1];
		// has + (i+1) * a[1] <= d
		// a[1] <= (d - has) / (i+1)
		
		ll t = (d - has) / (i+1);
		if(d - has < 0 && (d - has) % (i+1))
			--t;
		
		ans = min(ans, i + max(0ll, a[1] - t));
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