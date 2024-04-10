#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(void)
{
	ll x,y;
	scanf("%lld%lld",&x,&y);
	ll a,b;
	scanf("%lld%lld",&a,&b);
	
	if(a*2 < b)
		printf("%lld\n",a*x + a*y);
	else
	{
		if(x>y) swap(x,y);
		printf("%lld\n",x*b + (y-x)*a);
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}