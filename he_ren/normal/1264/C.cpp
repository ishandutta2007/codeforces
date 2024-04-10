#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fir first
#define sec second
#define Mp make_pair
const int MAXN = 2e5 + 5;
const int mod = 998244353;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

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

bool is[MAXN];
int p[MAXN];

struct Matrix
{
	int g[2][2];
	inline void set(void){ memset(g,0,sizeof(g)); g[0][0]=g[1][1]=1;}
	
	inline void setg(int e)
	{
		g[0][0]=g[0][1]=e;
		g[1][0]=0; g[1][1]=1;
	}
	
	void operator *= (const Matrix b)
	{
		Matrix c=*this;
		memset(g,0,sizeof(g));
		for(int k=0; k<=1; ++k)
			for(int i=0; i<=1; ++i)
				for(int j=0; j<=1; ++j)
					add_mod(g[i][j], (ll)b.g[i][k]*c.g[k][j] %mod);
	}
};

set<int> pos;

Matrix mul[MAXN<<2];
#define ls(u) ((u)<<1)
#define rs(u) ((u)<<1|1)

void push_up(int u)
{
	mul[u]=mul[ls(u)];
	mul[u]*=mul[rs(u)];
}

void build(int u,int l,int r)
{
	if(l==r)
	{
		mul[u].setg( (ll)pw(p[l],mod-2)*100 %mod );
		return;
	}
	int mid = (l+r)>>1;
	build(ls(u),l,mid);
	build(rs(u),mid+1,r);
	push_up(u);
}

Matrix query(int u,int l,int r, int ql,int qr)
{
	if(ql<=l && r<=qr) return mul[u];
	int mid = (l+r)>>1;
	Matrix res; res.set();
	if(ql<=mid) res *= query(ls(u),l,mid, ql,qr);
	if(mid<qr) res *= query(rs(u),mid+1,r, ql,qr);
	return res;
}

int main(void)
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	for(int i=1; i<=n; ++i) scanf("%d",&p[i]);
	
	is[1]=1;
	pos.insert(1); pos.insert(n+1);
	build(1,1,n);
	ll ans = query(1,1,n, 1,n).g[0][1];
	//printf("%lld\n",ans);
	while(Q--)
	{
		int u;
		scanf("%d",&u);
		if(is[u])
		{
			is[u]=0;
			pos.erase(u);
			set<int>::iterator it=pos.lower_bound(u);
			int r=(*it)-1;
			--it;
			int l=*it;
			ans -= query(1,1,n, l,u-1).g[0][1];
			ans -= query(1,1,n, u,r).g[0][1];
			ans += query(1,1,n, l,r).g[0][1];
			
			ans = (ans%mod+mod)%mod;
			printf("%d\n",(int)ans);
		}
		else
		{
			is[u]=1;
			set<int>::iterator it=pos.lower_bound(u);
			int r=(*it)-1;
			--it;
			int l=*it;
			pos.insert(u);
			ans -= query(1,1,n, l,r).g[0][1];
			ans += query(1,1,n, l,u-1).g[0][1];
			ans += query(1,1,n, u,r).g[0][1];
			
			ans = (ans%mod+mod)%mod;
			printf("%d\n",(int)ans);
		}
	}
	return 0;
}