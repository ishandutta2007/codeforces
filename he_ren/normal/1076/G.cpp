#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXM = 5 + 5;

int m;

struct Segment_Tree
{
	int f[MAXN<<2][2][MAXM], tag[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u)
	{
		int l = ls(u), r = rs(u);
		for(int k=0; k<=1; ++k)
			for(int i=1; i<=m+1; ++i)
			{
				int t = f[r][k][i];
				f[u][k][i] = f[l][k][t];
			}
	}
	inline void upd(int u)
	{
		tag[u] ^= 1;
		for(int i=1; i<=m+1; ++i)
			swap(f[u][0][i], f[u][1][i]);
	}
	inline void push_down(int u)
	{
		if(tag[u])
		{
			upd(ls(u)); upd(rs(u));
			tag[u] = 0;
		}
	}
	void build(int u,int l,int r,int a[])
	{
		tag[u] = 0;
		if(l == r)
		{
			for(int k=0; k<=1; ++k)
				for(int i=1; i<=m+1; ++i)
				{
					if(a[l]^k) f[u][k][i] = i <= m? i+1: 1;
					else f[u][k][i] = min(m+1, i+1);
				}
			return;
		}
		int mid = (l+r)>>1;
		build(lson(u),a); build(rson(u),a);
		push_up(u);
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
	int query(int u,int l,int r,int ql,int qr,int k)
	{
		if(ql<=l && r<=qr) return f[u][0][k];
		push_down(u);
		int mid = (l+r)>>1;
		if(mid<qr) k = query(rson(u),ql,qr,k);
		if(ql<=mid) k = query(lson(u),ql,qr,k);
		return k;
	}
}tree;

int a[MAXN];

int main(void)
{
	int n,Q;
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1; i<=n; ++i)
	{
		ll x;
		scanf("%lld",&x);
		a[i] = x & 1;
	}
	
	tree.build(1,1,n,a);
	while(Q--)
	{
		int type,l,r;
		scanf("%d%d%d",&type,&l,&r);
		if(type == 1)
		{
			ll x;
			scanf("%lld",&x);
			if(x & 1) tree.update(1,1,n,l,r);
		}
		else
		{
			int res = tree.query(1,1,n,l,r,m+1);
			printf("%d\n",res == 1? 2: 1);
		}
	}
	return 0;
}