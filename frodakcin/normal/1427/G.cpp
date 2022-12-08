#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>

using ll = long long;

const int MN = 2e2+10;
const int MX = MN * MN;
const int MM = MX * 4;

int N, a[MN][MN];
ll ans;

struct Event
{
	public:
		int v, n;
		bool operator < (const Event& o) const {return v < o.v || !(o.v < v) && n < o.n;}
};
std::vector<Event> evt;

int hd[MX], flow[MM*2], cap[MM*2], to[MM*2], nx[MM*2], cur[MX], l[MX], S, T, X, q[MX];
std::vector<int> path;
std::vector<std::vector<int> > paths[MX];

void add1(int a, int b, int f)
{
	nx[X]=hd[a];
	to[X]=b, flow[X]=0, cap[X]=f;
	hd[a]=X++;
}

void adde(int a, int b, int f)
{
	add1(a, b, f);
	add1(b, a, f);
}

bool bfs()
{
	memset(l, -1, (N*N+2)*sizeof*l);
	q[0]=S, l[S]=0;
	for(int i=0,n,Q=1;i<Q;++i)
	{
		n=q[i];
		for(int id=hd[n];~id;id=nx[id])
			if(cap[id]-flow[id]>0 && !~l[to[id]])
				l[q[Q++]=to[id]]=l[n]+1;
	}
	return ~l[T];
}

bool dfs(int n)
{
	if(n==T) return 1;
	for(int &id=cur[n];~id;id=nx[id])
		if(cap[id]-flow[id]>0 && l[n]+1==l[to[id]])
			if(dfs(to[id]))
			{
				++flow[id];//typically would be return value of dfs
				--flow[id^1];
				path.push_back(id);
				return 1;
			}
	return 0;
}

bool bfs_rev(int n)
{
	memset(l, -1, (N*N+2)*sizeof*l);
	q[0]=S, l[S]=-2;
	for(int i=0,n,Q=1;i<Q;++i)
	{
		n=q[i];
		for(int id=hd[n];~id;id=nx[id])
			if(flow[id]>0 && !~l[to[id]])
				l[q[Q++]=to[id]]=id;
	}
	if(!~l[n]) return 0;
	for(;n!=S;n=to[l[n]^1])
		--flow[l[n]], ++flow[l[n]^1];
	return 1;
}

int main(void)
{
	scanf("%d", &N);
	S = N*N, T=N*N+1;
	memset(hd, -1, sizeof hd);
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
		{
			scanf("%d", a[i]+j);
			if(a[i][j]>0)
			{
				evt.push_back({a[i][j], i*N+j});
				adde(i*N+j, T, 3);
			}
		}
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			if(~a[i][j])
			{
				if(i+1<N && ~a[i+1][j])
					adde(i*N+j, (i+1)*N+j, 1);
				if(j+1<N && ~a[i][j+1])
					adde(i*N+j, i*N+j+1, 1);
			}
	std::sort(evt.begin(), evt.end());
	for(int i=0, totf=0;i+1<evt.size();++i)
	{
		int n=evt[i].n;
		{//delete edges
			int *p=hd+n;
			for(;to[*p]!=T;)
				p=nx+*p;
			*p=nx[*p];

			p=hd+T;
			for(;to[*p]!=n;)
				p=nx+*p;
			*p=nx[*p];
		}
		for(;bfs_rev(n);)//reverse
			--totf;
		adde(S, n, 3);//equ to adde(n, S, 3), but bidir should be ok
		while(bfs())
		{
			memcpy(cur, hd, (N*N+2)*sizeof*hd);
			assert(path.empty());
			while(dfs(S))
			{
				paths[to[path[0]^1]].push_back(path); // alternatively, to[path[1]]
				path.clear();
				++totf;
			}
		}
		ans += (ll)(evt[i+1].v-evt[i].v)*totf;
		//printf("%d: %d\n", i, totf);
	}
	printf("%lld\n", ans);
	return 0;
}