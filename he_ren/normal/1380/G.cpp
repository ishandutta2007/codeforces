#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;
const int mod = 998244353;

inline ll pw(ll a,ll b)
{
	ll res = 1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod; b>>=1;
	}
	return res;
}

int a[MAXN];
ll sum[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	for(int i=1; i<=n; ++i)
		sum[i] = (sum[i-1] + a[i]) %mod;
	
	for(int k=1; k<=n; ++k)
	{
		int beg = (n-k)%k + 1;
		ll ans = sum[beg-1] * ((n-k)/k+1) %mod;
		
		for(int i=(n-k)/k; i>=1; --i, beg+=k)
			ans = (ans + (sum[beg+k-1] - sum[beg-1]) * i) %mod;
		ans = (ans + mod) %mod;
		
		printf("%lld ",ans * pw(n,mod-2) %mod);
	}
	return 0;
}