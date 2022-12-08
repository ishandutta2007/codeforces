#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>

template<typename T> bool ckmax(T& a, T b) {return a<b?a=b,1:0;}
template<typename T> bool ckmin(T& a, T b) {return b<a?a=b,1:0;}

template<typename F, int MN, int MM>
struct MaxFlow
{
public:
	int hd[MN], nx[MM*2], to[MM*2], h[MN], N, M, S, T, cur[MN];
	F flow[MM*2], cap[MM*2], e[MN];
	void init(int _N)
	{
		N=_N;
		M=0;
		memset(hd, -1, N*sizeof*hd);
	}
	void add1(int u, int v, F c)
	{
		nx[M]=hd[u], hd[u]=M;
		to[M]=v, flow[M]=0, cap[M]=c;
		++M;
	}
	void add(int u, int v, F f)// 1-dir
	{
		add1(u,v,f);
		add1(v,u,0);
		//printf("%d->%d, %lld\n", u, v, f);
	}
	void push(int n, int i)
	{
		int x=to[i];
		F f=std::min(e[n], cap[i]-flow[i]);
		flow[i]+=f, flow[i^1]-=f;
		e[n]-=f, e[x]+=f;
	}
	void relabel(int n)
	{
		int _h=N*2+10;
		for(int i=hd[n],x;~i;i=nx[i])
			if(cap[i]-flow[i]>0)
				ckmin(_h, h[to[i]]);
		h[n]=_h+1;
	}
	int get_next()
	{
		for(int i=0;i<N;++i)
			if(i!=S&&i!=T&&e[i]>0)
				return i;
		return -1;
	}
	F calc(int _S, int _T)
	{
	 	S=_S, T=_T;
		memset(e, 0, N*sizeof*e);
		memset(cur, -1, N*sizeof*cur);
		h[S]=N, e[S]=1;
		for(int i=hd[S];~i;i=nx[i])
			e[S]+=cap[i], push(S, i);
		for(int n,x;~(n=get_next());)
			for(int& i=cur[n];;)
				if(~i)
				{
					x=to[i];
					if(h[x]+1==h[n]&&cap[i]-flow[i]>0)
					{
						push(n, i);
						if(e[n]<=0)
							break;
					}
					i=nx[i];
				}
				else
					relabel(n), i=hd[n];
		return e[T];
	}
};

using ll = long long;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MN = 1e3+10, MM = 1e3+10;

MaxFlow<ll, MN+MM, MN+MM*3> maxflow;

int N, M, S, T;
ll tot;
int main()
{
	scanf("%d%d", &N, &M);
	maxflow.init(N+M+2);
	S=N+M, T=N+M+1;
	for(int i=0,a;i<N;++i)
		scanf("%d", &a), maxflow.add(i, T, a);
	for(int i=0,u,v,w;i<M;++i)
		scanf("%d%d%d", &u, &v, &w), tot+=w, maxflow.add(S, N+i, w), maxflow.add(N+i, u-1, INF), maxflow.add(N+i, v-1, INF);
	printf("%lld\n", tot-maxflow.calc(S, T));
	/*
	for(int i=maxflow.hd[S],x;~i;i=maxflow.nx[i])
	{
		x=maxflow.to[i];
		printf("PROJ: %d -> %d (%lld/%lld)\n", S, x, maxflow.flow[i], maxflow.cap[i]);
	}
	for(int i=maxflow.hd[T],x;~i;i=maxflow.nx[i])
	{
		x=maxflow.to[i];
		printf("INST: %d -> %d (%lld/%lld)\n", x, T, maxflow.flow[i^1], maxflow.cap[i^1]);
	}
	*/
	return 0;
}