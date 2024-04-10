#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e6 + 5;
const int mod = 998244353;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}
inline int gcd(int a,int b){ return b? gcd(b,a%b): a;}

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

bool isnp[MAXN];
int pri[MAXN], pricnt = 0, mu[MAXN], divv[MAXN][2];
void sieve(int n)
{
	isnp[0] = isnp[1] = 1; mu[1] = 1;
	for(int i=2; i<=n; ++i)
	{
		if(!isnp[i]) pri[++pricnt] = i, mu[i] = -1;
		for(int j=1; j<=pricnt && (ll)i*pri[j]<=n; ++j)
		{
			int x = i*pri[j];
			isnp[x] = 1; divv[x][0] = i; divv[x][1] = pri[j];
			if(i%pri[j]) mu[x] = -mu[i];
			else{ mu[x] = 0; break;}
		}
	}
}

int main(void)
{
	fac[0] = 1;
	for(int i=1; i<MAXN; ++i) fac[i] = fac[i-1] * i %mod;
	inv[MAXN-1] = pw(fac[MAXN-1], mod-2);
	for(int i=MAXN-2; i>=0; --i) inv[i] = inv[i+1] * (i+1) %mod;
	
	int n,d;
	scanf("%d%d",&n,&d);
	if(n == 1 || d == 1)
	{
		printf("1");
		return 0;
	}
	
	sieve(n);
	
	static int f[MAXN];
	for(int i=0; i<=n; ++i)
	{
		if(i) f[i] = f[i-1];
		if(i&1) add_mod(f[i], mod - inv[i]);
		else add_mod(f[i], inv[i]);
	}
	
	auto calc = [&] (int i) -> ll
	{
		int res = mod - 1;
		int lim = min(i, d);
		
		static ll curpw[MAXN];
		for(int k=0; k<=lim; ++k)
		{
			if(k<=1 || !isnp[k])
				curpw[k] = pw(k,i);
			else
				curpw[k] = curpw[divv[k][0]] * curpw[divv[k][1]] %mod;
			
			res = (res + curpw[k] * inv[k] %mod * f[lim-k]) %mod;
		}
		return res;
	};
	
	ll ans = 0;
	for(int i=1; i<=n; ++i)
		ans = (ans + mu[i] * calc((n + i - 1) / i)) %mod;
	ans = (ans %mod + mod) %mod;
	printf("%lld",ans);
	return 0;
}