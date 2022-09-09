#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;

void solve(void)
{
	int sx,sy,ex,ey;
	scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
	
	ll x = ex-sx;
	ll y = ey-sy;
	
	printf("%lld\n",x*y+1);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}