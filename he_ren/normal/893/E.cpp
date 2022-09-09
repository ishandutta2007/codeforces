#include<cstdio>
#include<cmath>
typedef long long ll;
const int maxn = 1500000;
const int MAXN = maxn + 5;
const int mod = 1e9 + 7;

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

ll fac[MAXN],inv[MAXN],f[MAXN];

inline int c(int a,int b)
{
	if(a<b) return 0;
	return fac[a]*inv[b] %mod * inv[a-b] %mod;
}

void solve(void)
{
	int x,y;
	scanf("%d%d",&x,&y);
	
	ll ans=pw(2,y-1);
	int sx=sqrt(x);
	for(int i=2; i<=sx && x>1; ++i)
		if(x%i==0)
		{
			int cnt=0;
			while(x%i == 0)
				++cnt, x/=i;
			ans = ans*c(cnt+y-1, y-1) %mod;
		}
	if(x>1) ans = ans*y %mod;
	
	printf("%d\n",(int)ans);
}

int main(void)
{
	fac[0]=1;
	for(int i=1; i<=maxn; ++i) fac[i] = fac[i-1]*i %mod;
	inv[maxn] = pw(fac[maxn], mod-2);
	for(int i=maxn-1; i>=0; --i) inv[i] = inv[i+1]*(i+1) %mod;
	
	int Q;
	scanf("%d",&Q);
	while(Q--) solve();
	return 0;
}