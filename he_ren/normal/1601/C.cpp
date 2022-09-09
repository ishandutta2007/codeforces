#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;

struct Segment_Tree
{
	int tag[MAXN<<2], mn[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u){ mn[u] = min(mn[ls(u)], mn[rs(u)]);}
	inline void push_down(int u)
	{
		if(tag[u])
		{
			mn[ls(u)] += tag[u]; tag[ls(u)] += tag[u];
			mn[rs(u)] += tag[u]; tag[rs(u)] += tag[u];
			tag[u] = 0;
		}
	}
	void build(int u,int l,int r)
	{
		mn[u] = tag[u] = 0;
		if(l == r) return;
		int mid = (l+r)>>1;
		build(lson(u)); build(rson(u));
	}
	void update(int u,int l,int r,int ql,int qr,int k)
	{
		if(ql<=l && r<=qr){ mn[u] += k; tag[u] += k; return;}
		push_down(u);
		int mid = (l+r)>>1;
		if(ql<=mid) update(lson(u),ql,qr,k);
		if(mid<qr) update(rson(u),ql,qr,k);
		push_up(u);
	}
}tree;

struct BIT
{
	int tree[MAXN], n;
	#define lowbit(x) ((x)&-(x))
	inline void clear(int _n){ n = _n; memset(tree,0,(n+1)<<2);}
	inline void update(int x,int k)
	{
		while(x<=n)
			tree[x] += k,
			x += lowbit(x);
	}
	inline int query(int x)
	{
		int res = 0;
		while(x)
			res += tree[x],
			x ^= lowbit(x);
		return res;
	}
}bit;

int a[MAXN], b[MAXN];

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=m; ++i) scanf("%d",&b[i]);
	
	static pii p[MAXN];
	for(int i=1; i<=n; ++i) p[i] = {a[i], i};
	sort(p+1,p+n+1);
	reverse(p+1,p+n+1);
	
	ll ans = 0;
	bit.clear(n);
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && p[i].first == p[j].first) ++j;
		for(int k=i; k<j; ++k)
			ans += bit.query(p[k].second);
		for(int k=i; k<j; ++k)
			bit.update(p[k].second, 1);
	}
	
	sort(b+1,b+m+1);
	reverse(b+1,b+m+1);
	tree.build(1,0,n);
	for(int i=0; i<=n; ++i) tree.update(1,0,n, i,i,n-i);
	
	int x = 1, y = 1;
	for(int i=1; i<=m; ++i)
	{
		while(x <= n && p[x].first > b[i])
			tree.update(1,0,n, p[x].second, n, 1), ++x;
		while(y <= n && p[y].first >= b[i])
			tree.update(1,0,n, 0, p[y].second-1, -1), ++y;
//		printf("%d: %d\n",b[i],tree.mn[1]);
		ans += tree.mn[1];
	}
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}