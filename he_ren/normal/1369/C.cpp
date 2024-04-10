#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const int MAXD = MAXN;

int a[MAXN], w[MAXD];
int sum[MAXD];

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=d; ++i) scanf("%d",&w[i]);
	
	sort(a+1,a+n+1);
	sort(w+1,w+d+1);
	reverse(w+1,w+d+1);
	
	ll ans = 0;
	for(int i=1; i<=d; ++i)
	{
		ans += a[n-i+1];
		if(w[d-i+1]==1) ans += a[n-i+1];
	}
	for(int i=1; i<=d; ++i)
		--w[i];
	n -= d;
	
	for(int i=1; i<=d; ++i)
		sum[i] = sum[i-1] + w[i];
	
	for(int i=1; i<=d && w[i]; ++i)
		ans += a[sum[i-1] + 1];
	
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}