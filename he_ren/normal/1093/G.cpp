#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const int MAXD = 5 + 5;
const int ALL = (1<<5) + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

inline void chk_max(ll &a,ll b){ if(a<b) a=b;}

int n,d;
int a[MAXN][MAXD];
#define bit(x,i) (((x)>>(i))&1)

struct Segment_Tree
{
	int mask;
	ll mx[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	
	inline void push_up(int u)
	{
		mx[u] = max(mx[ls(u)],mx[rs(u)]);
	}
	
	void build(int u=1,int l=1,int r=n)
	{
		if(l==r)
		{
			mx[u]=0;
			for(int i=0; i<d; ++i)
				if(bit(mask,i)) mx[u]+=a[l][i+1];
				else mx[u]-=a[l][i+1];
			return;
		}
		int mid=(l+r)>>1;
		build(lson(u)); build(rson(u));
		push_up(u);
	}
	
	ll query(int ql,int qr,int u=1,int l=1,int r=n)
	{
		if(ql<=l && r<=qr) return mx[u];
		int mid=(l+r)>>1;
		ll res=-linf;
		if(ql<=mid) chk_max(res, query(ql,qr,lson(u)));
		if(mid<qr) chk_max(res, query(ql,qr,rson(u)));
		return res;
	}
	
	void update(int q,int u=1,int l=1,int r=n)
	{
		if(l==r)
		{
			mx[u]=0;
			for(int i=0; i<d; ++i)
				if(bit(mask,i)) mx[u]+=a[l][i+1];
				else mx[u]-=a[l][i+1];
			return;
		}
		int mid=(l+r)>>1;
		if(q<=mid) update(q,lson(u));
		else update(q,rson(u));
		push_up(u);
	}
}tree[ALL];

int main(void)
{
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=d; ++j)
			scanf("%d",&a[i][j]);
	
	int all = (1<<d)-1;
	for(int i=0; i<=all; ++i)
		tree[i].mask=i,
		tree[i].build();
	
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int oper;
		scanf("%d",&oper);
		if(oper==1)
		{
			int x;
			scanf("%d",&x);
			for(int i=1; i<=d; ++i) scanf("%d",&a[x][i]);
			for(int i=0; i<=all; ++i)
				tree[i].update(x);
		}
		else
		{
			int l,r;
			scanf("%d%d",&l,&r);
			ll res=-linf;
			for(int i=0; i<=(all>>1); ++i)
				chk_max(res, tree[i].query(l,r) + tree[all^i].query(l,r));
			printf("%lld\n",res);
		}
	}
	return 0;
}