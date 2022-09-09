#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
const int MAXN = 2e3 + 5;
const int MAXM = 2e3 + 5;
const int MAXMM = 1e4 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

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

const ll inv2 = pw(2, mod-2);

struct Edge
{
	int next,to,w;
}e[MAXM<<1];
int head[MAXN],etot=0;
inline void add(int u,int v,int w)
{
	e[++etot] = (Edge){ head[u],v,w};
	head[u] = etot;
}

ll f[MAXMM][MAXN];
ll g[MAXMM];

struct Node
{
	ll beg, len;
}a[MAXM<<1], b[MAXM<<1];
int cnt = 0;
inline bool cmp(const Node &p,const Node &q){ return p.beg == q.beg? p.len > q.len: p.beg > q.beg;}

inline ll calc(ll beg, ll len, ll l, ll r)
{
	return ((l+r) * (r-l+1) %mod * inv2 %mod * len %mod + beg * (r-l+1) %mod) %mod;
}

int main(void)
{
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	int mxw = 0;
	for(int i=1; i<=m; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); add(v,u,w);
		
		mxw = max(mxw, w);
	}
	
	for(int i=1; i<=n; ++i) f[0][i] = -linf;
	f[0][1] = 0;
	
	int mm = min(MAXMM-5, q);
	
	for(int k=1; k<=mm; ++k)
		for(int u=1; u<=n; ++u)
		{
			f[k][u] = -linf;
			for(int i=head[u]; i; i=e[i].next)
			{
				int v = e[i].to;
				if(f[k-1][v] != -linf)
					f[k][u] = max(f[k][u], f[k-1][v] + e[i].w);
			}
			if(f[k][u] < 0) f[k][u] = -linf;
		}
	
	for(int i=0; i<=mm; ++i)
	{
		g[i] = -linf;
		for(int j=1; j<=n; ++j)
			g[i] = max(g[i], f[i][j]);
	}
	
	ll sum = 0;
	for(int i=1; i<=mm; ++i)
		sum = (sum + g[i]) %mod;
	
	if(mm == q){ printf("%lld",sum); return 0;}
	
	for(int i=1; i<=etot; ++i)
		a[i] = (Node){ f[mm][ e[i].to ], e[i].w};
	
	sort(a+1,a+etot+1,cmp);
	for(int i=1; i<=etot; ++i)
	{
		if(cnt > 0 && b[cnt].len >= a[i].len) continue;
		b[++cnt] = a[i];
	}
	for(int i=1; i<=cnt; ++i) a[i] = b[i];
	
	ll ans = sum;
	
	ll dif = q-mm, l = 1, r = 0;
	for(int i=1; i<=cnt && l<=dif; ++i)
	{
		r = dif;
		for(int j=i+1; j<=cnt; ++j)
			r = min(r, (a[i].beg - a[j].beg) / (a[j].len - a[i].len));
		
		if(r<l) continue;
		
		r = min(r,dif);
		ans = (ans + calc(a[i].beg %mod, a[i].len %mod, l, r)) %mod;
		
		l=r+1;
	}
		
	printf("%lld",ans);
	return 0;
}