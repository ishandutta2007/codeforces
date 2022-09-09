#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXD = 1e4 + 5;
const int MAXQ = 1e5 + 5;
const int MAXDSC = MAXQ * 2 + MAXD;
const int inf = 0x3f3f3f3f;

template<const int MAXN>
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
		if(tag[u])
			mn[ls(u)] = tag[ls(u)] = mn[rs(u)] = tag[rs(u)] = tag[u],
			tag[u] = 0;
	}
	void build(int u,int l,int r,int val[])
	{
		tag[u] = 0;
		if(l==r){ mn[u] = val[l]; return;}
		int mid = (l+r)>>1;
		build(lson(u),val); build(rson(u),val);
		push_up(u);
	}
	void update(int u,int l,int r,int ql,int qr,int k)
	{
		if(ql<=l && r<=qr){ mn[u] = tag[u] = k; return;}
		push_down(u);
		int mid = (l+r)>>1;
		if(ql<=mid) update(lson(u),ql,qr,k);
		if(mid<qr) update(rson(u),ql,qr,k);
		push_up(u);
	}
	int query(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr) return mn[u];
		push_down(u);
		int mid = (l+r)>>1, res = inf;
		if(ql<=mid) res = min(res, query(lson(u),ql,qr));
		if(mid<qr) res = min(res, query(rson(u),ql,qr));
		return res;
	}
};

struct Query
{
	int l,r,x;
	Query(void){}
	Query(int l,int r,int x=0): l(l), r(r), x(x) {}
};

int a[MAXN];
Query q[MAXQ];

int dsc[MAXDSC], dcnt = 0;
Segment_Tree<MAXN> bef;
Segment_Tree<MAXDSC> aft;

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	int Q;
	scanf("%d",&Q);
	for(int i=1; i<=Q; ++i)
	{
		int oper, l, r;
		scanf("%d%d%d",&oper,&l,&r);
		if(oper == 1)
		{
			int x;
			scanf("%d",&x);
			q[i] = Query(l,r,x);
		}
		else q[i] = Query(l,r);
	}
	
	for(int i=1; i<=d; ++i) dsc[++dcnt] = (i-1) * n + 1;
	for(int i=1; i<=Q; ++i)
		dsc[++dcnt] = q[i].l, dsc[++dcnt] = q[i].r+1;
	dsc[++dcnt] = n * d + 1;
	sort(dsc+1,dsc+dcnt+1);
	dcnt = unique(dsc+1,dsc+dcnt+1) - dsc - 1;
	for(int i=1; i<=Q; ++i)
		q[i].l = lower_bound(dsc+1,dsc+dcnt+1, q[i].l) - dsc,
		q[i].r = lower_bound(dsc+1,dsc+dcnt+1, q[i].r+1) - dsc - 1;
	
	static int nval[MAXDSC];
	
	bef.build(1,1,n, a);
	for(int i=1; i<=d; ++i)
	{
		int l = (i-1) * n + 1, r = l + n - 1;
		int pos = lower_bound(dsc+1,dsc+dcnt+1, l) - dsc;
		while(dsc[pos] <= r)
			nval[pos] = bef.query(1,1,n, dsc[pos]-l+1, dsc[pos+1]-l),
			++pos;
	}
	
	aft.build(1,1,dcnt, nval);
	
	for(int i=1; i<=Q; ++i)
	{
		if(q[i].x)
			aft.update(1,1,dcnt, q[i].l,q[i].r, q[i].x);
		else
			printf("%d\n",aft.query(1,1,dcnt, q[i].l,q[i].r));
	}
	return 0;
}