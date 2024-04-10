#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(void)
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	while(Q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		
		ll ans=0;
		if((x&1)!=(y&1)) ans+=((ll)n*n+1)>>1ll;
		
		ll num = (ll)(x-1)*n + y;
		ans += (num+1)>>1ll;
		printf("%lld\n",ans);
	}
	return 0;
}