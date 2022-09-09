#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3fll;

struct Segment_Tree
{
	int st[MAXN<<2], nd[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u)
	{
		if(st[ls(u)] <= st[rs(u)])
			st[u] = st[ls(u)],
			nd[u] = min(nd[ls(u)], st[rs(u)]);
		else
			st[u] = st[rs(u)],
			nd[u] = min(nd[rs(u)], st[ls(u)]);
	}
	inline void upd(pii &p,pii q)
	{
		if(p.first <= q.first) p.second = min(p.second, q.first);
		else p.second = min(q.second, p.first), p.first = q.first;
	}
	
	void build(int u,int l,int r)
	{
		st[u] = nd[u] = inf;
		if(l==r) return;
		int mid = (l+r)>>1;
		build(lson(u)); build(rson(u));
	}
	void update(int u,int l,int r,int q,int k)
	{
		if(l==r){ st[u]=k; nd[u]=inf; return;}
		int mid = (l+r)>>1;
		if(q<=mid) update(lson(u),q,k);
		else update(rson(u),q,k);
		push_up(u);
	}
	pii query(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr) return make_pair(st[u], nd[u]);
		int mid = (l+r)>>1; pii res = make_pair(inf,inf);
		if(ql<=mid) upd(res, query(lson(u),ql,qr));
		if(mid<qr) upd(res, query(rson(u),ql,qr));
		return res;
	}
};

int n;
int a[MAXN];

Segment_Tree tree[10];
void update(int pos,int x)
{
	int tmp = x;
	for(int i=0; i<=9; ++i)
	{
		if(tmp%10) tree[i].update(1,1,n, pos,x);
		else tree[i].update(1,1,n, pos,inf);
		tmp/=10;
	}
}

int main(void)
{
	int Q;
	scanf("%d%d",&n,&Q);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i)
		update(i, a[i]);
	
	while(Q--)
	{
		int oper,x,y;
		scanf("%d%d%d",&oper,&x,&y);
		if(oper==1) update(x,y);
		else
		{
			ll ans = linf;
			for(int i=0; i<=9; ++i)
			{
				pii res = tree[i].query(1,1,n,x,y);
				if(res.first != inf && res.second != inf)
					ans = min(ans, (ll)res.first + res.second);
			}
			if(ans == linf) printf("-1\n");
			else printf("%lld\n",ans);
		}
	}
	return 0;
}