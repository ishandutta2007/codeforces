#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 3e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

inline void chk_max(ll &a,ll b){ if(a<b) a=b;}

int a[3][MAXN];
ll suf[MAXN],b[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=0; i<=1; ++i)
		for(int j=1; j<=n; ++j)
			scanf("%d",&a[i][j]);
	
	for(int i=n; i>=1; --i)
		suf[i] = suf[i+1]+a[0][i]+a[1][i];
	
	int beg = !(n&1);
	for(int i=n; i>=1; i-=2)
	{
		b[i] = b[i+2]+(suf[i+2]<<1ll);
		b[i] += a[beg][i+1];
		ll tmp = (n-i)<<1;
		b[i] += tmp*a[!beg][i+1] + (tmp+1)*a[!beg][i];
		//printf("%d: %lld\n",i,b[i]);
	}
	beg^=1;
	for(int i=n-1; i>=1; i-=2)
	{
		b[i] = b[i+2]+(suf[i+2]<<1ll);
		b[i] += a[beg][i+1];
		ll tmp = (n-i)<<1;
		b[i] += tmp*a[!beg][i+1] + (tmp+1)*a[!beg][i];
		//printf("%d: %lld\n",i,b[i]);
	}
	
	ll ans=0, now=0;
	for(int i=1; i<=n; ++i)
	{
		ll tmp = (i-1)*2;
		chk_max(ans, b[i]+suf[i]*tmp+now);
		
		int beg = !(i&1);
		now += tmp*a[beg][i] + (tmp+1)*a[!beg][i];
	}
	printf("%lld",ans);
	return 0;
}