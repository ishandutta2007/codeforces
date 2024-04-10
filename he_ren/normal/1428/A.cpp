#include<cstdio>
#include<algorithm>
#include<vector>
#define x1 x11111
#define x2 x22222
#define y1 y11111
#define y2 y22222
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

inline ll Abs(ll x){ return x<0? -x: x;}

void solve(void)
{
	ll x1,y1,x2,y2;
	scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
	
	if(x1 == x2)
	{
		printf("%lld\n",Abs(y1 - y2));
		return;
	}
	if(y1 == y2)
	{
		printf("%lld\n",Abs(x1 - x2));
		return;
	}
	printf("%lld\n",Abs(x1 - x2) + Abs(y1-y2) + 2);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}