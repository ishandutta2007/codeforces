#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 3e5 + 5;
const int inf = 0x3f3f3f3f;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

struct Segment_Tree
{
	int n,mx[MAXN<<2],tag[MAXN<<2];
	Segment_Tree(int n_=0){ n=n_; memset(mx,0,sizeof(mx)); memset(tag,0,sizeof(tag));}
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u){ mx[u] = max(mx[ls(u)], mx[rs(u)]);}
	inline void push_down(int u)
	{
		mx[ls(u)]+=tag[u]; tag[ls(u)]+=tag[u];
		mx[rs(u)]+=tag[u]; tag[rs(u)]+=tag[u];
		tag[u]=0;
	}
	
	void update(int u,int l,int r,int ql,int qr,int k)
	{
		if(ql<=l && r<=qr){ mx[u]+=k; tag[u]+=k; return;}
		push_down(u);
		int mid = (l+r)>>1;
		if(ql<=mid) update(lson(u), ql,qr,k);
		if(mid<qr) update(rson(u), ql,qr,k);
		push_up(u);
	}
	void update(int ql,int qr,int k){ update(1,1,n, ql,qr,k);}
	
	int query(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr) return mx[u];
		push_down(u);
		int mid = (l+r)>>1, res=-inf;
		if(ql<=mid) chk_max(res, query(lson(u), ql,qr));
		if(mid<qr) chk_max(res, query(rson(u), ql,qr));
		push_up(u);
		return res;
	}
	int query(int ql,int qr){ return query(1,1,n,ql,qr);}
};

int p[MAXN],pos[MAXN];
Segment_Tree tree;

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&p[i]);
	
	for(int i=1; i<=n; ++i) pos[p[i]]=i;
	
	int ans=n;
	tree.n=n;
	tree.update(1,pos[ans],1);
	for(int i=1; i<=n; ++i)
	{
		printf("%d ",ans);
		
		int q;
		scanf("%d",&q);
		tree.update(1,q,-1);
		while(ans>1 && tree.query(1,n)<=0)
		{
			--ans;
			tree.update(1,pos[ans],1);
		}
	}
	return 0;
}