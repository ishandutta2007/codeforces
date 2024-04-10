#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int a[MAXN], b[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d%d",&a[i],&b[i]);
	
	static int ta[MAXN], tb[MAXN];
	memset(ta, 0, (n+1)<<2);
	memset(tb, 0, (n+1)<<2);
	for(int i=1; i<=n; ++i) ++ta[a[i]], ++tb[b[i]];
	
	ll ans = (ll)n * (n - 1) * (n - 2) / 6;
	for(int i=1; i<=n; ++i) ans -= (ll)(ta[a[i]] - 1) * (tb[b[i]] - 1);
	
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}