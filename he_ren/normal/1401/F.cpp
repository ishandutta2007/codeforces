#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = (1<<18) + 5;
const int LB = 18 + 5;

struct Segment_Tree
{
	ll sum[MAXN<<2], tag[LB];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u){ sum[u] = sum[ls(u)] + sum[rs(u)];}
	void build(int u,int l,int r, int a[])
	{
		if(l==r){ sum[u] = a[l]; return;}
		int mid = (l+r)>>1;
		build(lson(u),a); build(rson(u),a);
		push_up(u);
	}
	void update_rev(int k){ for(int i=k; i>0; --i) tag[i] ^= 1;}
	void update_swap(int k){ tag[k+1] ^= 1;}
	
	void update_chg(int u,int l,int r,int cur, int q,int k)
	{
		if(l==r){ sum[u]=k; return;}
		int mid = (l+r)>>1;
		if(q<=mid)
		{
			if(tag[cur]) update_chg(rson(u),cur-1, mid+1 + (q-l), k);
			else update_chg(lson(u),cur-1, q, k);
		}
		else
		{
			if(tag[cur]) update_chg(lson(u),cur-1, l + (q-(mid+1)), k);
			else update_chg(rson(u),cur-1, q, k);
		}
		push_up(u);
	}
	
	ll query(int u,int l,int r,int cur,int ql,int qr)
	{
		if(ql<=l && r<=qr) return sum[u];
		int mid = (l+r)>>1; ll res = 0;
		if(ql<=mid)
		{
			if(tag[cur])
				res += query(rson(u),cur-1, mid+1 + (ql-l), mid+1 + (qr-l));
			else
				res += query(lson(u),cur-1, ql, qr);
		}
		if(mid < qr)
		{
			if(tag[cur])
				res += query(lson(u),cur-1, l + (ql-(mid+1)), l + (qr-(mid+1)));
			else
				res += query(rson(u),cur-1, ql, qr);
		}
		return res;
	}
};

int a[MAXN];
Segment_Tree tree;

int main(void)
{
	int lb,Q;
	scanf("%d%d",&lb,&Q);
	int n = 1<<lb;
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	tree.build(1,1,n, a);
	
	while(Q--)
	{
		int oper, x;
		scanf("%d%d",&oper,&x);
		if(oper==1)
		{
			int k;
			scanf("%d",&k);
			tree.update_chg(1,1,n,lb, x,k);
		}
		else if(oper==2) tree.update_rev(x);
		else if(oper==3) tree.update_swap(x);
		else
		{
			int y;
			scanf("%d",&y);
			printf("%lld\n",tree.query(1,1,n,lb, x,y));
		}
	}
	return 0;
}