#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <utility>
#include <functional>
#include <vector>
#include <queue>

template<int MN, int MM, typename F, typename C> struct MinCostMaxFlow
{
public:
	F flow[MM*2], cap[MM*2];
	C cost[MM*2], pi[MN], d[MN];
	int N, hd[MN], nx[MM*2], to[MM*2], M, par[MN], v[MN];
	void add1(int a, int b, F f, C p)
	{
		flow[M] = 0, cap[M] = f, cost[M] = p;
		nx[M]=hd[a], hd[a]=M, to[M]=b;
		++M;
	}
	void add(int a, int b, F f, C p)//one-directional flow
	{
		add1(a, b, f, p);
		add1(b, a, 0, -p);
	}
	void init(int n)
	{
		N=n;
		memset(hd, -1, N*sizeof*hd);
	}
	void setpi(int S)
	{
		std::queue<int> q;
		q.push(S);
		for(;!q.empty();)
		{
			int n=q.front(); q.pop();
			assert(v[n]++ < N);
			for(int id=hd[n],x;~id;id=nx[id])
				if(cap[id]-flow[id]>0) //CHECK FLOAT POINT
				{
					x=to[id];
					if(!v[x])
						v[x]=1, d[x]=pi[n]+cost[id], q.push(x);
					else if(pi[n]+cost[id]<d[x]) //CHECK FLOAT POINT
						d[x]=pi[n]+cost[id], q.push(x);
				}
		}
	}
	std::priority_queue<std::pair<C, int>, std::vector<std::pair<C, int> >, std::greater<std::pair<C, int> > > q;
	void dijk(int S)
	{
		q.push({0, S});
		for(;!q.empty();)
		{
			int n=q.top().second;q.pop();
			if(v[n]) continue;
			v[n] = 1;
			for(int id=hd[n];~id;id=nx[id])
				if(cap[id] - flow[id] > 0)//CHECK FLOAT POINT
				{
					int x=to[id];
					if(v[x]) continue;
					C w = pi[n]+cost[id]-pi[x];
					if(!~par[x] || w+d[n]<d[x])//CHECK FLOAT POINT
						d[x]=w+d[n], par[x]=id, q.push({d[x], x});
				}
		}
	}
	std::pair<F, C> max_flow(int S, int T)
	{
		std::pair<F, C> ans(0,0);
		pi[S] = d[S] = 0;
		setpi(S);//spfa/bellman ford. Technically dijk works in this case but w/e
		for(;;)
		{
			memset(par, -1, N*sizeof*par);
			memset(v, 0, N*sizeof*v);
			dijk(S);
			if(!~par[T])
				return ans;
			C p = d[T] + pi[T] - pi[S];//technically pi[S] should be zero anyways
			F f = cap[par[T]]-flow[par[T]];//or infinity
			for(int n=T;n!=S;n=to[par[n]^1])
				f = std::min(f, cap[par[n]]-flow[par[n]]);
			ans.first += f;
			ans.second += f*p;
			for(int n=T;n!=S;n=to[par[n]^1])
				flow[par[n]] += f, flow[par[n]^1] -= f;
			for(int i=0;i<N;++i)
				pi[i] += d[i];
		}
	}
};
MinCostMaxFlow<200, 3000, int, int> maxflow;

const int MN = 110;
int N, a[MN], b[MN], T;
char t[MN], s[MN*MN];
int main(void)
{
	scanf(" %s", t);
	for(;t[T];++T);
	std::sort(t, t+T);
	scanf("%d", &N);
	for(int i=0;i<N;++i)
	{
		scanf(" %s%d", s+a[i], b+i);
		for(a[i+1]=a[i];s[a[i+1]];++a[i+1]);
		std::sort(s+a[i], s+a[i+1]);
	}
	maxflow.init(N+28);//26 chars, source, sink
	int src=N+26, snk=N+27;
	for(int i=0,j=0;i<26;++i)
	{
		int f=0;
		for(;j<T&&t[j]-'a'==i;++j)++f;
		if(f) maxflow.add(src, i, f, 0);
	}
	for(int i=0;i<N;++i)
	{
		for(int j=0,k=a[i];j<26;++j)
		{
			int f=0;
			for(;k<a[i+1]&&s[k]-'a'==j;++k)++f;
			if(f) maxflow.add(j, i+26, f, 0);
		}
		maxflow.add(i+26, snk, b[i], i+1);
	}
	auto flow=maxflow.max_flow(src, snk);
	//printf("%d, %d\n", flow.first, flow.second);
	if(flow.first < T)
		printf("-1\n");
	else
		printf("%d\n", flow.second);
	return 0;
}