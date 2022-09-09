#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;
const int mod = 1e9 + 7;

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

ll fac[MAXN],inv[MAXN];
inline ll c(int n,int m){ return n<0||m<0||n<m? 0: fac[n] * inv[m] %mod * inv[n-m] %mod;}

bool vis[MAXN];

int n,x,pos;
pii f(int l,int r)
{
	if(l>=r) return make_pair(0,0);
	
	int mid = (l+r)>>1;
	bool flag = vis[mid];
	vis[mid] = 1;
	
	if(pos >= mid)
	{
		pii res = f(mid+1,r);
		if(!flag) ++res.second;
		return res;
	}
	else
	{
		pii res = f(l,mid);
		if(!flag) ++res.first;
		return res;
	}
}

int main(void)
{
	fac[0] = 1;
	for(int i=1; i<MAXN; ++i) fac[i] = fac[i-1] * i %mod;
	inv[MAXN-1] = pw(fac[MAXN-1], mod-2);
	for(int i=MAXN-2; i>=0; --i) inv[i] = inv[i+1] * (i+1) %mod;
	
	scanf("%d%d%d",&n,&x,&pos);
	
	vis[pos] = 1;
	pii res = f(0,n);
	
	ll ans = c(n-x, res.first) * fac[res.first] %mod * c(x-1,res.second) %mod * fac[res.second] %mod;
	
	int cnt = 0;
	for(int i=0; i<n; ++i)
		if(!vis[i]) ++cnt;
	ans = ans * fac[cnt] %mod;
	
	printf("%lld",ans);
	return 0;
}