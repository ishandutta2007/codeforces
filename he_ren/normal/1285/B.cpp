#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
const int inf = 0x3f3f3f3f;

inline void chk_min(ll &a,ll b){ if(a>b) a=b;}
inline void chk_max(ll &a,ll b){ if(a<b) a=b;}

int a[MAXN];
ll sum[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i)
		sum[i] = sum[i-1]+a[i];
	
	ll mnS=0, mx=-inf;
	for(int i=1; i<n; ++i)
	{
		chk_max(mx, sum[i]-mnS);
		chk_min(mnS, sum[i]);
	}
	for(int i=1; i<n; ++i)
		chk_max(mx, sum[n]-sum[i]);
	
	if(sum[n] > mx) printf("YES\n");
	else printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}