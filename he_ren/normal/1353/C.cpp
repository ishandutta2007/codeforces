#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

void solve(void)
{
	int n;
	scanf("%d",&n);
	int m = n>>1;
	
	ll ans=0;
	for(int i=1; i<=m; ++i)
		ans += (ll)i * ((1 + i*2) * 4 - 4);
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}