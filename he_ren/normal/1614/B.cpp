#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int a[MAXN];
pii p[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d",&a[i]);
		p[i] = {-a[i], i};
	}
	
	sort(p+1,p+n+1);
	p[n+1] = {0,0};
	
	static int res[MAXN];
	for(int i=1,j=1; i<=n; i+=2,++j)
	{
		res[p[i].second] = j;
		res[p[i+1].second] = -j;
	}
	res[0] = 0;
	
	ll ans = 0;
	for(int i=1; i<=n; ++i)
		ans += (ll)2 * abs(res[i] - res[0]) * a[i];
	
	printf("%lld\n",ans);
	for(int i=0; i<=n; ++i)
		printf("%d ",res[i]);
	printf("\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}