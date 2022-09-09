#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

void solve(void)
{
	ll l,r,m;
	scanf("%lld%lld%lld",&l,&r,&m);
	
	for(int i=l; i<=r; ++i)
	{
		ll a = i;
		if(a>m)
		{
			ll tmp = a-m;
			if(tmp + l <= r)
			{
				printf("%lld %lld %lld\n",a,l,tmp+l);
				return;
			}
		}
		else
		{
			ll tmp = m%a;
			if(tmp + l <= r)
			{
				printf("%lld %lld %lld\n",a,tmp+l,l);
				return;
			}
			
			ll n = (m+a-1)/a;
			tmp = n * a - m;
			if(tmp + l <= r)
			{
				printf("%lld %lld %lld\n",a,l,tmp+l);
				return;
			}
		}
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}