#include<cstdio>
typedef long long ll;
const int MAXN = 4e5 + 5;
const int MAXM = 4e5 + 5;

struct Edge
{
	int next,to;
}e[MAXN*2];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	++etot;
	e[etot] = (Edge){ head[u],v};
	head[u] = etot;
}

#define lowbit(x) ((x)&-(x))

int c[MAXN];

struct Node
{
	int l,r;
}p[MAXN];
int fa[MAXN];
int a[MAXN];
void dfs(int u,int l)
{
	int pos=l;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa[u]) continue;
		fa[v]=u;
		dfs(v,pos);
		pos = p[v].r+1;
	}
	p[u] = (Node){l,pos};
	a[pos] = c[u];
}

ll ans[MAXN<<2];
int tag[MAXN<<2];
#define ls(u) ((u)<<1)
#define rs(u) ((u)<<1 | 1)

inline void push_up(int u)
{
	ans[u] = ans[ls(u)] | ans[rs(u)];
}

inline void push_down(int u)
{
	if(!tag[u]) return;
	tag[ls(u)]=tag[rs(u)]=tag[u];
	ans[ls(u)]=ans[rs(u)]=1ll<<tag[u];
	tag[u]=0;
}

void build(int u,int l,int r)
{
	if(l==r)
	{
		ans[u] = 1ll<<a[l];
		return;
	}
	
	int mid = (l+r)>>1;
	build(ls(u),l,mid);
	build(rs(u),mid+1,r);
	push_up(u);
}

void update(int u,int l,int r, int ql,int qr,int q)
{
	if(ql<=l && r<=qr)
	{
		tag[u] = q;
		ans[u] = 1ll<<q;
		return;
	}
	
	push_down(u);
	int mid = (l+r)>>1;
	if(ql<=mid)
		update(ls(u),l,mid, ql,qr,q);
	if(mid<qr)
		update(rs(u),mid+1,r, ql,qr,q);
	push_up(u);
}

ll query(int u,int l,int r, int ql,int qr)
{
	if(ql<=l && r<=qr) return ans[u];
	
	push_down(u);
	int mid = (l+r)>>1;
	ll res=0;
	if(ql<=mid)
		res|=query(ls(u),l,mid, ql,qr);
	if(mid<qr)
		res|=query(rs(u),mid+1,r, ql,qr);
	return res;
}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&c[i]);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	dfs(1,1);
	build(1,1,n);
	
	while(m--)
	{
		int t,u;
		scanf("%d%d",&t,&u);
		if(t==1)
		{
			int qc;
			scanf("%d",&qc);
			update(1,1,n, p[u].l,p[u].r,qc);
		}
		else
		{
			ll tmp = query(1,1,n, p[u].l,p[u].r);
			int res=0;
			while(tmp)
				++res, tmp^=lowbit(tmp);
			printf("%d\n",res);
		}
	}
	return 0;
}