#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

inline void chk_min(ll &a,ll b){ if(a>b) a=b;}

int n,d;
ll a[MAXN],sum[MAXN];

ll calc(int l,int r,int i)
{
	if(r-l+1 < d) return linf;
	ll res = a[i]*(i-l+1) - (sum[i]-sum[l-1]) + (sum[r]-sum[i]) - a[i]*(r-i);
	return res - (r-l+1-d);
}

int main(void)
{
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%lld",&a[i]);
	
	sort(a+1,a+n+1);
	
	for(int i=1; i<=n; ++i)
		sum[i] = sum[i-1] + a[i];
	
	ll ans = linf;
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && a[j]==a[i]) ++j;
		if(j-i >= d){ ans=0; break;}
		
		chk_min(ans, calc(1,n,i));
		chk_min(ans, calc(i,n,i));
		chk_min(ans, calc(1,j-1,i));
	}
	
	printf("%lld",ans);
	return 0;
}