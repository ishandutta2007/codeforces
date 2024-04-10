#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXD = MAXN * 2;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
 
inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}
 
struct Segment_Tree
{
	pii tree[MAXD<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void upd(pii &p,const pii &q)
	{
		if(p.first == q.first) add_mod(p.second, q.second);
		else if(p.first > q.first) p = q;
	}
	inline void push_up(int u)
	{
		if(tree[ls(u)].first != tree[rs(u)].first)
			tree[u] = min(tree[ls(u)], tree[rs(u)]);
		else tree[u] = make_pair(tree[ls(u)].first, (tree[ls(u)].second + tree[rs(u)].second) %mod);
	}
	void build(int u,int l,int r)
	{
		tree[u] = make_pair(inf,0);
		if(l==r) return;
		int mid = (l+r)>>1;
		build(lson(u)); build(rson(u));
	}
	void update(int u,int l,int r,int q,pii k)
	{
		if(l==r){ upd(tree[u], k); return;}
		int mid = (l+r)>>1;
		if(q<=mid) update(lson(u),q,k);
		else update(rson(u),q,k);
		push_up(u);
	}
	pii query(int u,int l,int r, int ql,int qr)
	{
		if(ql<=l && r<=qr) return tree[u];
		int mid = (l+r)>>1; pii res(inf, 0);
		if(ql<=mid) upd(res, query(lson(u), ql,qr));
		if(mid<qr) upd(res, query(rson(u), ql,qr));
		return res;
	}
};
 
pii p[MAXN];
 
int f[MAXN], g[MAXN];
 
int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d%d",&p[i].first,&p[i].second);
	
	sort(p+1,p+n+1);
	
	static int dsc[MAXD], dcnt = 0;
	dsc[++dcnt] = 0;
	for(int i=1; i<=n; ++i)
		dsc[++dcnt] = p[i].first,
		dsc[++dcnt] = p[i].second;
	sort(dsc+1,dsc+dcnt+1);
	dcnt = unique(dsc+1,dsc+dcnt+1) - dsc - 1;
	for(int i=1; i<=n; ++i)
		p[i].first = lower_bound(dsc+1,dsc+dcnt+1, p[i].first) - dsc,
		p[i].second = lower_bound(dsc+1,dsc+dcnt+1, p[i].second) - dsc;
	
	int mxl = 0;
	for(int i=1; i<=n; ++i)
		mxl = max(mxl, p[i].second);
	
	static Segment_Tree tree;
	tree.build(1,1,dcnt);
	
	tree.update(1,1,dcnt, 1, make_pair(0,1));
	
	pii ans = make_pair(inf,0);
	for(int i=1; i<=n; ++i)
	{
		int l = p[i].second, r = p[i].first;
		pii res = tree.query(1,1,dcnt, 1,l);
		
		f[i] = res.first + dsc[l];
		g[i] = res.second;
		tree.update(1,1,dcnt, r, make_pair(f[i] - dsc[r], g[i]));
		
		if(r > mxl) tree.upd(ans, make_pair(f[i],g[i]));
	}
	
	printf("%d\n",ans.second);
	return 0;
}