#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;

int a[MAXN];

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	ll ans = 0;
	
	ll sum = a[1];
	for(int i=2; i<=n; ++i)
	{
		ll need = ((ll)a[i] * 100 + d - 1) / d;
		if(sum <= need) ans += need - sum, sum = need;
		sum += a[i];
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