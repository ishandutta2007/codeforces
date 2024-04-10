#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXQ = 2e5 + 5;
const int inf = 0x3f3f3f3f;

struct Segment_Tree_add
{
	ll sum[MAXN<<2], tag[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u){ sum[u] = sum[ls(u)] + sum[rs(u)];}
	inline void push_down(int u,int len)
	{
		if(tag[u])
		{
			sum[ls(u)] += tag[u] * ((len+1)>>1);
			sum[rs(u)] += tag[u] * (len>>1);
			tag[ls(u)] += tag[u]; tag[rs(u)] += tag[u];
			tag[u] = 0;
		}
	}
	void update(int u,int l,int r,int ql,int qr,ll k)
	{
		if(ql<=l && r<=qr){ sum[u] += (r-l+1) * k; tag[u] += k; return;}
		push_down(u, r-l+1);
		int mid = (l+r)>>1;
		if(ql<=mid) update(lson(u),ql,qr,k);
		if(mid<qr) update(rson(u),ql,qr,k);
		push_up(u);
	}
	ll query(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr) return sum[u];
		push_down(u, r-l+1);
		int mid = (l+r)>>1;
		ll res = 0;
		if(ql<=mid) res += query(lson(u),ql,qr);
		if(mid<qr) res += query(rson(u),ql,qr);
		return res;
	}
	
	int n;
	inline void update(int ql,int qr,ll k){ if(ql<=qr) update(1,1,n,ql,qr,k);}
	inline ll query(int ql,int qr){ return ql<=qr? query(1,1,n,ql,qr): 0;}
}tsum;

struct Segment_Tree_Beats
{
	int fir[MAXN<<2], sec[MAXN<<2], cnt[MAXN<<2], tag[MAXN<<2];
	inline void push_up(int u)
	{
		int l = ls(u), r = rs(u);
		if(fir[l] == fir[r])
		{
			fir[u] = fir[l]; cnt[u] = cnt[l] + cnt[r];
			sec[u] = max(sec[l], sec[r]);
		}
		else
		{
			if(fir[l] < fir[r]) swap(l, r);
			fir[u] = fir[l]; cnt[u] = cnt[l];
			sec[u] = max(sec[l], fir[r]);
		}
	}
	inline void upd(int u,int k)
	{
		fir[u] += k; tag[u] += k;
	}
	inline void push_down(int u)
	{
		if(tag[u])
		{
			int l = ls(u), r = rs(u);
			if(fir[l] == fir[r])
				upd(l, tag[u]), upd(r, tag[u]);
			else if(fir[l] > fir[r])
				upd(l, tag[u]);
			else
				upd(r, tag[u]);
			tag[u] = 0;
		}
	}
	void build(int u,int l,int r)
	{
		if(l == r)
		{
			fir[u] = l; sec[u] = -inf;
			cnt[u] = 1;
			tsum.update(l, l, 1);
			return;
		}
		int mid = (l+r)>>1;
		build(lson(u)); build(rson(u));
		push_up(u);
	}
	void update(int u,int l,int r,int ql,int qr,int k)
	{
		if(fir[u] <= k) return;
		if(ql<=l && r<=qr && sec[u] <= k)
		{
			tsum.update(k+1, fir[u], -cnt[u]);
			upd(u, k - fir[u]);
			return;
		}
		push_down(u);
		int mid = (l+r)>>1;
		if(ql<=mid) update(lson(u),ql,qr,k);
		if(mid<qr) update(rson(u),ql,qr,k);
		push_up(u);
	}
	void set(int u,int l,int r,int q,int k)
	{
		if(l == r)
		{
			tsum.update(l, fir[u], -1);
			fir[u] = k;
			tsum.update(l, fir[u], 1);
			return;
		}
		push_down(u);
		int mid = (l+r)>>1;
		if(q<=mid) set(lson(u),q,k);
		else set(rson(u),q,k);
		push_up(u);
	}
}tree;

int main(void)
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	
	tsum.n = n;
	tree.build(1,1,n);
	while(Q--)
	{
		int type,x,y;
		scanf("%d%d%d",&type,&x,&y);
		if(type == 1)
		{
			if(x>1)	tree.update(1,1,n, 1,x-1, x-1);
			tree.set(1,1,n, x, y);
		}
		else
		{
			printf("%lld\n",tsum.query(x,y));
		}
	}
	return 0;
}