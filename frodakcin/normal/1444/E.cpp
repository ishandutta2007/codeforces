#include <cstdio>
#include <cassert>
#include <vector>
#include <functional>

const int MN = 1e2+10;

template<int S=MN> struct Dat
{
	public:
		bool v[S];
		void fill(bool _v=1)
		{
			for(int i=0;i<S;++i)
				v[i]=_v;
		}
		Dat(bool _v=0)
		{
			fill(_v);
		}
		void flip(int i) {v[i]^=1;}
		bool& operator [] (const int& x) {return v[x];}
};
using dat = Dat<MN>;

struct Edge
{
	public:
		int n, i;
};

struct Edge2
{
	public:
		int u, v;
};

int N, u[MN], w[MN], W;
std::vector<Edge> a[MN];
Edge2 e[MN];
dat dp[MN];

void dfs(int n, int p=0)
{
	std::vector<int> c[MN+1], t[2];
	int C=0;
	for(Edge x:a[n])
		if(x.n!=p)
			dfs(x.n, n), c[0].push_back(x.n), ++C;
	//dp[n] = union(dp[c[...]])
	dp[n].fill();
	for(int i=0;i<MN;++i)
	{
		for(int x:c[i])
			t[dp[x][i]].push_back(x);
		for(int j=1;j>=0;--j)
			for(int x:t[j])
			{
				c[i+1].push_back(x);
				t[j].clear();
			}
	}
	std::function<bool(void)> check=[&]()->bool
	{
		for(int x:c[0])
			u[x]=-1;
		bool ok=1;
		for(int i=MN-1;ok && i>=0;--i)
		{
			int ctr=0, z=-1;
			for(int x:c[i])
			{
				ctr += !~u[x] && dp[x][i];
				if(!~z && !~u[x])
					z=x;
			}
			if(!dp[n][i])
			{
				if(ctr)
					ok=0;
			}
			else
				if(ctr>=2)
					ok=0;
				else if(!ctr && ~z)
					u[z]=i;
		}
		for(int x:c[0])
			if(!~u[x])
				return 0;
		return ok;
	};
	for(int i=MN-1;i>=0;--i)
	{
		dp[n].flip(i);
		if(!check())
			dp[n].flip(i);
	}
	assert(check()); // this assert must be called
	for(Edge x:a[n])
		if(x.n!=p)
			w[x.i]=u[x.n];
}

int query(int u, int v)
{
	printf("? %d %d\n", u, v);
	fflush(stdout);
	int r;
	scanf("%d", &r);
	if(!(r==u||r==v))
		exit(0);
	return r;
}

int find(int n, int p=0)
{
	int b=-1;
	for(Edge x:a[n])
		if(w[x.i]<W && x.n!=p)
		{
			if(!~b || w[b] < w[x.i])
				b=x.i;
			int t=find(x.n, n);
			if(~t && (!~b || w[b] < w[t]))
				b=t;
		}
	return b;
}

int main()
{
	scanf("%d", &N);
	for(int i=0;i+1<N;++i)
	{
		int u,v;
		scanf("%d%d", &u, &v);
		e[i]={u,v};
		a[u].push_back({v, i});
		a[v].push_back({u, i});
	}
	dfs(1);
	W=N;
	//for(int i=0;i<N-1;++i) printf("%d<->%d: %d\n", e[i].u, e[i].v, w[i]);
	for(int i,n=1;;)
	{
		i=find(n);
		if(!~i) 
		{
			printf("! %d\n", n);
			fflush(stdout);
			break;
		}
		W=w[i];
		n=query(e[i].u, e[i].v);
	}
	return 0;
}