#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ldb;

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	int mid = n>>1;
	ll tmp = (ll)mid*(mid+1);
	if(!(n&1)) tmp -= n>>1;
	
	ll ans=0;
	while(m--)
	{
		int x,d;
		scanf("%d%d",&x,&d);
		ans += x*n;
		if(d>=0) ans += (ll)d*(n-1)*n/2;
		else ans += (ll)d*tmp;
	}
	printf("%.20lf",(db)ans/n);
	return 0;
}