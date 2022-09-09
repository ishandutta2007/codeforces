#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 50 + 5;
const int MAXF = MAXN * 4;
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

ll pw2[MAXF], ipw2[MAXF];

ll fac[MAXF], inv[MAXF];
inline ll c(int n,int m){ return n<0||m<0||n<m? 0: fac[n] * inv[m] %mod * inv[n-m] %mod;}

int a[MAXN];
int sum2[MAXN];

int cc[MAXF];

inline ll get_coef(int x,int y,int z,int s)
{
	return fac[y] * fac[x + 2 * y - 2 * s] %mod * cc[s] %mod * inv[y - s] %mod * inv[z - s] %mod * ipw2[z - s] %mod * ipw2[y] %mod;
}

inline ll get_coef(int x,int y,int z)
{
	int res = 0;
	for(int s=0; s<=y && s<=z; ++s)
	{
//		if(x == 0 && y == 2 && z == 2)
//			printf("res += %lld  cc[%d] = %d\n",get_coef(x,y,z,s),s,cc[s]);
		add_mod(res, get_coef(x,y,z,s));
	}
//	printf("x = %d, y = %d, z = %d, res = %d\n",x,y,z,res);
	return res;
}

int f[MAXN][MAXN];

int main(void)
{
	pw2[0] = 1;
	for(int i=1; i<MAXF; ++i) pw2[i] = pw2[i-1] * 2 %mod;
	ipw2[0] = 1; ipw2[1] = pw(2, mod-2);
	for(int i=2; i<MAXF; ++i) ipw2[i] = ipw2[i-1] * ipw2[1] %mod;
	
	fac[0] = 1;
	for(int i=1; i<MAXF; ++i) fac[i] = fac[i-1] * i %mod;
	inv[MAXF-1] = pw(fac[MAXF-1], mod-2);
	for(int i=MAXF-2; i>=0; --i) inv[i] = inv[i+1] * (i+1) %mod;
	
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i)
		sum2[i] = sum2[i-1] + (a[i] == 2);
	
	for(int i=0; i<MAXF; ++i)
		for(int j=0; (j<<1)<=i; ++j)
		{
			int k = i - (j<<1);
			if((j+k)&1) add_mod(cc[i], mod - inv[j] * inv[k] %mod);
			else add_mod(cc[i], inv[j] * inv[k] %mod);
		}
	
	if(a[1] + 1 > n) return printf("0\n"), 0;
	
	/*
	f[2][a[1]+1] = 1;
	for(int l=2; l<=n; ++l)
		for(int r=l; r<=n; ++r) if(f[l][r])
		{
			int x = sum2[r] - sum2[l-1], y = r - l + 1 - x;
			for(int z=0; x + 2 * y - 2 * z >= 0; ++z)
			{
				int rr = r + (x + 2 * y - 2 * z);
				if(r < n && rr <= r) continue;
				if(rr <= n)
					add_mod(f[r+1][rr], (ll)f[l][r] * get_coef(x, y, z) %mod);
			}
		}
	*/
	
	f[1][a[1]] = 1;
	for(int i=1; i<=n; ++i)
		for(int j=1; i+j<=n; ++j) if(f[i][j])
		{
			int x = sum2[i+j] - sum2[i], y = j - x;
			for(int z=0; x + 2 * y - 2 * z >= 0; ++z)
			{
				int jj = x + 2 * y - 2 * z;
				if(i + j + jj > n) continue;
				add_mod(f[i+j][jj], (ll)f[i][j] * get_coef(x, y, z) %mod);
			}
		}
	
	printf("%d\n",f[n][0]);
	return 0;
}