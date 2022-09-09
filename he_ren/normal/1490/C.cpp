#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	ll x;
	scanf("%lld",&x);
	
	set<ll> is;
	for(ll i=1; i * i * i < x; ++i)
	{
		is.insert(i * i * i);
		ll y = x - i * i * i;
		if(is.count(y))
		{
			printf("YES\n");
			return;
		}
	}
	printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}