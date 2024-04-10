#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(void)
{
	ll n;
	scanf("%lld",&n);
	
	ll ans=0;
	if(n&1)
	{
		int sn = sqrt(n);
		for(int i=2; i<=sn; ++i)
			if(n%i==0)
			{
				n-=i;
				break;
			}
		if(n&1) n=0;
		++ans;
	}
	
	ans += n/2;
	printf("%lld",ans);
	return 0;
}