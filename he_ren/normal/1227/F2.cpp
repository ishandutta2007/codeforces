#include<cstdio>
typedef long long ll;
const int MAXN = 2e5 + 5;
const int mod = 998244353;

inline void add_mod(ll &a,ll b){ a+=b; if(a>=mod) a-=mod;}

int pw(ll a,int b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

int h[MAXN];
ll fac[MAXN],inv[MAXN];

ll c(int a,int b)
{
	if(a<0 || b<0 || a-b<0) return 0;
	return fac[a]*inv[b] %mod * inv[a-b] %mod;
}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&h[i]);
	h[n+1]=h[1];
	
	fac[0]=1;
	for(int i=1; i<=n; ++i) fac[i] = fac[i-1]*i %mod;
	inv[n]=pw(fac[n],mod-2);
	for(int i=n-1; i>=0; --i) inv[i] = inv[i+1]*(i+1) %mod;
	
	ll pwm=1;
	int cnt=n;
	for(int i=1; i<=n; ++i)
		if(h[i]==h[i+1])
			pwm = pwm*m %mod,
			--cnt;
	
	ll ans=0;
	int inv2=pw(2,mod-2);
	for(int i=0; i<=cnt; ++i)
	{
		ll tmp=pw(2,i);
		if(!(i&1))
		{
			tmp-=c(i,i>>1);
			if(tmp<0) tmp+=mod;
		}
		tmp = tmp*inv2 %mod;
		add_mod(ans, c(cnt,i)*pw(m-2,cnt-i) %mod * tmp %mod);
	}
	printf("%d",(int)(ans*pwm %mod));
	return 0;
}