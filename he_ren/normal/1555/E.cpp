#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;
const int MAXM = 1e6 + 5;

struct Segment_Tree
{
	int mn[MAXM<<2], tag[MAXM<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u){ mn[u] = min(mn[ls(u)], mn[rs(u)]);}
	inline void upd(int u,int k){ mn[u] += k; tag[u] += k;}
	inline void push_down(int u)
	{
		if(tag[u])
		{
			upd(ls(u),tag[u]); upd(rs(u),tag[u]);
			tag[u] = 0;
		}
	}
	
	void update(int u,int l,int r,int ql,int qr,int k)
	{
		if(ql<=l && r<=qr){ upd(u,k); return;}
		push_down(u);
		int mid = (l+r)>>1;
		if(ql<=mid) update(lson(u),ql,qr,k);
		if(mid<qr) update(rson(u),ql,qr,k);
		push_up(u);
	}
}tree;

int m;
int a[MAXN], b[MAXN], val[MAXN];

inline void insert(int u)
{
	tree.update(1,1,m, a[u], b[u], 1);
}
inline void erase(int u)
{
	tree.update(1,1,m, a[u], b[u], -1);
}

int main(void)
{
	int n;
	scanf("%d%d",&n,&m); --m;
	for(int i=1; i<=n; ++i)
		scanf("%d%d%d",&a[i],&b[i],&val[i]), --b[i];
	
	if(m == 1) return printf("0"), 0;
	
	static int id[MAXN];
	for(int i=1; i<=n; ++i) id[i] = i;
	sort(id+1,id+n+1,[&](int x,int y){ return val[x] < val[y];});
	
	int ans = val[id[n]] - val[id[1]];
	for(int i=1,j=1; i<=n; erase(id[i++]))
	{
		while(j<=n && tree.mn[1] == 0) insert(id[j++]);
		if(tree.mn[1])
			ans = min(ans, val[id[j-1]] - val[id[i]]);
	}
	
	printf("%d",ans);
	return 0;
}