#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;

struct Segment_Tree
{
	int tag[MAXN<<2], mx[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u){ mx[u] = max(mx[ls(u)], mx[rs(u)]);}
	inline void push_down(int u)
	{
		if(tag[u])
		{
			mx[ls(u)] += tag[u]; tag[ls(u)] += tag[u];
			mx[rs(u)] += tag[u]; tag[rs(u)] += tag[u];
			tag[u] = 0;
		}
	}
	void update_add(int u,int l,int r,int ql,int qr,int k)
	{
		if(ql<=l && r<=qr){ mx[u] += k; tag[u] += k; return;}
		push_down(u);
		int mid = (l+r)>>1;
		if(ql<=mid) update_add(lson(u),ql,qr,k);
		if(mid<qr) update_add(rson(u),ql,qr,k);
		push_up(u);
	}
	void update_mx(int u,int l,int r,int q,int k)
	{
		if(l == r){ mx[u] = max(mx[u], k); return;}
		push_down(u);
		int mid = (l+r)>>1;
		if(q<=mid) update_mx(lson(u),q,k);
		else update_mx(rson(u),q,k);
		push_up(u);
	}
	int query(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr) return mx[u];
		push_down(u);
		int mid = (l+r)>>1, res = 0;
		if(ql<=mid) res = max(res, query(lson(u),ql,qr));
		if(mid<qr) res = max(res, query(rson(u),ql,qr));
		return res;
	}
	
	int n;
	inline void update_add(int ql,int qr,int k){ if(ql<=qr) update_add(1,1,n,ql,qr,k);}
	inline void update_mx(int q,int k){ update_mx(1,1,n,q,k);}
	inline int query(int ql,int qr){ return ql<=qr? query(1,1,n,ql,qr): 0;}
}tree;

int a[MAXN], s[MAXN];
inline int get_type(int x){ return a[x] > s[x];}

int dsc[MAXN], dcnt = 0;

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d%d",&s[i],&a[i]);
		if(s[i] < d) --i, --n;
	}
	
	dsc[++dcnt] = d;
	for(int i=1; i<=n; ++i) dsc[++dcnt] = s[i], dsc[++dcnt] = a[i];
	sort(dsc+1,dsc+dcnt+1);
	dcnt = unique(dsc+1,dsc+dcnt+1) - dsc - 1;
	auto get = [&] (int x){ return lower_bound(dsc+1,dsc+dcnt+1,x) - dsc;};
	
	d = get(d);
	for(int i=1; i<=n; ++i) s[i] = get(s[i]), a[i] = get(a[i]);
	
	static int id[MAXN];
	for(int i=1; i<=n; ++i) id[i] = i;
	sort(id+1,id+n+1,[](int x,int y){
		int tx = get_type(x), ty = get_type(y);
		if(tx != ty)
		{
			if(tx) return a[x] == s[y]? true: a[x] < s[y];
			else return s[x] == a[y]? false: s[x] < a[y];
		}
		if(tx == 0) return s[x] < s[y];
		else return a[x] < a[y];
	});
	
	static int ta[MAXN], ts[MAXN];
	for(int i=1; i<=n; ++i) ta[i] = a[id[i]], ts[i] = s[id[i]];
	memcpy(a,ta,(n+1)<<2); memcpy(s,ts,(n+1)<<2);
	
	tree.n = dcnt;
	tree.update_add(1, dcnt, -1e9);
	tree.update_mx(d, 0);
	
	for(int i=1; i<=n; ++i)
	{
		int type = get_type(i);
		if(type == 1)
		{
			int t = tree.query(1, s[i]);
			tree.update_mx(a[i], t + 1);
			continue;
		}
		
		int t = tree.query(1, a[i]);
		tree.update_mx(a[i], t + 1);
		tree.update_add(a[i]+1, s[i], 1);
	}
	
	printf("%d",tree.mx[1]);
	return 0;
}