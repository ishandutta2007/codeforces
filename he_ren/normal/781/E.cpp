#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXW = 1e5 + 5;
const int MAXN = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

struct Segment_Tree
{
	stack<pii> sta[MAXW];
	int mn[MAXW << 2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u){ mn[u] = min(mn[ls(u)], mn[rs(u)]);}
	void build(int u,int l,int r,int k)
	{
		mn[u] = k;
		if(l == r){ sta[l].push(make_pair(k, 1)); return;}
		int mid = (l+r)>>1;
		build(lson(u),k); build(rson(u),k);
	}
	void update(int u,int l,int r,int q,pii k)
	{
		mn[u] = min(mn[u], k.first);
		if(l == r){ sta[l].push(k); return;}
		int mid = (l+r)>>1;
		if(q<=mid) update(lson(u),q,k);
		else update(rson(u),q,k);
	}
	int query(int u,int l,int r,int ql,int qr,int k)
	{
		if(mn[u] > k) return 0;
		if(l == r)
		{
			int res = 0;
			while(sta[l].size() && sta[l].top().first <= k)
				add_mod(res, sta[l].top().second),
				sta[l].pop();
			mn[u] = sta[l].size()? sta[l].top().first: inf;
			return res;
		}
		int mid = (l+r)>>1, res = 0;
		if(ql<=mid) add_mod(res, query(lson(u),ql,qr,k));
		if(mid<qr) add_mod(res, query(rson(u),ql,qr,k));
		push_up(u);
		return res;
	}
}tree;

int H,W,n;

struct Board
{
	int u,l,r,s;
}p[MAXN];

namespace Subtask1
{
	inline int cmp_u(int x,int y){ return p[x].u > p[y].u;}
	
	void solve(void)
	{
		for(int i=1; i<=n; ++i)
			p[i].s = min(H+1, p[i].u + p[i].s);
		
		static int id[MAXN];
		for(int i=1; i<=n; ++i) id[i] = i;
		sort(id+1,id+n+1,cmp_u);
		
		tree.build(1,1,W, H+1);
		for(int i=1; i<=n; ++i)
		{
			int cur = id[i], l = p[cur].l, r = p[cur].r;
			int res = tree.query(1,1,W, l, r, p[cur].s);
			
			tree.update(1,1,W, l > 1? l - 1: r + 1, make_pair(p[cur].u, res));
			tree.update(1,1,W, r < W? r + 1: l - 1, make_pair(p[cur].u, res));
		}
		
		printf("%d",tree.query(1,1,W, 1, W, H+1));
		exit(0);
	}
}

int main(void)
{
	scanf("%d%d%d",&H,&W,&n);
	for(int i=1; i<=n; ++i)
		scanf("%d%d%d%d",&p[i].u, &p[i].l, &p[i].r, &p[i].s);
	
	Subtask1::solve();
	return 0;
}