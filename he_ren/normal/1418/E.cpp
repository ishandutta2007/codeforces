#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;
const int MAXF = MAXN * 2;
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

ll fac[MAXF], inv[MAXF];
inline ll c(int n,int m){ return n<0||m<0||n<m? 0: fac[n] * inv[m] %mod * inv[n-m] %mod;}

int d[MAXN];
ll sum[MAXN];

inline ll calc(ll x,ll y,ll a)
{
	if(x<0 || y<0 || x<a) return 0;
	return fac[x] * (x-a+1) %mod * fac[y] %mod * c(y+x+1,x+1) %mod;
}

int main(void)
{
	fac[0] = 1;
	for(int i=1; i<MAXF; ++i) fac[i] = fac[i-1] * i %mod;
	inv[MAXF-1] = pw(fac[MAXF-1], mod-2);
	for(int i=MAXF-2; i>=0; --i) inv[i] = inv[i+1] * (i+1) %mod;
	
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&d[i]);
	
	sort(d+1,d+n+1);
	for(int i=1; i<=n; ++i)
		sum[i] = (sum[i-1] + d[i]) %mod;
	
	while(m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		
		int pos = lower_bound(d+1,d+n+1,b) - d;
		
		int x = n-pos+1, y = pos-1;
		
		ll less = sum[pos-1] * calc(x,y-1,a) %mod;
		ll grea = (sum[n] - sum[pos-1]) * calc(x-1,y,a) %mod;
		
		printf("%lld\n",(less + grea + mod) %mod * inv[n] %mod);
	}
	return 0;
}