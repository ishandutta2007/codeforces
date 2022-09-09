#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll linf = 0x7fffffffffffffff;

ll c[7];

ll ans;
inline void chk_ans(ll x){ ans = min(ans, x);}

void solve(void)
{
	int x,y;
	scanf("%d%d",&x,&y);
	for(int i=1; i<=6; ++i)
		scanf("%lld",&c[i]);
	
	if(x < 0)
	{
		y = -y;
		x = -x;
		swap(c[3], c[6]);
		swap(c[1], c[4]);
		swap(c[2], c[5]);
	}
	
	ll c1 = c[1], c2 = c[2], c3 = c[3], c4 = c[4], c5 = c[5], c6 = c[6];
	
	ans = linf;
	
	if(y <= 0) chk_ans(c6 * x + c5 * (-y));
	else chk_ans(c6 * x + c2 * y);
	
	if(x <= y) chk_ans(c1 * x + c2 * (y-x));
	else chk_ans(c1 * x + c5 * (x-y));
	
	if(y >= 0)
	{
		if(x <= y) chk_ans(c1 * y + c3 * (y-x));
		else chk_ans(c1 * y + c6 * (x-y));
	}
	
	if(y <= 0)
	{
		chk_ans(c4 * (-y) + c6 * (-y + x));
	}
	
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}