#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

inline int calc(int x)
{
	int res=0;
	while(x) ++res, x/=10;
	return res;
}

void solve(void)
{
	ll a,b;
	scanf("%lld%lld",&a,&b);
	printf("%lld\n",a*(calc(b+1)-1));
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}