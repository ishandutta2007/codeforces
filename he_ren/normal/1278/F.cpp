#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXD = 5e3 + 5;
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

ll S[MAXD][MAXD];

int main(void)
{
	S[0][0] = 1;
	for(int i=1; i<MAXD; ++i)
		for(int j=1; j<=i; ++j)
			S[i][j] = (S[i-1][j-1] + S[i-1][j] * j) %mod;
	
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	if(m == 1) return printf("%lld",pw(n, d)), 0;
	
	int ivm = pw(m, mod-2);
	int p = ivm * pw(1 - ivm + mod, mod-2) %mod;
	
	static int downp[MAXD];
	downp[0] = 1;
	for(int i=1; i<=d; ++i) downp[i] = (ll)downp[i-1] * (n-i+1) %mod;
	
	ll ans = 0;
	for(int i=0; i<=d && i<=n; ++i)
		ans = (ans + (ll)downp[i] * S[d][i] %mod * pw(p, i) %mod * pw(p+1, n-i)) %mod;
	ans = ans * pw(1 - ivm + mod, n) %mod;
	
	printf("%lld",ans);
	return 0;
}