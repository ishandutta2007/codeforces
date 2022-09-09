#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	ll n,d;
	scanf("%lld%lld",&n,&d);
	
	int x = 0;
	while((1ll<<x) <= d) ++x;
	if((1ll<<x) >= n)
	{
		if((1ll<<(x-1)) >= n) printf("%d\n",x-1);
		else printf("%d\n",x);
	}
	else
	{
		printf("%lld\n",x + (n - (1ll<<x) + d - 1) / d);
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}