#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int inf = 0x3f3f3f3f;

struct Segment_Tree
{
	ll mn[MAXN<<2], tag[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u)
	{
		mn[u] = min(mn[ls(u)], mn[rs(u)]);
	}
	inline void upd(int u,ll k)
	{
		mn[u] += k; tag[u] += k;
	}
	inline void push_down(int u)
	{
		if(tag[u])
		{
			upd(ls(u), tag[u]); upd(rs(u), tag[u]);
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
	void update(int u,int l,int r,int ql,int qr,ll k)
	{
		if(ql<=l && r<=qr){ upd(u,k); return;}
		push_down(u);
		int mid = (l+r)>>1;
		if(ql<=mid) update(lson(u),ql,qr,k);
		if(mid<qr) update(rson(u),ql,qr,k);
		push_up(u);
	}
	int fir_leq(int u,int l,int r,int q,ll k)
	{
		if(mn[u] > k) return inf;
		if(l == r) return l;
		push_down(u);
		int mid = (l+r)>>1;
		if(q<=mid)
		{
			int res = fir_leq(lson(u),q,k);
			if(res != inf) return res;
		}
		return fir_leq(rson(u),q,k);
	}
	
	int n;
	inline void build(int _n){ n = _n; build(1,1,n);}
	inline void update(int ql,int qr,ll k){ if(ql<=qr) update(1,1,n,ql,qr,k);}
	inline int fir_leq(int q,ll k){ return q<=n? fir_leq(1,1,n,q,k): inf;}
}tree;

inline pii chk(pii x,pii y)
{
	int xl = x.second - x.first, yl = y.second - y.first;
	if(xl != yl)
		return xl > yl? x: y;
	else
		return min(x,y);
}

inline pii get_res(int a[],int n,int K,int d)
{
	if(d == 0) return {1,n};
	
	static int stamn[MAXN], stamx[MAXN];
	int tpmn = 0, tpmx = 0;
	tree.build(n);
	
	pii res = {1,1};
	int mnl = 1;
	map<int,int> lst;
	for(int i=1; i<=n; ++i)
	{
		if(lst.find(a[i]) != lst.end())
			mnl = max(mnl, lst[a[i]] + 1);
		lst[a[i]] = i;
		
		while(tpmx && a[stamx[tpmx]] <= a[i])
		{
			int j = stamx[tpmx--];
			tree.update(stamx[tpmx]+1, j, -a[j]);
		}
		while(tpmn && a[stamn[tpmn]] >= a[i])
		{
			int j = stamn[tpmn--];
			tree.update(stamn[tpmn]+1, j, a[j]);
		}
		
		tree.update(1, i-1, -1);
		tree.update(stamx[tpmx]+1, i, a[i]);
		tree.update(stamn[tpmn]+1, i, -a[i]);
		
		stamx[++tpmx] = stamn[++tpmn] = i;
		
		int lef = tree.fir_leq(mnl, K);
		if(lef <= i) res = chk(res, {lef, i});
	}
	return res;
}

int a[MAXN], b[MAXN];

int main(void)
{
	int n,K,d;
	scanf("%d%d%d",&n,&K,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i)
	{
		if(d == 0) b[i] = a[i];
		else
		{
			b[i] = (a[i] % d + d) % d;
			a[i] = (a[i] - b[i]) / d;
		}
	}
	
	pii ans = {1,1};
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && b[i] == b[j]) ++j;
		pii cur = get_res(a+i-1, j-i, K, d);
		cur.first += i-1; cur.second += i-1;
		ans = chk(ans, cur);
	}
	printf("%d %d",ans.first,ans.second);
	return 0;
}