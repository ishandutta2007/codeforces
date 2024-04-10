#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 3e5 + 5;

ll a[MAXN], sum[MAXN];
ll pre[MAXN], suf[MAXN];

int main(void)
{
	int n,x;
	scanf("%d%d",&n,&x);
	for(int i=1; i<=n; ++i) scanf("%lld",&a[i]);
	
	for(int i=1; i<=n; ++i)
		sum[i] = sum[i-1] + a[i];
	
	ll ans = 0;
	
	ll mn = 0;
	for(int i=1; i<=n; ++i)
	{
		mn = min(mn, sum[i]);
		pre[i] = sum[i] - mn;
		
		ans = max(ans, pre[i]);
	}
	
	mn = 0;
	for(int i=n; i>=1; --i)
	{
		mn = min(mn, sum[n]-sum[i-1]);
		suf[i] = sum[n] - sum[i-1] - mn;
		
		ans = max(ans, suf[i]);
	}
	
	ll mx = 0;
	for(int i=1; i<=n; ++i)
	{
		mx = max(mx, -sum[i]*x + pre[i]);
		
		ans = max(ans, suf[i+1] + sum[i]*x + mx);
	}
	printf("%lld",ans);
	return 0;
}