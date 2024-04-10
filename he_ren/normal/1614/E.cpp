#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int maxx = 1e9;
const int MAXP = MAXN * 100;
const int inf = 0x3f3f3f3f;

namespace Segment_Tree
{
	int ls[MAXP], rs[MAXP], tag[MAXP], mn[MAXP], pcnt = 0, rt = 0;
	#define lson(u) ls[u],l,mid
	#define rson(u) rs[u],mid+1,r
	void push_up(int u,int l)
	{
		mn[u] = ls[u]? mn[ls[u]] + tag[u]: l + tag[u];
	}
	void upd(int u,int k){ mn[u] += k; tag[u] += k;}
	
	void update(int &u,int l,int r,int ql,int qr,int k)
	{
		if(!u) u = ++pcnt, mn[u] = l;
		if(ql<=l && r<=qr){ upd(u,k); return;}
		int mid = (l+r)>>1;
		if(ql<=mid) update(lson(u),ql,qr,k);
		if(mid<qr) update(rson(u),ql,qr,k);
		push_up(u,l);
	}
	int lst_leq(int u,int l,int r,int k)
	{
		if(!u) return l > k? -inf: min(k, r);
		if(mn[u] > k) return -inf;
		if(l == r) return l;
		k -= tag[u];
		int mid = (l+r)>>1, res = lst_leq(rson(u), k);
		if(res != -inf) return res;
		else return lst_leq(lson(u), k);
	}
	int query(int u,int l,int r,int q)
	{
		if(!u) return q;
		if(l == r) return q + tag[u];
		int mid = (l+r)>>1;
		return (q<=mid? query(lson(u),q): query(rson(u),q)) + tag[u];
	}
	
	inline void update(int ql,int qr,int k)
	{
		ql = max(ql, 0); qr = min(qr, maxx);
		if(ql<=qr) update(rt, 0, maxx, ql, qr, k);
	}
	inline int lst_leq(int k)
	{
		return lst_leq(rt, 0, maxx, k);
	}
	inline int query(int q)
	{
		return query(rt, 0, maxx, q);
	}
} using namespace Segment_Tree;

int ts[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	
	int ans = 0;
	for(int k=1; k<=n; ++k)
	{
		int totq;
		scanf("%d%d",&ts[k],&totq);
		{
			int cur = ts[k];
			int l = lst_leq(cur - 1) + 1, r = lst_leq(cur);
			update(0, l-1, 1);
			update(r+1, maxx, -1);
		}
		
		while(totq--)
		{
			int x;
			scanf("%d",&x);
			x = ((ll)x + ans) % (maxx + 1);
			ans = query(x);
			printf("%d\n",ans);
		}
	}
	return 0;
}