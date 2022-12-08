#include <cstdio>
#include <cstring>
#include <algorithm>

const int MN = 2e2+10;

template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}
template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}

template<typename F, int MN, int MM>
struct MaxFlow
{
	public:
		int hd[MN], to[MM*2], nx[MM*2], q[MN], cur[MN], lvl[MN], N, M, S, T;
		F flow[MM*2], cap[MM*2];
		void init(int _N)
		{
			N=_N;
			memset(hd, -1, N*sizeof*hd);
			//everything else to zero
		}
		void add1(int u, int v, F c)
		{
			flow[M]=0, cap[M]=c;
			nx[M]=hd[u], to[M]=v, hd[u]=M++;
		}
		void adde(int u, int v, F c)//1 directional
		{
			add1(u, v, c);
			add1(v, u, 0);
		}
		bool bfs()
		{
			memset(lvl, 0, N*sizeof*lvl);
			lvl[S]=1;
			q[0]=S;
			for(int i=0,Q=1,x,y;i<Q;++i)
			{
				x=q[i];
				for(int j=hd[x];~j;j=nx[j])
					if(cap[j]-flow[j]>0 && !lvl[y=to[j]])
						lvl[y]=lvl[x]+1, q[Q++]=y;
			}
			return lvl[T];
		}
		F dfs(int n, F f)
		{
			if(n == T) return f;
			for(int &i=cur[n],x;~i;i=nx[i])
				if(cap[i]-flow[i]>0 && lvl[x=to[i]]==lvl[n]+1)
				{
					F r=dfs(x, std::min(f, cap[i]-flow[i]));
					if(r>0)
						return flow[i]+=r, flow[1^i]-=r, r;
				}
			return 0;
		}
		F saturate(int _S, int _T)
		{
			S=_S, T=_T;
			F ans=0;
			while(bfs())
			{
				F x;
				memcpy(cur, hd, N*sizeof*hd);
				for(bool ok=0;x=dfs(S, 1);)//1 because of special case. Normally it's INF
					if(x) ans+=x, ok=1;
					else if(ok) break;
					else return ans;
			}
			return ans;
		}
};

MaxFlow<int, MN*MN*2, MN*MN*6> maxflow;

int N, M, cnt;
char a[MN][MN];

int main()
{
	scanf("%d%d", &N, &M);
	maxflow.init(N*M*2+2);
	for(int i=0;i<N;++i)
		scanf(" %s", a[i]);
	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
			if(a[i][j]=='#')
			{
				int u=i&&a[i-1][j]=='#'?i*M+j<<1:-1;
				int d=i+1<N&&a[i+1][j]=='#'?(i+1)*M+j<<1:-1;
				int l=j&&a[i][j-1]=='#'?i*M+j<<1|1:-1;
				int r=j+1<M&&a[i][j+1]=='#'?i*M+j+1<<1|1:-1;
				if(~u&&~r) maxflow.adde(u, r, 1);//here, 1 can be INF
				if(~u&&~l) maxflow.adde(u, l, 1);
				if(~d&&~r) maxflow.adde(d, r, 1);
				if(~d&&~l) maxflow.adde(d, l, 1);
				++cnt;
				cnt -= (u!=-1) + (l!=-1);
			}
	for(int i=0;i<N*M;++i)
	{
		maxflow.adde(N*M*2, i*2, 1);
		maxflow.adde(i*2+1, N*M*2+1, 1);
	}
	printf("%d\n", cnt+maxflow.saturate(N*M*2, N*M*2+1));
	return 0;
}