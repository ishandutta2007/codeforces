#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll linf = 0x3f3f3f3f3f3f3f3f;

inline void chk_min(ll &a,ll b){ if(a>b) a=b;}

void solve(void)
{
	ll n,x,y,d;
	scanf("%lld%lld%lld%lld",&n,&x,&y,&d);
	
	ll ans=linf;
	if(y>=x && (y-x)%d==0) chk_min(ans, (y-x)/d);
	if(x>=y && (x-y)%d==0) chk_min(ans, (x-y)/d);
	if((y-1)%d==0) chk_min(ans, (y-1)/d + (x-1+d-1)/d);
	if((n-y)%d==0) chk_min(ans, (n-y)/d + (n-x+d-1)/d);
	
	if(ans==linf) printf("-1\n");
	else printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}