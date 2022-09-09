#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

inline int calc(ll x)
{
	if(x<10) return x;
	int sum=0;
	while(x)
		sum+=x%10, x/=10;
	return calc(sum);
}

void solve(void)
{
	ll d;
	int x;
	scanf("%lld%d",&d,&x);
	printf("%lld\n",x+(d-1)*9);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}