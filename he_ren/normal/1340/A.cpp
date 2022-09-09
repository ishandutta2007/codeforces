#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

struct Segment_Tree
{
	int mx[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u){ mx[u] = max(mx[ls(u)], mx[rs(u)]);}
	void build(int u,int l,int r)
	{
		mx[u] = 1;
		if(l==r) return;
		int mid = (l+r)>>1;
		build(lson(u));
		build(rson(u));
	}
	int query(void){ return mx[1];}
	void update(int u,int l,int r,int q,int k)
	{
		if(l==r){ mx[u]+=k; return;}
		int mid = (l+r)>>1;
		if(q<=mid) update(lson(u), q,k);
		else update(rson(u), q,k);
		push_up(u);
	}
}tree;

int p[MAXN],pos[MAXN];
int l[MAXN],r[MAXN],cnt[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&p[i]);
	
	for(int i=1; i<=n; ++i)
		pos[p[i]] = i;
	
	for(int i=1; i<=n; ++i)
	{
		l[i] = i-1;
		r[i] = i+1;
		cnt[i] = 1;
	}
	tree.build(1,1,n);
	
	int mx = 1;
	for(int i=1; i<=n; ++i)
	{
		int x = pos[i];
		if(cnt[x] < mx)
		{
			printf("No\n");
			return;
		}
		r[ l[x] ] = r[x];
		l[ r[x] ] = l[x];
		
		if(r[x]<=n)
		{
			tree.update(1,1,n, r[x], cnt[x]);
			cnt[r[x]] += cnt[x];
		}
		tree.update(1,1,n, x, -cnt[x]);
		cnt[x] = 0;
		
		mx = tree.query();
	}
	printf("Yes\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}