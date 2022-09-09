#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	ll n;
	scanf("%lld",&n);
	n = (n + 1) / 2;
	
	ll ans = (n + 2) / 3 * 3;
	for(int i=0; i<=1; ++i)
		for(int j=0; j<=1; ++j)
		{
			if(i * 4 + j * 5 > n) continue;
			ans = min(ans, (n - i * 4 - j * 5 + 2) / 3 * 3 + i * 4 + j * 5);
		}
	printf("%lld\n",ans * 5);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}