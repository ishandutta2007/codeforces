#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXP = MAXN * 200;

int lb[MAXN];

struct Segment_Tree
{
	int sum[MAXP], ls[MAXP], rs[MAXP], cnt;
	Segment_Tree(): cnt(0) {}
	#define lson(u) ls[u],l,mid
	#define rson(u) rs[u],mid+1,r
	void update(int &u,int l,int r,int q,int k)
	{
		if(!u) u=++cnt, sum[u] = ls[u] = rs[u] = 0;
		sum[u] += k;
		if(l==r) return;
		int mid = (l+r)>>1;
		if(q<=mid) update(lson(u),q,k);
		else update(rson(u),q,k);
	}
	int query(int u,int l,int r,int ql,int qr)
	{
		if(!u) return 0;
		if(ql<=l && r<=qr) return sum[u];
		int mid = (l+r)>>1, res=0;
		if(ql<=mid) res += query(lson(u), ql,qr);
		if(mid<qr) res += query(rson(u), ql,qr);
		return res;
	}
};

struct Seg_BIT
{
	int root[MAXN], n, m;
	Segment_Tree tree;
	#define lowbit(x) ((x)&-(x))
	void clear(void){ memset(root,0,sizeof(root));}
	inline void update(int x,int k)
	{
		while(x<=n)
			tree.update(root[x],1,m,k,1),
			x+=lowbit(x);
	}
	inline int query(int x,int l,int r)
	{
		int res=0;
		while(x)
			res += tree.query(root[x],1,m,l,r),
			x^=lowbit(x);
		return res;
	}
	inline int query(int x,int y,int l,int r){ return query(y,l,r) - query(x-1,l,r);}
};

struct Edge
{
	int next,to;
}e[MAXN];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot]=(Edge){ head[u],v};
	head[u]=etot;
}

int pre[MAXN];

int size[MAXN], dep[MAXN];
void dfs_size(int u)
{
	size[u] = 1;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		dep[v] = dep[u] + 1;
		dfs_size(v);
		size[u] += size[v];
	}
}

int son[MAXN], dfn[MAXN], seq[MAXN], cur=0, top[MAXN];
void dfs_son(int u,int tp)
{
	seq[++cur] = u;
	dfn[u] = cur;
	top[u] = tp;
	
	son[u] = -1;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(son[u] == -1 || size[son[u]] < size[v])
			son[u] = v;
	}
	if(son[u] == -1) return;
	
	dfs_son(son[u],tp);
	for(int i=head[u]; i; i=e[i].next)
		if(e[i].to != son[u])
			dfs_son(e[i].to, e[i].to);
}

int lca(int u,int v)
{
	while(top[u] != top[v])
		dep[top[u]] > dep[top[v]]? u = pre[top[u]]: v = pre[top[v]];
	return dep[u]<dep[v]? u: v; 
}

int n,m;
int del[MAXN];
Seg_BIT bit;

inline bool can(int u,int l,int r){ return del[u]<l || del[u]>r;}

int get_tot(int u,int v,int l,int r)
{
	int res = dep[u] - dep[v] + 1;
	while(top[u] != top[v])
		res -= bit.query(dfn[top[u]], dfn[u], l,r),
		u = pre[top[u]];
	return res - bit.query(dfn[v], dfn[u], l,r);
}

int get_ans(int u,int v,int d,int l,int r)
{
	int uv = lca(u,v);
	int totu = get_tot(u,uv,l,r) - can(u,l,r);
	int totv = get_tot(v,uv,l,r) - can(v,l,r);
	int tot = totu + totv - can(uv,l,r);
	
	if(tot < d) return -1;
	if(totu < d) swap(u,v), d = tot-d+1;
	
	while(d)
	{
		if(u==top[u]){ u=pre[u]; d-=can(u,l,r); continue;}
		
		int cnt = dep[u] - dep[top[u]] - bit.query(dfn[top[u]], dfn[pre[u]], l,r);
		if(cnt < d){ u=top[u]; d-=cnt; continue;}
		
		for(int i = lb[dep[u] - dep[top[u]]]; i>=0; --i) if(i <= lb[dep[u] - dep[top[u]]])
		{
			int v = seq[dfn[u] - (1<<i)], res = (1<<i) - bit.query(dfn[v], dfn[pre[u]], l,r);
			if(res < d)
				d -= res,
				u = v;
		}
		return pre[u];
	}
	return u;
}

int main(void)
{
	lb[1] = 0;
	for(int i=2; i<MAXN; ++i) lb[i] = lb[i>>1] + 1;
	
	scanf("%d",&n);
	int rt;
	for(int i=1; i<=n; ++i)
	{
		scanf("%d",&pre[i]);
		if(pre[i]) add(pre[i],i);
		else rt = i;
	}
	
	dfs_size(rt);
	dfs_son(rt,rt);
	
	scanf("%d",&m);
	bit.n = n;
	bit.m = m;
	for(int k=1; k<=m; ++k)
	{
		int oper;
		scanf("%d",&oper);
		if(oper==1)
		{
			int u;
			scanf("%d",&u);
			del[u] = k;
			bit.update(dfn[u],k);
		}
		else
		{
			int u,v,d,y;
			scanf("%d%d%d%d",&u,&v,&d,&y);
			printf("%d\n",get_ans(u,v,d,y+1,k));
		}
	}
	return 0;
}