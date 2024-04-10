#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 3e5 + 5;
const int MAXM = 3e5 + 5;

inline ll gcd(ll a,ll b){ return b? gcd(b,a%b): a;}

ll a[MAXN], p[MAXM];

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%lld",&a[i]);
	for(int i=1; i<=m; ++i) scanf("%lld",&p[i]);
	
	ll x = 0;
	for(int i=1; i<n; ++i)
		x = gcd(x, a[i+1]-a[i]);
	
	for(int i=1; i<=m; ++i)
	{
		if(x%p[i]) continue;
		printf("YES\n");
		printf("%lld %d\n",a[1],i);
		return;
	}
	printf("NO\n");
}

int main(void)
{
	int T=1;
	while(T--) solve();
	return 0;
}