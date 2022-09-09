#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

#define bit(x,i) (((x)>>(i))&1ll)

void solve(void)
{
	int n;
	scanf("%d",&n);
	ll a=0,b=0;
	for(int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d",&x);
		a+=x; b^=x;
	}
	b<<=1ll;
	
	ll x=0,y=0,z=0;
	for(ll i=0; i<62; ++i)
	{
		if(bit(a,i) == bit(b,i)) continue;
		x|=(1ll<<i);
		a+=(1ll<<i);
		b^=(1ll<<(i+1));
	}
	if(bit(a,62ll) != bit(b,62ll))
		y=z=1ll<<61ll;
	printf("3\n%lld %lld %lld\n",x,y,z);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}