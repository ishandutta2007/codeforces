#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>

const int MN = 1e5+10;
const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};
const char dir[] = "URDL";
const int INF = 0x3f3f3f3f;

template<typename F, int MN, int MM>
struct MaxFlow// Dinic's, because Hopcroft-Karp, maybe? I don't think preflow push is good for (nearly) bipartite graphs
{
	int hd[MN], nx[MM*2], to[MM*2], N, M, S, T, lvl[MN], cur[MN];
	bool vis[MN];
	F flow[MM*2], cap[MM*2];
	void init(int _N)
	{
		N=_N;
		memset(hd, -1, N*sizeof*hd);
		M=0;
	}
	void adde1(int u, int v, F w)
	{
		to[M]=v, nx[M]=hd[u], hd[u]=M;
		flow[M]=0, cap[M]=w;
		++M;
	}
	void adde(int u, int v, F w)//unidirectional flow
	{
		adde1(u, v, w);
		adde1(v, u, 0);
	}
	bool bfs()
	{
		memset(lvl, -1, N*sizeof*lvl);
		//might as well use cur array as queue
		cur[0]=S;
		lvl[S]=1;
		for(int q=0,n,Q=1;q<Q;++q)
		{
			n=cur[q];
			for(int i=hd[n];~i;i=nx[i])
			{
				if(cap[i]-flow[i]>0 && !~lvl[to[i]])
					lvl[cur[Q++]=to[i]]=lvl[n]+1;
			}
		}
		return ~lvl[T];
	}
	F dfs(int n, F f=1) //1 because this is Hopcroft-Karp (sort of), normally INF would go here
	{
		if(n==T) return f;
		for(int& i=cur[n], x;~i;i=nx[i])
			if(cap[i]-flow[i]>0 && lvl[x=to[i]]==lvl[n]+1)
			{
				F ff=dfs(x, std::min(f, cap[i]-flow[i]));
				if(ff)
					return flow[i]+=ff, flow[i^1]-=ff, ff;
			}
		return 0;
	}
	F saturate(int _S, int _T)
	{
		S=_S, T=_T;
		F tot=0;
		for(;bfs();)
		{
			memcpy(cur, hd, N*sizeof*hd);
			bool ok=0;
			for(F x;x=dfs(S);)
			{
				tot+=x;
				ok=1;
			}
			if(!ok) break;
		}
		return tot;
	}
};

MaxFlow<int, MN, 8*MN> maxflow;

void fail() {printf("NO\n");}

struct Event
{
	public:
		int v, i, j;
		bool operator < (const Event& o) const {return v < o.v;}
};

int T, N, M, a[MN], f[MN], f2[MN], id[MN];
char ok[MN];
bool vis[MN];
std::vector<Event> event;
std::vector<int> g[2];

bool okay(int x, int y) {return 0 <= x && x < N && 0 <= y && y < M;}

int get_dir(int u, int v)
{
	if((u-v)%M)
		return u<v?1:3;//same row? left/right
	else
		return u<v?2:0;//same col? down/up
}

void dfs(int x, int y, int val, bool t=0)
{
	vis[x*M+y]=1;
	id[x*M+y]=g[t].size();
	g[t].push_back(x*M+y);
	for(int k=0;k<4;++k)
	{
		int nx=x+dx[k], ny=y+dy[k];
		if(okay(nx, ny) && !vis[nx*M+ny] && a[nx*M+ny]==val)
			dfs(nx, ny, val, !t);
	}
}

void solve()
{
	scanf("%d%d", &N, &M);
	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
		{
			scanf("%d", a+(i*M+j));
			event.push_back({a[i*M+j], i, j});
		}
	memset(ok, -1, N*M*sizeof*ok);
	memset(f, -1, N*M*sizeof*f);
	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
			for(int k=0;k<4;++k)
			{
				int nx=i+dx[k], ny=j+dy[k];
				if(okay(nx, ny) && a[nx*M+ny]<a[i*M+j])
					ok[i*M+j]=k;
			}
	std::sort(event.begin(), event.end());
	for(int i=0,j;i<event.size();i=j)
	{
		int val=event[i].v;
		for(j=i;j<event.size() && event[j].v==val;++j)
		{
			int x=event[j].i, y=event[j].j;
			if(!vis[x*M+y])
			{
				dfs(x, y, val);
				int X = g[0].size()+g[1].size();
				maxflow.init(X+4);//X->X+1 = original src->sink, X+2->X+3 = new src->sink
				//Middle edges
				for(int i=0;i<g[0].size();++i)
				{
					int x=g[0][i]/M, y=g[0][i]-x*M;//shadow vars
					for(int k=0;k<4;++k)
					{
						int nx=x+dx[k], ny=y+dy[k];
						if(okay(nx, ny) && a[nx*M+ny]==val)
							maxflow.adde(i, id[nx*M+ny]+g[0].size(), 1);
					}
				}
				int s_dem=0, t_exc=0, tot;
				//LHS
				for(int n=0;n<g[0].size();++n)
					if(~ok[g[0][n]])
						maxflow.adde(X, n, 1);
					else
						++s_dem, maxflow.adde(X+2, n, 1);
				//RHS
				for(int n=0;n<g[1].size();++n)
					if(~ok[g[1][n]])
						maxflow.adde(g[0].size()+n, X+1, 1);
					else
						++t_exc, maxflow.adde(g[0].size()+n, X+3, 1);
				//AUX
				maxflow.adde(X+1, X, INF);
				if(s_dem) maxflow.adde(X, X+3, s_dem);
				if(t_exc) maxflow.adde(X+2, X+1, t_exc);
				tot=s_dem+t_exc;
				if(tot != maxflow.saturate(X+2, X+3))
					return fail();
				for(int n=0;n<g[0].size();++n)
					for(int id=maxflow.hd[n];~id;id=maxflow.nx[id])
						if(maxflow.flow[id]==1)
						{
							int oth=maxflow.to[id]-g[0].size();
							assert(!~f[g[0][n]]);
							assert(!~f[g[1][oth]]);
							f[g[0][n]]=1;
							f[g[1][oth]]=val-1;
							f2[g[0][n]]=get_dir(g[0][n], g[1][oth]);
							f2[g[1][oth]]=f2[g[0][n]]^2;
						}
				g[0].clear(), g[1].clear();
			}
		}
	}
	printf("YES\n");
	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
		{
			if(~f[i*M+j])
				printf("%d", f[i*M+j]);
			else
			{
				f2[i*M+j]=ok[i*M+j];
				int nx=i+dx[f2[i*M+j]], ny=j+dy[f2[i*M+j]];
				printf("%d", a[i*M+j]-a[nx*M+ny]);
			}
			if(j+1==M) printf("\n"); else printf(" ");
		}
	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
			printf("%c%c", dir[f2[i*M+j]], " \n"[j+1==M]);
}

void reset()
{
	event.clear();
	memset(vis, 0, N*M*sizeof*vis);
	g[0].clear(), g[1].clear();
}

int main()
{
	scanf("%d", &T);
	for(;T--;)
		solve(), reset();
	return 0;
}