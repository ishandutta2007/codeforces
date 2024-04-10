#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
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

int f[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	
	f[1] = 1;
	for(int i=2; i<=n; ++i)
		f[i] = (f[i-1] + f[i-2]) %mod;
	
	printf("%lld", f[n] * pw(pw(2, n), mod-2) %mod);
	return 0;
}