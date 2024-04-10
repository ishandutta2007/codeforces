#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 LL;
typedef pair<int,int> pii;

LL sum1(LL n){ return n * (n+1) / 2;}
LL sum2(LL n){ return n * (n+1) * (2*n+1) / 6;}
LL calc(LL x,LL y)
{
	if(!x || !y) return 0;
	LL res = sum1(min(x,y) * min(x,y));
	if(x > y) res += y * (sum2(x) - sum2(y)) - (x-y) * sum1(y-1);
	if(x < y) res += x * (sum2(y-1) - sum2(x-1)) + (y-x) * sum1(x);
	return res;
}

void solve(void)
{
	int xl, xr, yl, yr;
	scanf("%d%d%d%d",&xl,&yl,&xr,&yr);
	
	LL ans = calc(xr, yr) - calc(xl-1, yr) - calc(xr, yl-1) + calc(xl-1, yl-1);
	LL mod = 1e10;
	
	if(ans < mod) printf("%lld\n",(ll)ans);
	else printf("...%010lld\n",(ll)(ans % mod));
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}