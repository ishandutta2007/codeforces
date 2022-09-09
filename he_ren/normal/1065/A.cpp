#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(void)
{
	ll s,a,b,c;
	scanf("%lld%lld%lld%lld",&s,&a,&b,&c);
	ll ans = s/c;
	ans += ans/a * b;
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}