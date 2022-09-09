#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	ll n;
	scanf("%lld",&n);
	if(n % 2050){ printf("-1\n"); return;}
	n /= 2050;
	int ans = 0;
	while(n)
		ans += n % 10, n /= 10;
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}