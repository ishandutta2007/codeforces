#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int inf = 0x3f3f3f3f;

inline ll Abs(const ll x){ return x<0? -x: x;}

#define bbit(i) (1ll<<(i))
#define bdig(x,i) (((x)>>(i))&1)

struct BIT
{
	int mx[MAXN], n;
	#define lowbit(x) ((x)&-(x))
	inline void init(int n_){ n=n_; memset(mx,0,sizeof(mx));}
	inline void update(int x,int k)
	{
		while(x)
			mx[x] = max(mx[x], k),
			x ^= lowbit(x);
	}
	inline int query(int x)
	{
		int res = 0;
		while(x<=n)
			res = max(res, mx[x]),
			x += lowbit(x);
		return res;
	}
};

struct Node
{
	ll l,r;
};
inline bool cmp(const Node &p,const Node &q){ return p.r == q.r? p.l > q.l: p.r < q.r;}

int n,d;
int a[MAXN];

bool check(int w)
{
	static Node p[MAXN];
	for(int i=1; i<=n; ++i)
		p[i] = (Node){ a[i] - (ll)i * w, a[i] + (ll)i * w};
	
	sort(p+1,p+n+1,cmp);
	
	static ll dsc[MAXN];
	int dcnt = 0;
	for(int i=1; i<=n; ++i)
		dsc[++dcnt] = p[i].l;
	sort(dsc+1,dsc+dcnt+1);
	dcnt = unique(dsc+1,dsc+dcnt+1) - dsc - 1;
	for(int i=1; i<=n; ++i)
		p[i].l = lower_bound(dsc+1,dsc+dcnt+1, p[i].l) - dsc;
	
	static BIT tree;
	tree.init(dcnt);
	
	for(int i=1; i<=n; ++i)
	{
		int res = tree.query(p[i].l) + 1;
		if(res >= d) return 1;
		tree.update(p[i].l, res);
	}
	
	return 0;
}

int main(void)
{
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	d = n-d;
	
	int l = 0, r = 2e9 + 5;
	while(l<r)
	{
		int mid = ((ll)l + (ll)r)>>1;
		if(check(mid)) r = mid;
		else l = mid+1;
	}
	
	printf("%d",l);
	return 0;
}