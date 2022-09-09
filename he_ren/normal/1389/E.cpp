#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int gcd(int a,int b){ return b? gcd(b,a%b): a;}

void solve(void)
{
	int m,d,w;
	scanf("%d%d%d",&m,&d,&w);
	ll mx = min(m,d);
	
	--d;
	d = gcd(d,w);
	
	ll ans = 0;
	
	ll tot = mx / (w/d);
	ll rem = mx % (w/d);
	
	ans += rem * ((tot+1) * tot / 2);
	ans += (w/d - rem) * ((tot-1) * tot / 2);
	
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}