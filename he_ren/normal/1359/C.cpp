#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef long double ldb;
const ldb eps = 1e-9;

int h,c,t;

inline ldb calc(ll x){ return (x*h + (x-1)*c) / (ldb)(x*2-1);}

void solve(void)
{
	
	scanf("%d%d%d",&h,&c,&t);
	if(t*2 <= h+c){ printf("%d\n",2); return;}
	
	int l=1, r=1e9;
	while(l<r)
	{
		int mid = (l+r)>>1;
		if(calc(mid)<t) r=mid;
		else l=mid+1;
	}
	
	ldb mn = abs(calc(l) - t);
	int ans = l;
	
	for(int k=-2; k<=2; ++k)
	{
		if(l+k < 1) continue;
		ldb now = abs(calc(l+k) - t);
		
		if(now < mn || (abs(now-mn)<=eps && ans>l+k))
			ans = l+k,
			mn = now;
	}
	printf("%d\n",ans*2 - 1);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}