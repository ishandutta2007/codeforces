#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 4e5 + 5;

int a[MAXN];
ll sum[MAXN];

ll b[MAXN], sumb[MAXN];

inline ll calc(int len){ return (ll)len * (len+1) / 2;}

int main(void)
{
	int n;
	ll x;
	scanf("%d%lld",&n,&x);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i) a[i+n] = a[i];
	for(int i=1; i<=n*2; ++i)
		sum[i] = sum[i-1] + a[i];
	
	for(int i=1; i<=n*2; ++i)
		b[i] = calc(a[i]);
	for(int i=1; i<=n*2; ++i)
		sumb[i] = sumb[i-1] + b[i];
	
	ll ans=0;
	for(int i=1; i<=n; ++i)
	{
		ll d = sum[i-1] + x;
		int j = lower_bound(sum+1,sum+2*n+1,d) - sum;
		
		ll r = min(sum[i]+x-1, sum[j]);
		ll l = r-x+1;
		
		ll res = sumb[j-1] - sumb[i-1] + calc(r-sum[j-1]) - calc(l-1-sum[i-1]);
		ans = max(ans, res);
	}
	printf("%lld",ans);
	return 0;
}