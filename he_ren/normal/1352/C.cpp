#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	
	ll l=1, r=1e10;
	while(l<r)
	{
		ll mid = (l+r)>>1ll;
		if(mid - mid/n >= d) r=mid;
		else l=mid+1;
	}
	printf("%lld\n",l);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}