#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e3 + 5;
const int MAXD = MAXN * 2;
const int inf = 0x3f3f3f3f;

struct Segment_Tree
{
	int mx[MAXD<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u){ mx[u] = max(mx[ls(u)], mx[rs(u)]);}
	void clear(int u,int l,int r)
	{
		mx[u] = 0;
		if(l==r) return;
		int mid = (l+r)>>1;
		clear(lson(u)); clear(rson(u));
	}
	void update(int u,int l,int r,int q,int k)
	{
		mx[u] = max(mx[u],k);
		if(l==r) return;
		int mid = (l+r)>>1;
		if(q<=mid) update(lson(u),q,k);
		else update(rson(u),q,k);
	}
	int query(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l&&r<=qr) return mx[u];
		int mid=(l+r)>>1, res=0;
		if(ql<=mid) res = max(res, query(lson(u),ql,qr));
		if(mid<qr) res = max(res, query(rson(u),ql,qr));
		return res;
	}
};

struct Seg
{
	int l,r;
}a[MAXN];
inline bool cmp(const Seg &p,const Seg &q){ return p.r==q.r? p.l>q.l: p.r<q.r;}

int dsc[MAXD], dcnt=0;

int f[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d%d",&a[i].l,&a[i].r);
	a[++n] = (Seg){-inf,inf};
	
	dcnt = 0;
	for(int i=1; i<=n; ++i)
		dsc[++dcnt] = a[i].l,
		dsc[++dcnt] = a[i].r;
	sort(dsc+1,dsc+dcnt+1);
	dcnt=unique(dsc+1,dsc+dcnt+1)-dsc-1;
	for(int i=1; i<=n; ++i)
		a[i].l = lower_bound(dsc+1,dsc+dcnt+1,a[i].l) - dsc,
		a[i].r = lower_bound(dsc+1,dsc+dcnt+1,a[i].r) - dsc;
	
	sort(a+1,a+n+1,cmp);
	for(int i=1; i<=n; ++i)
	{
		static Segment_Tree tree;
		tree.clear(1,1,dcnt);
		
		for(int j=1; j<i; ++j) if(a[i].l <= a[j].l && a[j].r <= a[i].r)
		{
			int now = f[j] + tree.query(1,1,dcnt, 1,a[j].l-1);
			tree.update(1,1,dcnt, a[j].r,now);
		}
		
		f[i] = tree.query(1,1,dcnt, 1,dcnt) + 1;	
	}
	
	printf("%d\n",f[n] - 1);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}