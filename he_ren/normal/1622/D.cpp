#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e3 + 5;
const int mod = 998244353;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

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

ll fac[MAXN], inv[MAXN];
inline ll C(int n,int m){ return n<0||m<0||n<m? 0: fac[n] * inv[m] %mod * inv[n-m] %mod;}

char s[MAXN];
int cnt[MAXN];

int main(void)
{
	fac[0] = 1;
	for(int i=1; i<MAXN; ++i) fac[i] = fac[i-1] * i %mod;
	inv[MAXN-1] = pw(fac[MAXN-1], mod-2);
	for(int i=MAXN-2; i>=0; --i) inv[i] = inv[i+1] * (i+1) %mod;
	
	int n,d;
	scanf("%d%d%s",&n,&d,s+1);
	
	if(count(s+1,s+n+1,'1') < d)
	{
		printf("1");
		return 0;
	}
	
	for(int i=1; i<=n; ++i) cnt[i] = cnt[i-1] + (s[i] == '1');
	
	int ans = 1;
	for(int i=1,j=0; i<=n; ++i)
	{
		while(j<=n && cnt[j] - cnt[i-1] <= d) ++j;
		
		int len = j-i;
		int k = cnt[j-1] - cnt[i-1];
		if(s[i] == '1')
			ans = (ans + C(len - 1, k)) %mod;
		else
			ans = (ans + C(len - 1, k - 1)) %mod;
	}
	printf("%d\n",ans);
	return 0;
}