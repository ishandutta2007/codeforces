#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(void)
{
	ll n,m,d;
	scanf("%lld%lld%lld",&n,&m,&d);
	if(n<m) swap(n,m);
	if(d<n){ printf("-1\n"); return;}
	
	if(((n-m)&1)==0 && ((d-m)&1))
		--n, --m, d-=2;
	ll ans = m;
	n-=m; d-=m;
	if(n&1) --d;
	ans += d;
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	
	return 0;
}