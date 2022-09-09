#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int inf = 0x3f3f3f3f;

struct Segment_Tree_mx
{
	pii mx[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u){ mx[u] = max(mx[ls(u)], mx[rs(u)]);}
	void build(int u,int l,int r,int a[])
	{
		if(l == r){ mx[u] = make_pair(a[l], l); return;}
		int mid = (l+r)>>1;
		build(lson(u),a); build(rson(u),a);
		push_up(u);
	}
	pii query(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr) return mx[u];
		int mid = (l+r)>>1; pii res = make_pair(-inf, -inf);
		if(ql<=mid) res = max(res, query(lson(u),ql,qr));
		if(mid<qr) res = max(res, query(rson(u),ql,qr));
		return res;
	}
}tmn, tmx;

inline void get_pre(int a[],int lmx[],int lmn[],int n)
{
	stack<int> mx, mn;
	for(int i=1; i<=n; ++i)
	{
		while(mx.size() && a[mx.top()] <= a[i]) mx.pop();
		while(mn.size() && a[mn.top()] >= a[i]) mn.pop();
		lmx[i] = mx.size()? mx.top(): 0;
		lmn[i] = mn.size()? mn.top(): 0;
		mx.push(i); mn.push(i);
	}
}
inline void reverse(int f[],int n)
{
	reverse(f+1,f+n+1);
	for(int i=1; i<=n; ++i) f[i] = n - f[i] + 1;
}

int a[MAXN];

int f[MAXN], mxf[MAXN], mxg[MAXN];
pii g[MAXN];

int dsc[MAXN], dcnt = 0;

int main(void)
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i) dsc[++dcnt] = a[i];
	sort(dsc+1,dsc+dcnt+1); dcnt = unique(dsc+1,dsc+dcnt+1) - dsc - 1;
	for(int i=1; i<=n; ++i) a[i] = lower_bound(dsc+1,dsc+dcnt+1,a[i]) - dsc;
	
	tmx.build(1,1,n,a);
	for(int i=1; i<=n; ++i) a[i] = -a[i];
	tmn.build(1,1,n,a);
	for(int i=1; i<=n; ++i) a[i] = -a[i];
	
	static int lmx[MAXN], lmn[MAXN], rmx[MAXN], rmn[MAXN];
	
	get_pre(a, lmx, lmn, n);
	reverse(a+1,a+n+1);
	get_pre(a, rmx, rmn, n);
	reverse(a+1,a+n+1);
	reverse(rmx, n); reverse(rmn, n);
	
	for(int i=2; i<n; ++i)
	{
		g[rmx[i]] = max(g[rmx[i]], make_pair(lmx[i], i));
		g[rmn[i]] = max(g[rmn[i]], make_pair(lmn[i], i));
	}
	for(int i=1; i<=n; ++i)
		mxg[i] = g[mxg[i-1]] > g[i]? mxg[i-1]: i;
	
	set<int> pos;
	static vector<int> tag[MAXN];
	for(int i=1; i<=n; ++i)
		tag[max(rmx[i], rmn[i])].push_back(i);
	for(int i=1; i<=n; ++i)
	{
		for(int j=0; j<(int)tag[i].size(); ++j)
			pos.insert(tag[i][j]);
		
		int lef = min(lmn[i], lmx[i]);
		set<int>::iterator it = pos.upper_bound(lef);
		if(it != pos.begin())
			f[i] = *--it;
		mxf[i] = f[mxf[i-1]] > f[i]? mxf[i-1]: i;
	}
	
	for(int k=1; k<=Q; ++k)
	{	
		int l,r;
		scanf("%d%d",&l,&r);
		if(g[mxg[r]].first < l){ printf("0\n"); continue;}
		
		int y = mxf[r];
		if(f[y] >= l)
		{
			int x = f[y];
			int mid1 = tmx.query(1,1,n,x,y).second, mid2 = tmn.query(1,1,n,x,y).second;
			if(mid1 > mid2) swap(mid1, mid2);
			printf("4\n%d %d %d %d\n",x,mid1,mid2,y);
			continue;
		}
		
		int x = mxg[r];
		printf("3\n%d %d %d\n",g[x].first,g[x].second,x);
	}
	return 0;
}