#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

inline void chk_max(ll &a,ll b){ if(a<b) a=b;}

void solve(void)
{
	ll n,g,b;
	scanf("%lld%lld%lld",&n,&g,&b);
	
	if(g>=b)
	{
		printf("%lld\n",n);
		return;
	}
	
	ll m = n>>1ll;
	n-=m;
	
	ll ans=0;
	ll t = m/b;
	ans += t*(g+b);
	n-=t*g;
	m-=t*b;
	
	if(!m)
	{
		if(n%g) ans += (n/g)*(g+b) + n%g;
		else if(n) ans += (n/g)*(g+b) - b;
	}
	else
	{
		if(n<=g) ans += n+m;
		else
		{
			n-=g;
			ans += g+b;
			
			if(n%g) ans += (n/g)*(g+b) + n%g;
			else if(n) ans += (n/g)*(g+b) - b;
		}
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