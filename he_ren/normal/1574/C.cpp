#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

ll a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%lld",&a[i]);
	
	sort(a+1,a+n+1);
	ll sum = accumulate(a+1,a+n+1,0ll);
	
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		
		ll ans = linf;
		int pos = lower_bound(a+1,a+n+1,x) - a;
		if(pos <= n)
			ans = min(ans, max(0ll, y - (sum - a[pos])));
		if(pos - 1 >= 1)
		{
			--pos;
			ans = min(ans, max(0ll, y - (sum - a[pos])) + (x - a[pos]));
		}
		printf("%lld\n",ans);
	}
	return 0;
}