#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e2 + 5;
const int mod = 1e9 + 7;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

ll pw(ll a,ll b)
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
inline ll c(int n,int m){ return n<0||m<0||n<m? 0: fac[n] * inv[m] %mod * inv[n-m] %mod;}

inline bool chk_sq(ll x)
{
	ll t = sqrt(x);
	for(ll i=t-2; i<=t+2; ++i)
		if(i * i == x)
			return 1;
	return 0;
}

int n;
int a[MAXN];

namespace Subtask1
{
	int t[MAXN], sum[MAXN], f[MAXN][MAXN];
	
	void solve(void)
	{
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=i; ++j)
				if(chk_sq((ll)a[i] * a[j]))
				{
					++t[j];
					break;
				}
		
		int tot = 0;
		for(int i=1; i<=n; ++i)
			if(t[i]) swap(t[i], t[++tot]);
		for(int i=1; i<=tot; ++i)
			sum[i] = sum[i-1] + t[i];
		
		f[1][t[1] - 1] = fac[t[1]];
		for(int i=2; i<=tot; ++i)
			for(int x=1; x<=t[i]; ++x)
			{
				ll coef = (ll)fac[t[i]] * c(t[i]-1, x-1) %mod;
				for(int j=0; j<sum[i-1]; ++j) if(f[i-1][j])
				{
					int rem = sum[i-1] + 1 - j;
					for(int k=0; k<=j && k<=x; ++k)
					{
						int jj = (t[i] - x) + (j - k);
						add_mod(f[i][jj], (ll)f[i-1][j] * coef %mod * c(j, k) %mod * c(rem, x - k) %mod);
					}
				}
			}
		
		printf("%d",f[tot][0]);
		exit(0);
	}
}

int main(void)
{
	fac[0] = 1;
	for(int i=1; i<MAXN; ++i) fac[i] = fac[i-1] * i %mod;
	inv[MAXN-1] = pw(fac[MAXN-1], mod-2);
	for(int i=MAXN-2; i>=0; --i) inv[i] = inv[i+1] * (i+1) %mod;
	
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	Subtask1::solve();
	return 0;
}