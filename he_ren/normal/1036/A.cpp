#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

inline ll cl(ll a,ll b){ return (a+b-1)/b;}

int main(void)
{
	ll n,d;
	scanf("%lld%lld",&n,&d);
	printf("%lld",cl(d,n));
	return 0;
}