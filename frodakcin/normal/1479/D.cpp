#include <cstdio>
#include <cassert>
#include <chrono>
#include <random>
#include <vector>
#include <algorithm>

using Rng=std::mt19937;

Rng rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());

using ll = long long;
using ull = unsigned long long;

const int MN = 3e5+10;

//segtree stuff

const int POOL_SZ = 1e5;

struct node
{
	public:
		node *l, *r;
		ull v;
		node(ull _v=0) : l(nullptr), r(nullptr), v(_v) {};
};

node *pool;
int pool_ctr;
node *nn(node *n=nullptr)
{
	if(!pool_ctr) pool = new node[pool_ctr = POOL_SZ];
	node *f = pool+--pool_ctr;
	if(n) *f=*n;
	return f;
}

void upd(node *n, int l, int r, int q, ull v) // assume input is a copy
{
	n->v^=v;
	if(r-l>1)
	{
		int m=l+(r-l)/2;
		if(q<m) upd(n->l=nn(n->l), l, m, q, v);
		else upd(n->r=nn(n->r), m, r, q, v);
	}
}

int find(const std::vector<node*>& a, int l, int r, int ql, int qr) // leftmost
{
	ull v=0;
	for(node* x:a) v^=x->v;
	if(!v) return -1;

	if(r-l>1)
	{
		std::vector<node*> z; z.reserve(a.size());
		int m=l+(r-l)/2;

		if(ql < m)
		{
			for(node* x:a) if(x->l) z.push_back(x->l);
			int f=find(z, l, m, ql, qr);
			if(~f) return f;
			z.clear();
		}
		if(m < qr)
		{
			for(node *x:a) if(x->r) z.push_back(x->r);
			return find(z, m, r, ql, qr);
		}
		return -1;
	}
	else
		return l;
}

//other variables

struct dat
{
	public:
		int n, d;
		bool operator < (const dat& o) const {return d < o.d || !(o.d < d) && n < o.n;}
};

int N, Q, v[MN], p[MN], o[MN], ctr;
ull w[MN];
std::vector<int> a[MN];
dat q[MN*2][20];
node *root[MN];

void dfs(int n=1, int d=0)
{
	upd(root[n]=nn(root[p[n]]), 1, N+1, v[n], w[v[n]]);
	o[n]=ctr;
	q[ctr++][0]={n,d};
	for(int x:a[n])
		if(x!=p[n])
		{
			p[x]=n;
			dfs(x, d+1);
			q[ctr++][0]={n,d};
		}
}

int lca(int a, int b)
{
	if(a==b) return a;
	a=o[a], b=o[b];
	if(b<a) std::swap(a,b);
	assert(a<b);
	int d=31-__builtin_clz(b-a); // msb(b-a) = 1<<d
	return std::min(q[a][d], q[b-(1<<d)][d]).n; // return [a, b)
}

int main()
{
	scanf("%d%d", &N, &Q);
	for(int i=1;i<=N;++i) scanf("%d", v+i);
	for(int i=0,u,v;i+1<N;++i)
		scanf("%d%d", &u, &v), a[u].push_back(v), a[v].push_back(u);
	for(int i=1;i<=N;++i) w[i]=rng()|(ull)rng()<<32;

	dfs();
	assert(ctr == N*2-1); // range: [0, ctr)
	for(int i=ctr-1;i>=0;--i)
		for(int j=0;i+(1<<j+1)<=ctr;++j)
			q[i][j+1]=std::min(q[i][j], q[i+(1<<j)][j]);
	
	std::vector<node*> z; z.reserve(4);
	for(int i=0;i<Q;++i)
	{
		int u,v,l,r;
		scanf("%d%d%d%d", &u, &v, &l, &r);
		int t=lca(u,v);
		if(root[u]) z.push_back(root[u]);
		if(root[v]) z.push_back(root[v]);
		if(root[t]) z.push_back(root[t]);
		if(root[p[t]]) z.push_back(root[p[t]]);
		//printf("%d %d %d\n", u, v, t);
		printf("%d\n", find(z, 1, N+1, l, ++r));
		z.clear();
	}
	
	return 0;
}