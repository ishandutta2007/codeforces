#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 5;
const int inf = 0x3f3f3f3f;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

const int MAXNN = 5.3e5 + 5;
struct Segment_Tree
{
	int N, mx[MAXNN<<1][2];
	bool tag[MAXNN<<1];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	inline void push_up(int u)
	{
		mx[u][0] = max(mx[ls(u)][0], mx[rs(u)][0]);
		mx[u][1] = max(mx[ls(u)][1], mx[rs(u)][1]);
		if(tag[u]) swap(mx[u][0], mx[u][1]);
	}
	inline void upd_tag(int u){ tag[u]^=1; swap(mx[u][0], mx[u][1]);}
	inline void build(int n,int dep_dfn[])
	{
		N = 1;
		while(N <= n) N<<=1;
		
		memset(tag,0,sizeof(tag));
		for(int i=1; i<=n; ++i)
			mx[i + N][0] = dep_dfn[i],
			mx[i + N][1] = -inf;
		
		for(int i=N-1; i>=1; --i) push_up(i);
	}
	inline void update(int l,int r)
	{
		for(l+=N-1, r+=N+1; l^r^1; l>>=1, r>>=1)
		{
			if(l<N) push_up(l);
			if(r<N) push_up(r);
			if(~l&1) upd_tag(l^1);
			if( r&1) upd_tag(r^1);
		}
		if(l<N) push_up(l);
		if(r<N) push_up(r);
		for(l>>=1; l; l>>=1)
			push_up(l);
	}
	inline int query(int l,int r,int k)
	{
		int resl[2] = {-inf, -inf}, resr[2] = {-inf, -inf};
		for(l+=N-1, r+=N+1; l^r^1; l>>=1, r>>=1)
		{
			if(l<N && tag[l]) swap(resl[0], resl[1]);
			if(r<N && tag[r]) swap(resr[0], resr[1]);
			if(~l&1) chk_max(resl[0], mx[l^1][0]), chk_max(resl[1], mx[l^1][1]);
			if( r&1) chk_max(resr[0], mx[r^1][0]), chk_max(resr[1], mx[r^1][1]);
		}
		for(; l; l>>=1, r>>=1)
		{
			if(l<N && tag[l]) swap(resl[0], resl[1]);
			if(r<N && tag[r]) swap(resr[0], resr[1]);
		}
		return max(resl[k], resr[k]);
	}
};

struct Edge
{
	int next,to;
}e[MAXN<<1];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot] = (Edge){ head[u],v};
	head[u] = etot;
}

struct Edge_uvw
{
	int u,v,w;
};

void dfs_dep(int u,int fa,int dep[])
{
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dep[v] = dep[u] + 1;
		dfs_dep(v,u,dep);
	}
}

int n;

int get_far(int u)
{
	static int dep[MAXN];
	dep[u] = 0;
	dfs_dep(u,0, dep);
	
	int res = u;
	for(int i=1; i<=n; ++i)
		if(dep[i] > dep[res]) res = i;
	return res;
}

struct Solver
{
	int size[MAXN], dfn[MAXN], cur_dfn;
	void dfs_dfn(int u,int fa)
	{
		size[u] = 1;
		dfn[u] = ++cur_dfn;
		for(int i=head[u]; i; i=e[i].next)
		{
			int v = e[i].to;
			if(v == fa) continue;
			dfs_dfn(v,u);
			size[u] += size[v];
		}
	}
	
	int dep[MAXN];
	Segment_Tree tree;
	
	void init(int u)
	{
		dep[u] = 0;
		dfs_dep(u,0, dep);
		
		cur_dfn = 0;
		dfs_dfn(u,0);
		
		static int dep_dfn[MAXN];
		for(int i=1; i<=n; ++i)
			dep_dfn[dfn[i]] = dep[i];
		
		tree.build(n,dep_dfn);
	}
	
	void update(int u,int v)
	{
		if(dep[u] < dep[v]) swap(u,v);
		tree.update(dfn[u], dfn[u] + size[u] - 1);
	}
	
	int query(void){ return tree.query(1,n,0);}
}solver[2];

int main(void)
{
	scanf("%d",&n);
	static Edge_uvw ee[MAXN];
	for(int i=1; i<n; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v); add(v,u);
		ee[i] = (Edge_uvw){u,v,w};
	}
	
	int s = get_far(1);
	int t = get_far(s);
	
	solver[0].init(s);
	solver[1].init(t);
	
	for(int i=1; i<n; ++i) if(ee[i].w)
		solver[0].update(ee[i].u, ee[i].v),
		solver[1].update(ee[i].u, ee[i].v);
	
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int id;
		scanf("%d",&id);
		
		solver[0].update(ee[id].u, ee[id].v);
		solver[1].update(ee[id].u, ee[id].v);
		printf("%d\n",max(solver[0].query(), solver[1].query()));
	}
	return 0;
}