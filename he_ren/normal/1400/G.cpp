#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;
const int MAXM = 40 + 5;
const int mod = 998244353;

#define bit(i) (1ll<<(i))

inline ll pw(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod; b>>=1;
	}
	return res;
}

ll fac[MAXN], inv[MAXN];
inline ll c(int n,int m){ return n<0||m<0||n<m? 0: fac[n] * inv[m] %mod * inv[n-m] %mod;}

struct BIT
{
	int tree[MAXN], n;
	#define lowbit(x) ((x)&-(x))
	inline void update(int x,int k)
	{
		while(x<=n)
			tree[x] += k,
			x += lowbit(x);
	}
	inline void update(int l,int r,int k){ update(l,k); update(r+1,-k);}
	inline int query(int x)
	{
		int res = 0;
		while(x)
			res += tree[x],
			x ^= lowbit(x);
		return res;
	}
};

struct Data
{
	int u,v;
};

int x[MAXN], y[MAXN];
Data p[MAXM];

ll val[MAXN][MAXM];

int main(void)
{
	fac[0] = 1;
	for(int i=1; i<MAXN; ++i) fac[i] = fac[i-1] * i %mod;
	inv[MAXN-1] = pw(fac[MAXN-1], mod-2);
	for(int i=MAXN-2; i>=0; --i) inv[i] = inv[i+1] * (i+1) %mod;
	
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d%d",&x[i],&y[i]);
	for(int i=1; i<=m; ++i) scanf("%d%d",&p[i].u,&p[i].v);
	
	static BIT bit;
	bit.n = n;
	for(int i=1; i<=n; ++i) bit.update(x[i],y[i],1);
	
	for(int i=1; i<=n; ++i)
	{
		int cnt = bit.query(i);
		for(int j=0; j<=2*m; ++j)
			val[i][j] = c(cnt-j, i-j);
	}
	for(int j=0; j<=2*m; ++j)
		for(int i=1; i<=n; ++i)
			val[i][j] = (val[i][j] + val[i-1][j]) %mod;
	
	ll ans = 0;
	int all = (1<<m) - 1;
	
	for(int mask=0; mask<=all; ++mask)
	{
		vector<int> vec;
		for(int i=1; i<=m; ++i) if(mask & bit(i-1))
			vec.push_back(p[i].u),
			vec.push_back(p[i].v);
		sort(vec.begin(), vec.end());
		vec.resize(unique(vec.begin(),vec.end()) - vec.begin());
		
		int l=1, r=n;
		for(int i=0; i<(int)vec.size(); ++i)
			l = max(l, x[vec[i]]),
			r = min(r, y[vec[i]]);
		if(l>r) continue;
		
		ll res = (val[r][vec.size()] - val[l-1][vec.size()] + mod) %mod;
		
		int cnt1 = 0;
		for(int i=0; i<m; ++i) if(mask & bit(i))
			++cnt1;
		
		if(cnt1&1) ans = (ans + mod - res) %mod;
		else ans = (ans + res) %mod;
	}
	printf("%lld",ans);
	return 0;
}