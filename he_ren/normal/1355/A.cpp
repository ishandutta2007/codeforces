#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

inline void chk_min(int &a,int b){ if(a>b) a=b;}
inline void chk_max(int &a,int b){ if(a<b) a=b;}


inline int calcMin(ll x)
{
	int res=9;
	while(x)
		chk_min(res, x%10),
		x/=10;
	return res;
}

inline int calcMax(ll x)
{
	int res=0;
	while(x)
		chk_max(res, x%10),
		x/=10;
	return res;
}

void solve(void)
{
	ll a,d;
	scanf("%lld%lld",&a,&d);
	
	for(int i=2; i<=d && calcMin(a); ++i)
		a = a + calcMin(a) * calcMax(a);
	printf("%lld\n",a);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}