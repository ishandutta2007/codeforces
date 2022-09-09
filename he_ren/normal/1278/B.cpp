#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(void)
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(a>b) swap(a,b);
	int n=b-a;
	
	for(ll i=0; ; ++i)
	{
		ll sum = (i*(i+1))>>1ll;
		if(sum<n) continue;
		if((sum&1ll) == (n&1))
		{
			printf("%lld\n",i);
			return;
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