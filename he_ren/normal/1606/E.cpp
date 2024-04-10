#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e2 + 5;
const int MAXD = 5e2 + 5;
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

ll fac[MAXN], inv[MAXN];
inline ll C(int n,int m){ return n<0||m<0||n<m? 0: fac[n] * inv[m] %mod * inv[n-m] %mod;}

int f[MAXD][MAXN];

int main(void)
{
	fac[0] = 1;
	for(int i=1; i<MAXN; ++i) fac[i] = fac[i-1] * i %mod;
	inv[MAXN-1] = pw(fac[MAXN-1], mod - 2);
	for(int i=MAXN-2; i>=0; --i) inv[i] = inv[i+1] * (i+1) %mod;
	
	int n,d;
	scanf("%d%d",&n,&d);
	
	for(int i=1; i<=d; ++i)
		for(int j=2; j<=n; ++j)
		{
			static ll pwj[MAXN];
			pwj[0] = 1;
			for(int k=1; k<MAXN; ++k) pwj[k] = pwj[k-1] * min(i, (j - 1)) %mod;
			
			f[i][j] = pwj[j];
			if(i >= j-1)
			{
				for(int k=2; k<=j; ++k)
					f[i][j] = (f[i][j] + f[i-j+1][k] * C(j, k) %mod * pwj[j - k]) %mod;
			}
		}
	
	printf("%d",f[d][n]);
	return 0;
}