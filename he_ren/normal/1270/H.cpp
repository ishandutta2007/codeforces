#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 15;

struct Segment_Tree
{
	pii mn[MAXN << 2]; int tag[MAXN << 2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u)
	{
		if(mn[ls(u)].first == mn[rs(u)].first)
			mn[u] = {mn[ls(u)].first, mn[ls(u)].second + mn[rs(u)].second};
		else
			mn[u] = min(mn[ls(u)], mn[rs(u)]);
	}
	inline void upd(int u,int k)
	{
		mn[u].first += k; tag[u] += k;
	}
	inline void push_down(int u)
	{
		if(tag[u])
		{
			upd(ls(u), tag[u]); upd(rs(u), tag[u]);
			tag[u] = 0;
		}
	}
	void add(int u,int l,int r,int ql,int qr,int k)
	{
		if(ql<=l && r<=qr){ upd(u,k); return;}
		push_down(u);
		int mid = (l+r)>>1;
		if(ql<=mid) add(lson(u),ql,qr,k);
		if(mid<qr) add(rson(u),ql,qr,k);
		push_up(u);
	}
	void setval(int u,int l,int r,int q,int k)
	{
		if(l == r){ mn[u].second = k; return;}
		push_down(u);
		int mid = (l+r)>>1;
		q <= mid? setval(lson(u),q,k): setval(rson(u),q,k);
		push_up(u);
	}
}tree;

int a[MAXN];

int main(void)
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	
	const int mxa = 1e6 + 1;
	a[0] = mxa; a[n + 1] = 0;
	
	auto upd = [&] (int i,int k)
	{
		int x = a[i], y = a[i+1];
		if(x > y) swap(x, y);
		if(x < y) tree.add(1, 0, mxa, x, y-1, k);
	};
	
	tree.add(1, 0, mxa, mxa, mxa, 1);
	for(int i=0; i<=n; ++i)
		upd(i, 1);
	for(int i=0; i<=n+1; ++i)
		tree.setval(1, 0, mxa, a[i], 1);
	
	while(Q--)
	{
		int x,k;
		scanf("%d%d",&x,&k);
		upd(x,-1); upd(x-1,-1);
		tree.setval(1, 0, mxa, a[x], 0);
		a[x] = k;
		tree.setval(1, 0, mxa, a[x], 1);
		upd(x,1); upd(x-1,1);
		
		printf("%d\n",tree.mn[1].second - 2);
	}
	return 0;
}