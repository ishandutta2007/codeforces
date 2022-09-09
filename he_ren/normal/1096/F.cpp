#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const int mod = 998244353;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}
inline void add_mod(ll &a,ll b){ a+=b; if(a>=mod) a-=mod;}

inline ll pw(ll a,int b)
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

int n,p[MAXN];
int sum[MAXN];
ll fac[MAXN],inv[MAXN];

int tree[MAXN];
#define lowbit(x) ((x)&-(x))
inline void update(int x,int k)
{
	while(x<=n)
		tree[x]+=k,
		x+=lowbit(x);
}
inline int query(int x)
{
	int res=0;
	while(x)
		res+=tree[x],
		x^=lowbit(x);
	return res;
}

int main(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&p[i]);
	
	fac[0]=1;
	for(int i=1; i<=n; ++i) fac[i] = fac[i-1]*i %mod;
	inv[n]=pw(fac[n],mod-2);
	for(int i=n-1; i>=0; --i) inv[i] = inv[i+1]*(i+1) %mod;
	
	for(int i=1; i<=n; ++i)
		sum[i]=sum[i-1]+(p[i]==-1);
	int m=sum[n];
	
	ll ans = (ll)m*(m-1) %mod * pw(4,mod-2) %mod;
	
	for(int i=1; i<=n; ++i)
		if(~p[i])
		{
			update(p[i],1);
			add_mod(ans, query(n)-query(p[i]));	
		}
	
	int invm = pw(m,mod-2);
	for(int i=1; i<=n; ++i)
		if(~p[i])
		{
			ans += (ll)sum[i]*(m-p[i]+query(p[i]))%mod * invm %mod;
			ans += (ll)(sum[n]-sum[i])*(p[i]-query(p[i]))%mod * invm %mod;
			ans%=mod;
		}
	printf("%lld",ans);
	return 0;
}