#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e6 + 5;
const int mod = 1e9 + 7;

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

const int MAXF = MAXN + 100;
ll fac[MAXF], inv[MAXF];
inline ll C(int n,int m){ return n<0||m<0||n<m? 0: fac[n] * inv[m] %mod* inv[n-m] %mod;}

inline int calc(int n,int x)
{
	int res = 0;
	for(int i=1; i<=n; ++i) add_mod(res, C(3 * i, x));
	return res;
}

int f[MAXN];

int main(void)
{
	fac[0] = 1;
	for(int i=1; i<MAXF; ++i) fac[i] = fac[i-1] * i %mod;
	inv[MAXF-1] = pw(fac[MAXF-1], mod - 2);
	for(int i=MAXF-2; i>=0; --i) inv[i] = inv[i+1] * (i+1) %mod;
	
	int n,Q;
	scanf("%d%d",&n,&Q);
	
	int m = 3 * n;
	f[m] = calc(n, m);
	f[m-1] = calc(n, m-1);
	for(int i=m-2; i>=1; --i)
	{
		f[i] = C(m+3, i+3);
		f[i] = (f[i] + mod - 3ll * (f[i+1] + f[i+2]) %mod) %mod;
	}
	
	while(Q--)
	{
		int x;
		scanf("%d",&x);
		printf("%d\n",f[x]);
	}
	return 0;
}