#include<cstdio>
typedef long long ll;
const int MAXN = 1e3 + 5;
const int mod = 998244353;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

int pw(ll a,int b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res = res*a %mod;
		a = a*a %mod;
		b>>=1;
	}
	return res;
}

int a[MAXN];
ll fac[MAXN],inv[MAXN];
int f[MAXN];

inline int c(int a,int b)
{
	if(a<0 || b<0 || a-b<0) return 0;
	return fac[a]*inv[a-b] %mod * inv[b] %mod;
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	fac[0]=1;
	for(int i=1; i<=n; ++i) fac[i] = fac[i-1] * i %mod;
	inv[n]=pw(fac[n], mod-2);
	for(int i=n-1; i>=0; --i) inv[i] = inv[i+1] * (i+1) %mod;
	
	int ans=0;
	for(int i=n; i>=1; --i)
	{
		if(a[i]<=0 || i+a[i]>n) continue;
		f[i]=c(n-i, a[i]);
		for(int j=i+a[i]+1; j<=n; ++j)
			add_mod( f[i], (ll)f[j]*c(j-i-1, a[i]) %mod );
		add_mod(ans, f[i]);
	}
	printf("%d",ans);
	return 0;
}