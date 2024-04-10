#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

struct Data
{
	ll l, r;
	Data(void){}
	Data(ll _l,ll _r): l(_l), r(_r) {}
	Data(ll k)
	{
		if(k >= 0) l = k, r = 0;
		else r = -k, l = 0;
	}
};

inline Data operator + (const Data &p,const Data &q)
{
	if(p.r >= q.l) return Data(p.l, p.r - q.l + q.r);
	else return Data(p.l + q.l - p.r, q.r);
}

struct Segment_Tree
{
	Data dat[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u){ dat[u] = dat[ls(u)] + dat[rs(u)];}
	void build(int u,int l,int r,int a[])
	{
		if(l == r){ dat[u] = Data(a[l]); return;}
		int mid = (l+r)>>1;
		build(lson(u),a); build(rson(u),a);
		push_up(u);
	}
	Data query(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr) return dat[u];
		int mid = (l+r)>>1;
		if(ql<=mid && mid<qr) return query(lson(u),ql,qr) + query(rson(u),ql,qr);
		return ql<=mid? query(lson(u),ql,qr): query(rson(u),ql,qr);
	}
}tree, tree2;

int a[MAXN], b[MAXN];

int main(void)
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	
	for(int i=1; i<=n; ++i) a[i] -= b[i], b[i] = -a[i];
	
	tree.build(1,1,n,a);
	tree2.build(1,1,n,b);
	
	while(Q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		Data res = tree.query(1,1,n,l,r);
		
		if(res.l || res.r)
		{
			printf("-1\n");
			continue;
		}
		printf("%lld\n",tree2.query(1,1,n,l,r).l);
	}
	return 0;
}