#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll gao(ll a,ll b,ll x,ll y,ll n)
{
	int tmp = min(n, a-x);
	a -= tmp; n -= tmp;
	
	tmp = min(n, b-y);
	b -= tmp; n -= tmp;
	
	return a * b;
}

void solve(void)
{
	ll a,b,x,y,n;
	scanf("%lld%lld%lld%lld%lld",&a,&b,&x,&y,&n);
	printf("%lld\n",min(gao(a,b,x,y,n), gao(b,a,y,x,n)));
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}