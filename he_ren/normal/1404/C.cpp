#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;
const int MAXQ = 3e5 + 5;

struct Segment_Tree
{
	int sum[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void clear(void){ memset(sum,0,sizeof(sum));}
	inline void push_up(int u){ sum[u] = sum[ls(u)] + sum[rs(u)];}
	void update(int u,int l,int r,int q)
	{
		if(l==r){ ++sum[u]; return;}
		int mid = (l+r)>>1;
		if(q<=mid) update(lson(u),q);
		else update(rson(u),q);
		push_up(u);
	}
	int query(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr) return sum[u];
		int mid = (l+r)>>1, res = 0;
		if(ql<=mid) res += query(lson(u), ql,qr);
		if(mid<qr) res += query(rson(u), ql,qr);
		return res;
	}
	int find_kth(int u,int l,int r,int k)
	{
		if(l==r) return l;
		int mid = (l+r)>>1;
		if(sum[rs(u)] >= k) return find_kth(rson(u), k);
		return find_kth(lson(u), k - sum[rs(u)]);
	}
};

int a[MAXN];
int lef[MAXN];

struct Query
{
	int x,y,id;
}q[MAXQ];
inline bool cmp(const Query &p,const Query &q){ return p.y < q.y;}

int ans[MAXN];

int main(void)
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	static Segment_Tree tree;
	for(int i=1; i<=n; ++i)
	{
		if(a[i] > i){ lef[i]=0; continue;}
		if(a[i] == i){ lef[i]=i; tree.update(1,1,n,lef[i]); continue;}
		
		if(tree.query(1,1,n,1,n) < i-a[i]){ lef[i]=0; continue;}
		lef[i] = tree.find_kth(1,1,n, i-a[i]);
		tree.update(1,1,n,lef[i]);
	}
	
//	for(int i=1; i<=n; ++i)
//		printf("lef %d: %d\n",i,lef[i]);
	
	for(int i=1; i<=Q; ++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		q[i] = (Query){x,n-y,i};
	}
	
	sort(q+1,q+Q+1,cmp);
	
	tree.clear();
	for(int i=1,j=1; i<=Q; ++i)
	{
		while(j<=n && j <= q[i].y)
		{
			if(lef[j]) tree.update(1,1,n,lef[j]);
			++j;
		}
		
		ans[q[i].id] = tree.query(1,1,n, q[i].x+1, n);
	}
	
	for(int i=1; i<=Q; ++i)
		printf("%d\n",ans[i]);
	return 0;
}