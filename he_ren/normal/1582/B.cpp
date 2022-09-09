#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n;
	scanf("%d",&n);
	int x = 0, y = 0;
	for(int i=1; i<=n; ++i)
	{
		int k;
		scanf("%d",&k);
		if(k == 0) ++x;
		if(k == 1) ++y;
	}
	
	ll ans = (1ll<<x) * y;
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}