#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;
const int inf = 0x3f3f3f3f;

struct Segment_Tree
{
	int mn[MAXN<<2], tag[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u){ mn[u] = min(mn[ls(u)], mn[rs(u)]);}
	inline void push_down(int u)
	{
		mn[ls(u)] += tag[u]; tag[ls(u)] += tag[u];
		mn[rs(u)] += tag[u]; tag[rs(u)] += tag[u];
		tag[u] = 0;
	}
	
	void update(int u,int l,int r, int q,int k)
	{
		if(l==r){ mn[u]=k; return;}
		push_down(u);
		int mid = (l+r)>>1;
		if(q<=mid) update(lson(u), q,k);
		else update(rson(u), q,k);
		push_up(u);
	}
	
	void update(int u,int l,int r, int ql,int qr,int k)
	{
		if(ql<=l && r<=qr){ mn[u]+=k; tag[u]+=k; return;}
		push_down(u);
		int mid = (l+r)>>1;
		if(ql<=mid) update(lson(u), ql,qr,k);
		if(mid<qr) update(rson(u), ql,qr,k);
		push_up(u);
	}
	
	int query(int u,int l,int r, int ql,int qr)
	{
		if(ql<=l && r<=qr) return mn[u];
		push_down(u);
		int mid = (l+r)>>1, res=inf;
		if(ql<=mid) res = min(res, query(lson(u), ql,qr));
		if(mid<qr) res = min(res, query(rson(u), ql,qr));
		return res;
	}
};

int n;
vector<pii> g[MAXN];
int a[MAXN];
bool is[MAXN];

int size[MAXN];
void dfs_size(int u)
{
	size[u] = is[u];
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i].second;
		dfs_size(v);
		size[u] += size[v];
	}
}

int val[MAXN];
void dfs_val(int u)
{
	int now = is[u];
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i].second;
		
		val[v] = val[u] + now;
		
		dfs_val(v);
		now += size[v];
		
		val[v] = val[v] - val[u];
	}
}

int ans[MAXN];
Segment_Tree tree;

void dfs_ans(int u, int fa, int dep)
{
	if(u)
	{
		tree.update(1,0,n, 0,dep-1, val[u]);
		
		ans[u] = ans[fa] + 1;
		if(is[u]) ans[u] = min(ans[u], tree.query(1,0,n, 0,dep-1) + 1);
		
		tree.update(1,0,n, dep, ans[u]);
	}
	
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i].second;
		dfs_ans(v, u, dep+1);
	}
	
	if(u) tree.update(1,0,n, 0,dep-1, -val[u]);
}

int main(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
	{
		int p;
		scanf("%d",&p);
		char c = getchar();
		while(c<'a' || c>'z') c=getchar();
		g[p].push_back(make_pair(c-'a', i));
	}
	int d;
	scanf("%d",&d);
	for(int i=1; i<=d; ++i)
	{
		scanf("%d",&a[i]);
		is[a[i]] = 1;
	}
	
	for(int i=0; i<=n; ++i)
		sort(g[i].begin(), g[i].end());
	
	dfs_size(0);
	dfs_val(0);
	dfs_ans(0, 0, 0);
	
	//for(int i=1; i<=n; ++i) printf("val %d: %d\n",i,val[i]); putchar('\n');
	//for(int i=1; i<=n; ++i) printf("ans %d: %d\n",i,ans[i]); putchar('\n');
	
	for(int i=1; i<=d; ++i)
		printf("%d ",ans[a[i]]);
	return 0;
}