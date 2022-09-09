#include<cstdio>
#include<Cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef long double ldb;

void solve(void)
{
	ll n,d;
	scanf("%lld%lld",&n,&d);
	
	int mx = 1e6;
	for(int x=0; x<=mx; ++x)
		if(x+(d+x)/(x+1) <= n)
		{
			printf("YES\n");
			return;
		}
	printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}