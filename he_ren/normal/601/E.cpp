#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1.5e4 + 5;
const int MAXQ = 3e4 + 5;
const int MAXD = 1e3 + 5;
const int base = 1e7 + 19;
const int mod = 1e9 + 7;

int d;
int V[MAXN], W[MAXN];

struct Bag
{
	int f[MAXD];
	Bag(void){ memset(f,0,sizeof(f));}
	inline void insert(int v,int w)
	{
		for(int i=d; i>=w; --i)
			f[i] = max(f[i], f[i-w] + v);
	}
	inline int get(void) const
	{
		ll cur = 1, res = 0;
		for(int i=1; i<=d; ++i)
			res = (res + cur * f[i]) %mod,
			cur = cur * base %mod;
		return res;
	}
};

int res[MAXQ];

namespace SegT
{
	vector<int> eve[MAXQ<<2];
	bool hasqry[MAXQ<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	void add_query(int u,int l,int r,int q)
	{
		hasqry[u] = 1;
		if(l == r) return;
		int mid = (l+r)>>1;
		q<=mid? add_query(lson(u), q): add_query(rson(u), q);
	}
	void add_eve(int u,int l,int r,int ql,int qr,int k)
	{
		if(ql<=l && r<=qr){ eve[u].push_back(k); return;}
		int mid = (l+r)>>1;
		if(ql<=mid) add_eve(lson(u),ql,qr,k);
		if(mid<qr) add_eve(rson(u),ql,qr,k);
	}
	void dfs(int u,int l,int r,Bag cur)
	{
		if(!hasqry[u]) return;
		for(auto id: eve[u]) cur.insert(V[id], W[id]);
		if(l == r){ res[l] = cur.get(); return;}
		int mid = (l+r)>>1;
		dfs(lson(u), cur);
		dfs(rson(u), cur);
	}
}

int main(void)
{
	int n;
	scanf("%d%d",&n,&d);
	static int lst[MAXN];
	for(int i=1; i<=n; ++i) scanf("%d%d",&V[i],&W[i]);
	
	for(int i=1; i<=n; ++i) lst[i] = 1;
	
	int Q;
	scanf("%d",&Q);
	for(int i=1; i<=Q; ++i)
	{
		int type;
		scanf("%d",&type);
		if(type == 1)
		{
			++n;
			scanf("%d%d",&V[n],&W[n]);
			lst[n] = i;
		}
		else if(type == 2)
		{
			int x;
			scanf("%d",&x);
			SegT::add_eve(1,1,Q, lst[x], i, x);
			lst[x] = -1;
		}
		else
		{
			SegT::add_query(1,1,Q, i);
		}
	}
	for(int i=1; i<=n; ++i)
		if(lst[i] != -1) SegT::add_eve(1,1,Q, lst[i], Q, i);
	
	memset(res,-1,sizeof(res));
	SegT::dfs(1,1,Q, Bag());
	
	for(int i=1; i<=Q; ++i)
		if(res[i] != -1) printf("%d\n",res[i]);
	return 0;
}