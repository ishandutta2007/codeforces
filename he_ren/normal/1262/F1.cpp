#include<cstdio>
typedef long long ll;
const int MAXN = 2e3 + 5;
const int mod = 998244353;

inline void add_mod(ll &a,int b){ a+=b; if(a>=mod) a-=mod;}

inline int pw(ll a,int b)
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

int h[MAXN];
ll pwm[MAXN],fac[MAXN],inv[MAXN];

int c(int a,int b){ return fac[a]*inv[b] %mod * inv[a-b] %mod;}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&h[i]);
	
	ll t=1;
	int cnt=0;
	for(int i=1; i<=n; ++i)
	{
		int nxt = i==n? 1: i+1;
		if(h[i]==h[nxt]) t = t*m %mod;
		else ++cnt;
	}
	
	pwm[0]=1;
	for(int i=1; i<=n; ++i) pwm[i] = pwm[i-1]*(m-2) %mod;
	
	fac[0]=1;
	for(int i=1; i<=n; ++i) fac[i] = fac[i-1]*i %mod;
	inv[n] = pw(fac[n], mod-2);
	for(int i=n-1; i>=0; --i) inv[i] = inv[i+1]*(i+1) %mod;
	
	ll ans=0;
	for(int i=0; i<=cnt; ++i)
		for(int j=0; j<i && i+j<=cnt; ++j)
			add_mod(ans, t*pwm[cnt-i-j] %mod * c(cnt,i+j) %mod * c(i+j,j) %mod);
	
	printf("%d",(int)ans);
	return 0;
}