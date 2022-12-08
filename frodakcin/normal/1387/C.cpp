#include <cstdio>
#include <cstring>
#include <queue>
#include <functional>

template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

using ull = unsigned long long;
using ll = long long;

const ull INF = 0xffffffffffffffff;

const int MG = 120;
const int ML = 55;

int G, N, M, X, L, c[ML][2], g[ML][2], l[ML], q[ML];
bool bad[ML], vis[MG*2][ML][ML];
std::vector<std::vector<int> > jmp[MG*2];
ull dp[MG*2][ML][ML];
struct Tran
{
	public:
		int g, i;//g = gene to transition to, i>>1 = "pair" gene, i&1 = 0 your index in the 2-vector. If i == -1: then its a single transition
};
std::vector<Tran> tr[MG*2];
struct State
{
	public:
		int g, s, e;
		ull w;
		bool operator > (const State& o) const {return w > o.w;}
};
std::priority_queue<State, std::vector<State>, std::greater<State> > pq;

void build_aho()
{
	l[0]=-1;
	q[0]=0;
	memset(g[0], 0, sizeof*g);
	for(int i=0,Q=1,n;i<Q;++i)
	{
		n=q[i];
		if(~l[n])
		{
			memcpy(g[n], g[l[n]], sizeof*g);
			bad[n]|=bad[l[n]];
		}
		for(int x=0;x<=1;++x)
			if(~c[n][x])
			{
				g[n][x]=c[n][x];
				l[c[n][x]]=~l[n]?g[l[n]][x]:0;
				q[Q++]=c[n][x];
			}
	}
}

int main()
{
	memset(dp, 0xff, sizeof dp);
	scanf("%d%d%d", &G, &N, &M);
	X=G;
	for(int i=0;i<N;++i)
	{
		int a,k,u;
		scanf("%d%d", &a, &k);
		if(k==1)
		{
			scanf("%d",&u);
			jmp[a].push_back({u});
			tr[u].push_back({a,-1});
		}
		else
		{
			for(int j=0;j+2<k;++j)
			{
				scanf("%d", &u);
				jmp[a].push_back({u, X});
				tr[u].push_back({a, X<<1});
				tr[X].push_back({a, u<<1|1});
				a=X++;
			}
			int v;
			scanf("%d%d", &u, &v);
			jmp[a].push_back({u,v});
			tr[u].push_back({a, v<<1});
			tr[v].push_back({a, u<<1|1});
		}
	}
	memset(c, -1, sizeof c);
	for(int i=0,l;i<M;++i)
	{
		scanf("%d", &l);
		int n=0;
		for(int j=0,x;j<l;++j)
		{
			scanf("%d", &x);
			if(~c[n][x]) n=c[n][x]; else n=c[n][x]=++L;
		}
		bad[n]=1;
	}
	build_aho();
	for(int i=0;i<=L;++i)
		if(!bad[i])
			for(int v=0,x;v<2;++v)
				if(!bad[x=g[i][v]])
					dp[v][i][x]=1, pq.push({v, i, x, dp[v][i][x]});
	for(State n;!pq.empty();)
	{
		n=pq.top(); pq.pop();
		if(vis[n.g][n.s][n.e]) continue;
		vis[n.g][n.s][n.e]=1;
		for(auto t:tr[n.g])
			if(~t.i)
				if(t.i&1)
				{
					int y=t.i>>1, g=t.g;
					for(int i=0;i<=L;++i)
						if(~dp[y][i][n.s] && ckmin(dp[g][i][n.e], dp[y][i][n.s]+dp[n.g][n.s][n.e]))
							pq.push({g, i, n.e, dp[g][i][n.e]});
				}
				else
				{
					int y=t.i>>1, g=t.g;
					for(int i=0;i<=L;++i)
						if(~dp[y][n.e][i] && ckmin(dp[g][n.s][i], dp[n.g][n.s][n.e]+dp[y][n.e][i]))
							pq.push({g, n.s, i, dp[g][n.s][i]});
				}
			else if(ckmin(dp[t.g][n.s][n.e], dp[n.g][n.s][n.e]))
				pq.push({t.g, n.s, n.e, dp[t.g][n.s][n.e]});
	}
	for(int i=2;i<G;++i)
	{
		ull f=INF;
		for(int j=0;j<=L;++j)
			if(!bad[j])
				ckmin(f, dp[i][0][j]);
		if(!~f)
			printf("YES\n");
		else
			printf("NO %llu\n", f);
	}
	return 0;
}