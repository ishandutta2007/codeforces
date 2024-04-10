#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 4e4 + 5;

int n;
int t[MAXN],sum[MAXN];

inline ll calc(ll x)
{
	return (ll)sum[n-1] * (x/n) + sum[x%n];
}

void solve(void)
{
	int a,b,Q;
	scanf("%d%d%d",&a,&b,&Q);
	
	n = a*b;
	for(int i=0; i<n; ++i)
		t[i] = (i%a%b != i%b%a);
	for(int i=1; i<n; ++i)
		sum[i] = sum[i-1] + t[i];
	
	while(Q--)
	{
		ll l,r;
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",calc(r)-calc(l-1));
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}