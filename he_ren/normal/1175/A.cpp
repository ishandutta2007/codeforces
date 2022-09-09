#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	ll n,d;
	scanf("%lld%lld",&n,&d);
	
	ll ans = 0;
	while(n)
	{
		if(n%d) ans += n%d, n-=n%d;
		else ++ans, n/=d;
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