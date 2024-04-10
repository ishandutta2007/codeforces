#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;
const int MAXD = 2e5 + 5;
const int MAXB = 1e6 + 5;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

struct Segment_tree
{
	ll *a, mx[MAXM<<2], tag[MAXM<<2];
	Segment_tree(ll a_[]){ a=a_;}
	
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	
	inline void push_up(int u){ mx[u] = max(mx[ls(u)], mx[rs(u)]);}
	inline void push_down(int u)
	{
		mx[ls(u)] += tag[u]; tag[ls(u)] += tag[u];
		mx[rs(u)] += tag[u]; tag[rs(u)] += tag[u];
		tag[u]=0;
	}
	
	void build(int u,int l,int r)
	{
		if(l==r){ mx[u] = a[l]; return;}
		int mid = (l+r)>>1;
		build(lson(u)); build(rson(u));
		push_up(u);
	}
	
	inline void update(int u,int l,int r, int ql,int qr,ll k)
	{
		if(ql<=l && r<=qr)
		{
			mx[u] += k; tag[u] += k;
			return;
		}
		push_down(u);
		int mid = (l+r)>>1;
		if(ql<=mid) update(lson(u), ql,qr,k);
		if(mid<qr) update(rson(u), ql,qr,k);
		push_up(u);
	}
	
	inline ll query(int u,int l,int r, int ql,int qr)
	{
		if(ql<=l && r<=qr) return mx[u];
		push_down(u);
		int mid = (l+r)>>1;
		ll res = -linf;
		if(ql<=mid) res = max(res, query(lson(u), ql,qr));
		if(mid<qr) res = max(res, query(rson(u), ql,qr));
		push_up(u);
		return res;
	}
};

struct Node
{
	int x,c;
}a[MAXN], b[MAXM];
inline bool cmp_a(const Node &p,const Node &q){ return p.x < q.x;}

struct Mob
{
	int x,y,z;
}p[MAXD];
inline bool cmp_p(const Mob &p,const Mob &q){ return p.x < q.x;}

int dsc[MAXM], cnt=0;

ll c[MAXB];
Segment_tree tree(c);

int main(void)
{
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1; i<=n; ++i)
		scanf("%d%d",&a[i].x, &a[i].c);
	for(int i=1; i<=m; ++i)
		scanf("%d%d",&b[i].x, &b[i].c);
	for(int i=1; i<=d; ++i)
		scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
	
	for(int i=1; i<=m; ++i)
		dsc[++cnt] = b[i].x;
	sort(dsc+1,dsc+cnt+1);
	cnt = unique(dsc+1,dsc+cnt+1)-dsc-1;
	for(int i=1; i<=m; ++i)
		b[i].x = lower_bound(dsc+1,dsc+cnt+1, b[i].x) - dsc;
	
	for(int i=1; i<=d; ++i)
		p[i].y = upper_bound(dsc+1,dsc+cnt+1, p[i].y) - dsc - 1;
	
	for(int i=1; i<=cnt; ++i)
		c[i] = -linf;
	for(int i=1; i<=m; ++i)
		c[b[i].x] = max(c[b[i].x], -(ll)b[i].c);
	
	tree.build(1,1,cnt);
	
	sort(a+1,a+n+1,cmp_a);
	sort(p+1,p+d+1,cmp_p);
	
	ll ans = -linf;
	for(int i=1,j=1; i<=n; ++i)
	{
		while(j<=d && p[j].x < a[i].x)
		{
			if(p[j].y+1 <= cnt)
				tree.update(1,1,cnt, p[j].y+1, cnt, p[j].z);
			++j;
		}
		ans = max(ans, tree.query(1,1,cnt, 1,cnt) - a[i].c);
	}
	printf("%lld",ans);
	return 0;
}