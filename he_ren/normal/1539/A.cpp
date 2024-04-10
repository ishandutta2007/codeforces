#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

inline ll calc(int n){ return n<=0? 0: (ll)n * (n + 1) / 2;}

void solve(void)
{
	int n,x,t;
	scanf("%d%d%d",&n,&x,&t);
	
	int mx = t / x;
	ll ans = max(0ll, (ll)(n - mx) * mx);
	ans += calc(min(n-1, mx-1));
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}