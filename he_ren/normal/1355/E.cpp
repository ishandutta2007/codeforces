#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

inline void chk_min(ll &a,ll b){ if(a>b) a=b;}

int a[MAXN];
ll sum[MAXN];

int main(void)
{
	int n;
	ll x,y,z;
	scanf("%d%lld%lld%lld",&n,&x,&y,&z);
	chk_min(z, x+y);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	for(int i=1; i<=n; ++i)
		sum[i] = sum[i-1] + a[i];
	
	ll ans = linf;
	
	for(int i=0; i<n; ++i)
	{
		if(a[i]==a[i+1]) continue;
		
		ll l = a[i]+1;
		ll r = min((ll)a[i+1], sum[n]/n);
		if(l>r) continue;
		
		ll A = - y * n + z * i;
		ll B = y * sum[n] - z * sum[i];
		
		ll h = A<0? r: l;
		chk_min(ans, A*h + B);
	}
	
	
	for(int i=0; i<n; ++i)
	{
		if(a[i]==a[i+1]) continue;
		
		ll l = max((ll)a[i]+1, (sum[n]+n)/n);
		ll r = a[i+1];
		if(l>r) continue;
		
		ll A = x*n - z*(n-i);
		ll B = - x*sum[n] + z * (sum[n]-sum[i]);
		
		ll h = A<0? r: l;
		chk_min(ans, A*h + B);
	}
	
	printf("%lld",ans);
	return 0;
}