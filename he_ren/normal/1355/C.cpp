#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

void solve(void)
{
	ll a,b,c,d;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	
	ll ans=0;
	for(int i=c; i<=d; ++i)
	{
		ll l=max(i-b+1,a), r=b;
		if(l<=r) ans += (r-l+1) * (c-b+1);
		
		l=max(i-c+1,a); r=min(i-b,b);
		if(l<=r)
		{
			ans += (r-l+1) * (c-i);
			ans += (r+1) * r / 2;
			ans -= (l-1) * l / 2;
		}
	}
	printf("%lld\n",ans);
}

int main(void)
{
	int T=1;
	while(T--) solve();
	return 0;
}