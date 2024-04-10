#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define x1 x11111
#define y1 y11111
#define x2 x22222
#define y2 y22222
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;
const int maxc = 1e6;
const int MAXC = maxc + 5;

struct BIT
{
	int tree[MAXC], n;
	#define lowbit(x) ((x)&-(x))
	inline void clear(void){ memset(tree,0,sizeof(tree));}
	inline void update(int x,int k)
	{
		while(x<=n)
			tree[x]+=k, x+=lowbit(x);
	}
	inline void update(int l,int r,int k){ update(max(l,1),k); update(r+1,-k);}
	inline int query(int x)
	{
		int res=0;
		while(x)
			res+=tree[x], x^=lowbit(x);
		return res;
	}
	inline int query(int l,int r){ return query(r)-query(l-1);}
};

struct Seg
{
	int x,l,r;
	inline int& y(void){ return x;}
	inline void read(void){ scanf("%d%d%d",&x,&l,&r);}
}p[MAXN], q[MAXM];

inline bool cmp_y(const Seg &p,const Seg &q){ return p.x < q.x;}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) p[i].read();
	for(int i=1; i<=m; ++i) q[i].read();
	
	ll ans = (ll)(n+1) * (m+1);
	
	p[++n] = q[++m] = (Seg){0,0,maxc};
	p[++n] = q[++m] = (Seg){maxc,0,maxc};
	
	static int xx[MAXM];
	for(int i=1; i<=m; ++i)
		xx[i] = q[i].x;
	sort(xx+1,xx+m+1);
	
	for(int i=1; i<=n; ++i)
	{
		int l=p[i].l, r=p[i].r;
		if(l!=0) ans -= lower_bound(xx+1,xx+m+1,l)-xx - 1;
		if(r!=maxc) ans -= m - (upper_bound(xx+1,xx+m+1,r)-xx - 1);
	}
	
	vector<pii> seg;
	for(int i=1; i<=m; ++i)
		if(q[i].l!=0) seg.push_back(make_pair(q[i].l-1, q[i].x));
	
	static BIT bit;
	bit.n = maxc;
	
	sort(seg.begin(), seg.end());
	sort(p+1,p+n+1,cmp_y);
	for(int i=0, j=1; i<(int)seg.size(); ++i)
	{
		while(j<=n && p[j].x <= seg[i].first)
			bit.update(p[j].l,p[j].r, 1),
			++j;
		ans -= bit.query(seg[i].second);
	}
	
	seg.clear();
	for(int i=1; i<=m; ++i)
		if(q[i].r!=maxc) seg.push_back(make_pair(q[i].r+1, q[i].x));
	
	bit.clear();
	
	sort(seg.begin(), seg.end());
	reverse(seg.begin(), seg.end());
	for(int i=0,j=n; i<(int)seg.size(); ++i)
	{
		while(j>=1 && p[j].x >= seg[i].first)
			bit.update(p[j].l,p[j].r, 1),
			--j;
		ans -= bit.query(seg[i].second);
	}
	
	printf("%lld",ans);
	return 0;
}