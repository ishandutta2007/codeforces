#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;
const int inf = 0x3f3f3f3f;

struct Segment_Tree
{
	int n;
	int mn[MAXN<<2], tag[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u){ mn[u] = min(mn[ls(u)], mn[rs(u)]);}
	inline void push_down(int u)
	{
		if(tag[u])
		{
			mn[ls(u)] += tag[u]; tag[ls(u)] += tag[u];
			mn[rs(u)] += tag[u]; tag[rs(u)] += tag[u];
			tag[u] = 0;
		}
	}
	
	void build(int u,int l,int r,vector<int> &val)
	{
		tag[u]=0;
		if(l==r){ mn[u]=val[l]; return;}
		int mid = (l+r)>>1;
		build(lson(u),val); build(rson(u),val);
		push_up(u);
	}
	inline void build(vector<int> &val){ n = (int)val.size(); build(1,0,n-1,val);}
	
	void update(int u,int l,int r,int ql,int qr,int k)
	{
		if(ql<=l && r<=qr){ mn[u]+=k; tag[u]+=k; return;}
		push_down(u);
		int mid = (l+r)>>1;
		if(ql<=mid) update(lson(u),ql,qr,k);
		if(mid<qr) update(rson(u),ql,qr,k);
		push_up(u);
	}
	inline void update(int ql,int qr,int k){ update(1,0,n-1,ql,qr,k);}
	
	int query(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr) return mn[u];
		push_down(u);
		int mid = (l+r)>>1, res = inf;
		if(ql<=mid) res = min(res, query(lson(u),ql,qr));
		if(mid<qr) res = min(res, query(rson(u),ql,qr));
		return res;
	}
	inline int query(int ql,int qr){ return query(1,0,n-1,ql,qr);}
	
	#undef ls
	#undef rs
	#undef lson
	#undef rson
};

int n;
int a[MAXN];
vector<int> posz;

int nxt[MAXN];

void solve(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	posz.clear();
	for(int i=1; i<=n; ++i)
		if(!a[i]) posz.push_back(i);
	if((int)posz.size()<=1){ printf("0\n"); return;}
	
	static int lst[MAXN];
	for(int i=1; i<=n; ++i) lst[i] = n+1;
	for(int i=n; i>=1; --i) if(a[i])
	{
		nxt[i] = lst[a[i]];
		lst[a[i]] = i;
	}
	
	int m = (int)posz.size() / 2;
	
	vector<int> rs(m);
	for(int i=0; i<m; ++i)
		rs[i] = *(posz.end() - m + i);
	
	static int freq[MAXN];
	for(int i=1; i<=n; ++i) freq[i] = 0;
	int ccnt = 0;
	
	static int cnt_clr[MAXN];
	for(int i=posz[0]; i<=n; ++i)
	{
		if(a[i] && ++freq[a[i]] == 1) ++ccnt;
		cnt_clr[i] = ccnt;
	}
	
	vector<int> val(m);
	for(int i=0; i<m; ++i)
		val[i] = cnt_clr[rs[i]] - (i+1);
	
	static Segment_Tree tree;
	tree.build(val);
	
	int ans = m;
	
	int beg = 0;
	while(beg<m && tree.query(beg,m-1) < 0)
	{
		--ans;
		tree.update(beg,m-1, 1);
		++beg;
	}
	
	for(int i=beg+1, ii=1; i<m; ++i, ++ii)
	{
		for(int j=posz[ii-1]+1; j<posz[ii]; ++j) if(a[j])
		{
			int r = lower_bound(rs.begin(), rs.end(), nxt[j]) - rs.begin() - 1;
			if(r < i) continue;
			tree.update(i,r, -1);	
		}
		tree.update(i,m-1,1);
		
		while(i<m && tree.query(i,m-1) < 0)
		{
			--ans;
			tree.update(i,m-1, 1);
			++i;
		}
	}
	
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}