#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int inf = 0x3f3f3f3f;

struct Segment_Tree_add
{
	int tag[MAXN<<2];
	pii mn[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u){ mn[u] = min(mn[ls(u)], mn[rs(u)]);}
	inline void push_down(int u)
	{
		if(tag[u])
		{
			mn[ls(u)].first += tag[u]; tag[ls(u)] += tag[u];
			mn[rs(u)].first += tag[u]; tag[rs(u)] += tag[u];
			tag[u] = 0;
		}
	}
	void build(int u,int l,int r)
	{
		mn[u] = make_pair(0, l);
		if(l == r) return;
		int mid = (l+r)>>1;
		build(lson(u)); build(rson(u));
	}
	void update(int u,int l,int r,int ql,int qr,int k)
	{
		if(ql<=l && r<=qr){ tag[u] += k; mn[u].first += k; return;}
		push_down(u);
		int mid = (l+r)>>1;
		if(ql<=mid) update(lson(u),ql,qr,k);
		if(mid<qr) update(rson(u),ql,qr,k);
		push_up(u);
	}
	pii query(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr) return mn[u];
		push_down(u);
		int mid = (l+r)>>1;
		pii res = make_pair(inf, -1);
		if(ql<=mid) res = min(res, query(lson(u),ql,qr));
		if(mid<qr) res = min(res, query(rson(u),ql,qr));
		return res;
	}
}cnt_pos, cnt_neg;

struct Segment_Tree_mn
{
	int val[MAXN<<2];
	ll sum[MAXN<<2];
	int fir[MAXN<<2], sec[MAXN<<2], tag[MAXN<<2];
	inline void push_up(int u)
	{
		sum[u] = sum[ls(u)] + sum[rs(u)];
		if(fir[ls(u)] == fir[rs(u)])
			fir[u] = fir[ls(u)], sec[u] = max(sec[ls(u)], sec[rs(u)]), val[u] = val[ls(u)] + val[rs(u)];
		else if(fir[ls(u)] > fir[rs(u)])
			fir[u] = fir[ls(u)], sec[u] = max(fir[rs(u)], sec[ls(u)]), val[u] = val[ls(u)];
		else
			fir[u] = fir[rs(u)], sec[u] = max(fir[ls(u)], sec[rs(u)]), val[u] = val[rs(u)];
	}
	inline void push_down(int u)
	{
		if(tag[u])
		{
			if(fir[ls(u)] + tag[u] == fir[u])
				fir[ls(u)] += tag[u], sum[ls(u)] += (ll)tag[u] * val[ls(u)], tag[ls(u)] += tag[u];
			if(fir[rs(u)] + tag[u] == fir[u])
				fir[rs(u)] += tag[u], sum[rs(u)] += (ll)tag[u] * val[rs(u)], tag[rs(u)] += tag[u];
			tag[u] = 0;
		}
	}
	void build(int u,int l,int r)
	{
		if(l == r){ fir[u] = inf; sec[u] = -inf; val[u] = 0; sum[u] = 0; return;}
		int mid = (l+r)>>1;
		build(lson(u)); build(rson(u));
		push_up(u);
	}
	void update_val(int u,int l,int r,int q,int k)
	{
		if(l == r){ val[u] = k; sum[u] = k * fir[u]; return;}
		push_down(u);
		int mid = (l+r)>>1;
		if(q<=mid) update_val(lson(u),q,k);
		else update_val(rson(u),q,k);
		push_up(u);
	}
	void update_mn(int u,int l,int r,int ql,int qr,int k)
	{
		if(fir[u] <= k) return;
		if(ql<=l && r<=qr && sec[u] < k)
		{
			tag[u] += k - fir[u]; sum[u] += (ll)(k - fir[u]) * val[u];
			fir[u] = k;
			return;
		}
		push_down(u);
		int mid = (l+r)>>1;
		if(ql<=mid) update_mn(lson(u),ql,qr,k);
		if(mid<qr) update_mn(rson(u),ql,qr,k);
		push_up(u);
	}
	inline ll query(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr) return sum[u];
		push_down(u);
		int mid = (l+r)>>1;
		ll res = 0;
		if(ql<=mid) res += query(lson(u),ql,qr);
		if(mid<qr) res += query(rson(u),ql,qr);
		return res;
	}
}tree_pos, tree_neg;

int type[MAXN];

int main(void)
{
	int n = 1e5, Q;
	scanf("%d",&Q);
	
	cnt_pos.build(1,1,n); cnt_neg.build(1,1,n);
	tree_pos.build(1,1,n); tree_neg.build(1,1,n);
	while(Q--)
	{
		int oper,l,r;
		scanf("%d%d%d",&oper,&l,&r);
		--r;
		if(oper == 1)
		{
			int k;
			scanf("%d",&k);
			Segment_Tree_add *tadd = k > 0? &cnt_pos: &cnt_neg;
			Segment_Tree_mn *tmn = k > 0? &tree_pos: &tree_neg;
			
			tmn -> update_mn(1,1,n, l,r,abs(k));
			tadd -> update(1,1,n, l,r,1);
			
			int cur = l, d = k > 0? 2: 1;
			pii tmp;
			while(cur <= r && (tmp = tadd -> query(1,1,n, cur,r)).first == 1)
			{
				cur = tmp.second;
				if((type[cur] |= d) == 3)
					tree_pos.update_val(1,1,n, cur, 1),
					tree_neg.update_val(1,1,n, cur, 1);
				++cur;
			}
		}
		else printf("%lld\n",tree_pos.query(1,1,n,l,r) + tree_neg.query(1,1,n,l,r));
	}
	return 0;
}