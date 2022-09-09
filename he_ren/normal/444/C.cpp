#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

inline int Abs(int x){ return x<0? -x: x;}

struct Segment_Tree
{
	int n;
	ll sum[MAXN<<2],tag[MAXN<<2];
	int clr[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	
	void init(int n_){ n=n_; build(1,1,n);}
	void update(int ql,int qr,int k){ update(1,1,n,ql,qr,k);}
	ll query(int ql,int qr){ return query(1,1,n,ql,qr);}
	
	inline void push_up(int u)
	{
		sum[u] = sum[ls(u)] + sum[rs(u)];
		clr[u] = clr[ls(u)]==clr[rs(u)]? clr[ls(u)]: -1;
	}
	inline void upd(int u,int len,ll k){ tag[u] += k; sum[u] += k*len;}
	inline void push_down(int u,int l,int r,int mid)
	{
		if(tag[u])
		{
			upd(ls(u), mid-l+1, tag[u]);
			upd(rs(u), r-mid, tag[u]);
			tag[u]=0;
		}
		if(~clr[u])
		{
			clr[ls(u)]=clr[u];
			clr[rs(u)]=clr[u];
		}
	}
	
	void build(int u,int l,int r)
	{
		tag[u]=0;
		if(l==r){ clr[u]=l; sum[u]=0; return;}
		int mid = (l+r)>>1;
		build(lson(u)); build(rson(u));
		push_up(u);
	}
	
	void update(int u,int l,int r,int ql,int qr,int k)
	{
		if(ql<=l && r<=qr && ~clr[u])
		{
			upd(u, r-l+1, Abs(clr[u]-k));
			clr[u] = k;
			return;
		}
		int mid = (l+r)>>1;
		push_down(u,l,r,mid);
		if(ql<=mid) update(lson(u),ql,qr,k);
		if(mid<qr) update(rson(u),ql,qr,k);
		push_up(u);
	}
	
	ll query(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr) return sum[u];
		int mid = (l+r)>>1;
		ll res=0;
		push_down(u,l,r,mid);
		if(ql<=mid) res += query(lson(u),ql,qr);
		if(mid<qr) res += query(rson(u),ql,qr);
		push_up(u);
		return res;
	}
}solver;

int main(void)
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	
	solver.init(n);
	
	while(Q--)
	{
		int oper,l,r;
		scanf("%d%d%d",&oper,&l,&r);
		if(oper==1)
		{
			int x;
			scanf("%d",&x);
			solver.update(l,r,x);
		}
		else printf("%lld\n",solver.query(l,r));
	}
	return 0;
}