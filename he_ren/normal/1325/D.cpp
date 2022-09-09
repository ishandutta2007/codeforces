#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

#define bit(x,i) (((x)>>(i))&1)

int main(void)
{	
	ll u,v;
	scanf("%lld%lld",&u,&v);
	
	if((u&1) != (v&1)) return printf("-1"),0;
	if(u>v) return printf("-1"),0;
	if(u==v)
	{
		if(u) printf("1\n%lld",u);
		else printf("0");
		return 0;
	}
	
	ll x=u, y=(v-u)>>1;
	if(x&y)
	{
		x=u; y=0;
		ll z=0;
		for(int i=0; i<62; ++i)
			if(bit(v,i+1) != bit(u,i+1))
			{
				y |= (1ll<<i);
				z |= (1ll<<i);
				u += (1ll<<(i+1));
			}
		printf("3\n%lld %lld %lld",x,y,z);
	}
	else printf("2\n%lld %lld",x|y,y);
	return 0;
}