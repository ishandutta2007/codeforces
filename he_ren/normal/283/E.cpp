#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;

struct Segment_Tree
{
	int c0[MAXN<<2], c1[MAXN<<2], tag[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u)
	{
		c0[u] = c0[ls(u)] + c0[rs(u)];
		c1[u] = c1[ls(u)] + c1[rs(u)];
	}
	inline void upd(int u)
	{
		tag[u] ^= 1;
		swap(c0[u], c1[u]);
	}
	inline void push_down(int u)
	{
		if(tag[u])
		{
			upd(ls(u)); upd(rs(u));
			tag[u] = 0;
		}
	}
	void build(int u,int l,int r)
	{
		c0[u] = r-l+1; c1[u] = tag[u] = 0;
		if(l == r) return;
		int mid = (l+r)>>1;
		build(lson(u)); build(rson(u));
	}
	void update(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr){ upd(u); return;}
		push_down(u);
		int mid = (l+r)>>1;
		if(ql<=mid) update(lson(u),ql,qr);
		if(mid<qr) update(rson(u),ql,qr);
		push_up(u);
	}
	int query(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr) return c1[u];
		push_down(u);
		int mid = (l+r)>>1, res = 0;
		if(ql<=mid) res += query(lson(u),ql,qr);
		if(mid<qr) res += query(rson(u),ql,qr);
		return res;
	}
}tree;

int s[MAXN], a[MAXM], b[MAXM];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&s[i]);
	
	sort(s+1,s+n+1);
	for(int i=1; i<=m; ++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[i] = lower_bound(s+1,s+n+1,x) - s;
		b[i] = upper_bound(s+1,s+n+1,y) - s - 1;
	}
	
	static vector<int> lef[MAXN], rig[MAXN];
	for(int i=1; i<=m; ++i) if(a[i] <= b[i])
		lef[a[i]].push_back(i),
		rig[b[i]].push_back(i);
	auto upd = [&] (int i)
	{
		if(a[i] <= b[i])
			tree.update(1,1,n, a[i], b[i]);
	};
	
	ll ans = 0;
	
	tree.build(1,1,n);
	for(int i=1; i<=n; ++i)
	{
		for(int x: lef[i]) upd(x);
		int L = i > 1? i-1 - tree.query(1,1,n, 1,i-1): 0;
		int R = i < n? tree.query(1,1,n, i+1,n): 0;
		int k = L + R;
		ans += (ll)k * (k-1) / 2;
		for(int x: rig[i]) upd(x);
	}
	
	ans = (ll)n * (n-1) * (n-2) / 6 - ans;
	printf("%lld",ans);
	return 0;
}