#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	ll x,y,d;
	scanf("%lld%lld%lld",&x,&y,&d);
	
	printf("%lld\n",(d + y * d - 1 + x-1 - 1)/(x-1) + d);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}