#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>

using ll = long long;

const int MN = 1.5e3+10;
const int MOD = 998244353;

struct mint
{
	public:
		int v;
		mint(int _v=0) :v(_v) {};
		mint& operator += (const mint& o) {if((v+=o.v)>=MOD) v-=MOD; return *this;}
		mint& operator -= (const mint& o) {if((v-=o.v)<0) v+=MOD; return *this;}
		mint& operator *= (const mint& o) {v=(ll)v*o.v%MOD; return *this;}

		operator int() const {return v;}

		friend mint operator + (mint a, const mint& b) {return a+=b;}
		friend mint operator - (mint a, const mint& b) {return a-=b;}
		friend mint operator * (mint a, const mint& b) {return a*=b;}
};

int N, p[MN*2], top[MN*2], X, cnt[MN*2], s[MN*2];
mint dp[MN*2][MN];
std::vector<int> a[MN], dw[MN*2];
struct Edge
{
	public:
		int u,v;
};
std::vector<Edge> e;
struct DSU
{
	public:
		DSU()
		{
			memset(p, -1, sizeof p);
			for(int i=0;i<MN;++i)
			{
				sz[i]=1;
				g[i].push_back(i);
			}
		}
		int p[MN], r[MN], sz[MN], cnt[MN];
		std::vector<int> g[MN];
		int find(int a) {return ~p[a]?p[a]=find(p[a]):a;}
		bool merge(int u, int v)
		{
			u=find(u), v=find(v);
			if(u==v)
				return ++cnt[u], 0;
			else
			{
				if(r[u]<r[v]) std::swap(u,v);
				else if(r[u]==r[v]) ++r[u];
				cnt[u]+=cnt[v]+1;
				sz[u]+=sz[v];
				p[v]=u;
				if(g[u].size()<g[v].size()) g[u].swap(g[v]);//actually N log N isn't even necessary
				g[u].insert(g[u].end(), g[v].begin(), g[v].end()), g[v].clear();
				return 1;
			}
		}
};
DSU dsu;

int find(int n) {return ~top[n]?top[n]=find(top[n]):n;}

void dfs(int n)
{
	if(n<N)
	{
		s[n]=1, dp[n][1]=mint(1);
		assert(dw[n].empty());
	}
	else
	{
		assert(dw[n].size()>1);
		int x=dw[n][0];
		dfs(x);
		memcpy(dp[n], dp[x], (s[x]+1)*sizeof**dp);
		s[n]=s[x];
		for(int i=1;i<dw[n].size();++i)
		{
			x=dw[n][i];
			dfs(x);
			for(int k=s[x]+s[n];k>=1;--k)
			{
				dp[n][k]=mint(0);
				for(int j=std::max(1, k-s[n]),mj=std::min(k-1, s[x]);j<=mj;++j)
					dp[n][k]+=dp[x][j]*dp[n][k-j];
			}
			s[n]+=s[x];
		}
		dp[n][1] = mint(1);
	}
	//printf("%d: ", n); for(int i=1;i<=s[n];++i) printf("%d ", dp[n][i]); printf("\n");
}

int main()
{
	memset(top, -1, sizeof top);
	scanf("%d", &N);
	e.resize(N*(N-1), {0,0});
	for(int i=0,a;i<N;++i)
		for(int j=0;j<N;++j)
		{
			scanf("%d", &a);
			if(i<j)
				e[a-1]={i,j};
		}
	X=N;
	for(int i=0;i<e.size();++i)
	{
		dsu.merge(e[i].u, e[i].v);
		int q=dsu.find(e[i].u);
		int val=dsu.sz[q];
		val = val*(val-1)/2;
		if(dsu.cnt[q]==val)
		{
			int nn=X++;
			for(int k:dsu.g[q])
			{
				int x=find(k);
				if(x!=nn)
				{
					top[x]=nn;
					dw[nn].push_back(x);
					//printf("%d->%d, %d\n", x, top[x], val);
				}
			}
		}
	}
	dfs(X-1);
	for(int i=1;i<=N;++i)
		printf("%d%c", dp[X-1][i], " \n"[i==N]);
	return 0;
}